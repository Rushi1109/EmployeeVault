#include <iostream>
#include "EmployeeView.h"
#include "ManagerView.h"
#include "ManagerController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::ManagerView, EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validator;

void ManagerView::printManagerFields() {
	std::cout << "1. managerID* (employeeID) : " << '\n';
	std::cout << "2. teamSize* : " << '\n';
	std::cout << "3. yearsOfExperience* : " << '\n';
	std::cout << "4. projectTitle : " << '\n';
	std::cout << "5. role : " << '\n';
}

void ManagerView::printViewManagerFields() {
	std::cout << "14. departmentID* : " << '\n';
	std::cout << "15. teamSize* : " << '\n';
	std::cout << "16. yearsOfExperience* : " << '\n';
	std::cout << "17. projectTitle* : " << '\n';
	std::cout << "18. role* : " << '\n';
}

void ManagerView::getInsertManagerInput(Manager& manager) {
	{
		auto managerID = Utility::getUserInputInt("managerId", Validator::validateEmployeeID, "*");
		manager.setManagerID(managerID.value());
	}

	{
		auto teamSize = Utility::getUserInputInt("teamSize");
		manager.setTeamSize(teamSize.value());
	}

	{
		auto yearsOfExperience = Utility::getUserInputInt("yearsOfExperience");
		manager.setYearsOfExperience(yearsOfExperience.value());
	}

	{
		auto projectTitle = Utility::getUserInputString("projectTitle", 0, false);
		manager.setProjectTitle(projectTitle.value());
	}

	{
		auto role = Utility::getUserInputString("role", 0, false);
		manager.setRole(role.value());
	}
};

bool ManagerView::insertManager() {
	Manager manager;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert Manager" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(manager);
	ManagerController::insertManager(manager);

	return Utility::repeatOperation("insert", "Manager");
}

bool ManagerView::getManagerIDInput(Manager& manager, const std::string& operation) {
	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Manager" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Please enter Manager ID.\n";

	{
		auto managerID = Utility::getUserInputInt("managerID", Validator::validateManagerID);
		manager.setManagerID(managerID.value());
	}

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Manager" << "\033[0m" <<"-------------------------------------------------\n";
	ManagerController::selectManager("employeeID", std::to_string(manager.getManagerID()));

	return Utility::proceedFurther(operation);
}

bool ManagerView::deleteManager() {
	Manager manager;

	if (!getManagerIDInput(manager, "Delete")) {
		return false;
	}

	ManagerController::deleteManagerByID(manager.getEmployeeID());

	return Utility::repeatOperation("delete", "Manager");
}

void ManagerView::printUpdateManagerFields() {
	std::cout << "13. teamSize* : " << '\n';
	std::cout << "14. yearsOfExperience* : " << '\n';
	std::cout << "15. projectTitle : " << '\n';
	std::cout << "16. role : " << '\n';
}

void ManagerView::getUpdateManagerInput(Manager& manager, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
		case 13:
		{
			auto teamSize = Utility::getUserInputInt("teamSize");
			manager.setTeamSize(teamSize.value());
		}
		break;

		case 14:
		{
			auto yearsOfExperience = Utility::getUserInputInt("yearsOfExperience");
			manager.setYearsOfExperience(yearsOfExperience.value());
		}
		break;

		case 15:
		{
			auto projectTitle = Utility::getUserInputString("projectTitle", 0, false);
			manager.setProjectTitle(projectTitle.value());
		}
		break;

		case 16:
		{
			auto role = Utility::getUserInputString("role", 0, false);
			manager.setRole(role.value());
		}
		break;
	}
}

bool ManagerView::updateManager() {
	Manager manager{ true };

	if (!getManagerIDInput(manager, "Update")) {
		return false;
	}

	auto isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "Update Manager" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		printUpdateManagerFields();
		std::cout << "17. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the field you want to update, or select 0/17 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-17]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput >= 1 && userInput <= 12) {
				EmployeeView::getUpdateEmployeeInput(manager, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput >= 13 && userInput <= 16) {
				getUpdateManagerInput(manager, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 17) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	ManagerController::updateManager(manager);

	return Utility::repeatOperation("update", "Manager");
}

void ManagerView::getViewManagerInput(Manager& manager, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
		case 14:
		{
			auto departmentID = Utility::getUserInputInt("departmentID");
			manager.setDepartmentID(departmentID.value());
		}
		break;

		case 15:
		{
			auto teamSize = Utility::getUserInputInt("teamSize");
			manager.setTeamSize(teamSize.value());
		}
		break;

		case 16:
		{
			auto yearsOfExperience = Utility::getUserInputInt("yearsOfExperience");
			manager.setYearsOfExperience(yearsOfExperience.value());
		}
		break;

		case 17:
		{
			auto projectTitle = Utility::getUserInputString("projectTitle");
			manager.setProjectTitle(projectTitle.value());
		}
		break;

		case 18:
		{
			auto role = Utility::getUserInputString("role");
			manager.setRole(role.value());
		}
		break;
	}
}

bool ManagerView::viewManagerConditional() {
	Manager manager;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Manager" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewManagerFields();
		std::cout << "19. Go back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view a Manager, or select 0/19 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-19]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);

			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				EmployeeView::getViewEmployeeInput(manager, 1);
				ManagerController::selectManager("employeeID", std::to_string(manager.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(manager, 2);
				ManagerController::selectManager("firstName", manager.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(manager, 3);
				ManagerController::selectManager("middleName", manager.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(manager, 4);
				ManagerController::selectManager("lastName", manager.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(manager, 5);
				ManagerController::selectManager("dateOfBirth", manager.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(manager, 6);
				ManagerController::selectManager("mobileNo", std::to_string(manager.getMobileNo()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(manager, 7);
				ManagerController::selectManager("email", manager.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(manager, 8);
				ManagerController::selectManager("address", manager.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(manager, 9);
				ManagerController::selectManager("gender", EmployeeDB::Model::getGenderString(manager.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(manager, 10);
				ManagerController::selectManager("dateOfJoining", manager.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(manager, 11);
				ManagerController::selectManager("mentorID", std::to_string(manager.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(manager, 12);
				ManagerController::selectManager("performanceMetric", std::to_string(manager.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(manager, 13);
				ManagerController::selectManager("bonus", std::to_string(manager.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				getViewManagerInput(manager, 14);
				ManagerController::selectManager("departmentID", std::to_string(manager.getDepartmentID()));
				break;
			}
			else if (userInput == 15) {
				getViewManagerInput(manager, 15);
				ManagerController::selectManager("teamSize", std::to_string(manager.getTeamSize()));
				break;
			}
			else if (userInput == 16) {
				getViewManagerInput(manager, 16);
				ManagerController::selectManager("yearsOfExp", std::to_string(manager.getYearsOfExperience()));
				break;
			}
			else if (userInput == 17) {
				getViewManagerInput(manager, 17);
				ManagerController::selectManager("projectTitle", manager.getProjectTitle().value());
				break;
			}
			else if (userInput == 18) {
				getViewManagerInput(manager, 18);
				ManagerController::selectManager("role", manager.getRole().value());
				break;
			}
			else if (userInput == 19) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
	return true;
}

bool ManagerView::viewManager() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Manager" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Manager based on a field" << '\n';
		std::cout << "2. View all Manager" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the operation [0-3]: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-3]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				if (!viewManagerConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				ManagerController::selectManager();
				break;
			}
			else if (userInput == 3) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	return Utility::repeatOperation("view", "Manager");
}