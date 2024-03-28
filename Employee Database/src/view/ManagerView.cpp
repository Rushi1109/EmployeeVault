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
	std::string userInput;

	while (true) {
		std::cout << "managerID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "managerID is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateEmployeeID(userInput, "*")) {
				manager.setManagerID(stoi(userInput));
				break;
			}
			else {
				std::cout << "\033[0;31m" << "Wrong input...Please enter positive integer number!!\n" << "\033[0m";
			}
		}
	}

	while (true) {
		std::cout << "teamSize* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "teamSize is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			try {
				if (std::stoi(userInput) >= 0) {
					manager.setTeamSize(std::stoi(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "\033[0;31m" << "Wrong input...Please enter positive integer number!!\n" << "\033[0m";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "yearsOfExperience* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "yearsOfExperience is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			try {
				if (std::stod(userInput) >= 0.0) {
					manager.setYearsOfExperience(std::stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "\033[0;31m" << "Wrong input...Please enter positive real number!!\n" << "\033[0m";
				continue;
			}
			break;
		}
	}

	{
		std::cout << "projectTitle : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			manager.setProjectTitle(userInput);
		}
	}

	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			manager.setRole(userInput);
		}
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
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Manager" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Please enter Manager ID.\n";

	while (true) {
		std::cout << "Manager ID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "Manager ID is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateManagerID(userInput)) {
				manager.setEmployeeID(stoi(userInput));
				manager.setManagerID(stoi(userInput));
				break;
			}
			else {
				std::cout << "\033[0;31m" << "Wrong input...Please enter positive integer number!!\n" << "\033[0m";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Manager" << "\033[0m" <<"-------------------------------------------------\n";
	ManagerController::selectManager("employeeID", userInput);

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
		while (true) {
			std::cout << "teamSize* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "teamSize is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (std::stoi(userInput) >= 0) {
						manager.setTeamSize(std::stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter positive integer number!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;

	case 14:
		while (true) {
			std::cout << "yearsOfExperience* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "yearsOfExperience is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (std::stod(userInput) >= 0.0) {
						manager.setYearsOfExperience(std::stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter positive real number!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;

	case 15:
	{
		std::cout << "projectTitle : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			manager.setProjectTitle(userInput);
		}
	}
	break;

	case 16:
	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			manager.setRole(userInput);
		}
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
		while (true) {
			std::cout << "departmentID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Department ID is mandatory...Please enter again!!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						manager.setDepartmentID(stoi(userInput));
					}
					else {
						throw "Negative number entered!";
					}
				}
				catch (std::exception& e) {
					std::cout << "\033[0;31m" << "Wrong Input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 15:
		while (true) {
			std::cout << "team size* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Team size is mandatory...Please enter again!!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						manager.setTeamSize(stoi(userInput));
					}
					else {
						throw "Negative number entered!";
					}
				}
				catch (std::exception& e) {
					std::cout << "\033[0;31m" << "Wrong Input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 16:
		while (true) {
			std::cout << "yearsOfExperience* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Years of Experience is mandatory...Please enter again!!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stod(userInput) > 0.0) {
						manager.setYearsOfExperience(stod(userInput));
					}
					else {
						throw "Negative number entered!";
					}
				}
				catch (std::exception& e) {
					std::cout << "\033[0;31m" << "Wrong Input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 17:
		while (true) {
			std::cout << "Project Title* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Project Title is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				manager.setProjectTitle(userInput);
				break;
			}
		}
		break;
	case 18:
		while (true) {
			std::cout << "Role* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Role is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				manager.setRole(userInput);
				break;
			}
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
				ManagerController::selectManager("middleName", manager.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(manager, 4);
				ManagerController::selectManager("lastName", manager.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(manager, 5);
				ManagerController::selectManager("dateOfBirth", manager.getDateOfBirth());
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
				ManagerController::selectManager("mentorID", std::to_string(manager.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(manager, 12);
				ManagerController::selectManager("performanceMetric", std::to_string(manager.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(manager, 13);
				ManagerController::selectManager("bonus", std::to_string(manager.getBonus()));
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
				ManagerController::selectManager("projectTitle", manager.getProjectTitle());
				break;
			}
			else if (userInput == 18) {
				getViewManagerInput(manager, 18);
				ManagerController::selectManager("role", manager.getRole());
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