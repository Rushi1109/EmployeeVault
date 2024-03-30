#include <iostream>
#include "EmployeeView.h"
#include "EngineerView.h"
#include "EngineerController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::EngineerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EngineerController;
using EmployeeDB::Validator;

bool EngineerView::insertEngineer() {
	Engineer engineer;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert Engineer" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(engineer);

	{
		auto technology = Utility::getUserInputString("technology");
		engineer.setTechnology(technology.value());
	}

	EngineerController::insertEngineer(engineer);

	return Utility::repeatOperation("insert", "Engineer");
}

bool EngineerView::deleteEngineer() {
	Engineer engineer;

	EmployeeView::getEmployeeIDInput(engineer, "Delete", "Engineer");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Delete Engineer" << "\033[0m" << "-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(engineer.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	EngineerController::deleteEngineerByID(engineer.getEmployeeID());

	return Utility::repeatOperation("delete", "Engineer");
}

bool EngineerView::updateEngineer() {
	Engineer engineer{ true };

	EmployeeView::getEmployeeIDInput(engineer, "Update", "Engineer");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Update Engineer" << "\033[0m" << "-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(engineer.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	auto isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Engineer-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. technology* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the field you want to update, or select 0/14 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-14]\n" << "\033[0m";
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
				EmployeeView::getUpdateEmployeeInput(engineer, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 13) {
				{
					auto technology = Utility::getUserInputString("technology");
					engineer.setTechnology(technology.value());
				}
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 14) {
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

	EngineerController::updateEngineer(engineer);

	return Utility::repeatOperation("update", "Engineer");
}

bool EngineerView::viewEngineer() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Engineer" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Engineer based on a field" << '\n';
		std::cout << "2. View all Engineer" << '\n';
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
				if (!viewEngineerConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				EngineerController::selectEngineer();
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

	return Utility::repeatOperation("view", "Engineer");
}

void EngineerView::printViewEngineerFields() {
	std::cout << "14. technology* : " << '\n';
}

void EngineerView::getViewEngineerInput(Engineer& engineer, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
		case 14:
		{
			auto technology = Utility::getUserInputString("technology");
			engineer.setTechnology(technology.value());
		}
		break;
	}
}

bool EngineerView::viewEngineerConditional() {
	Engineer engineer;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Engineer" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewEngineerFields();
		std::cout << "15. Go back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view a engineer, or select 0/15 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-15]\n" << "\033[0m";
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
				EmployeeView::getViewEmployeeInput(engineer, 1);
				EngineerController::selectEngineer("employeeID", std::to_string(engineer.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(engineer, 2);
				EngineerController::selectEngineer("firstName", engineer.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(engineer, 3);
				EngineerController::selectEngineer("middleName", engineer.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(engineer, 4);
				EngineerController::selectEngineer("lastName", engineer.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(engineer, 5);
				EngineerController::selectEngineer("dateOfBirth", engineer.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(engineer, 6);
				EngineerController::selectEngineer("mobileNo", std::to_string(engineer.getMobileNo()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(engineer, 7);
				EngineerController::selectEngineer("email", engineer.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(engineer, 8);
				EngineerController::selectEngineer("address", engineer.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(engineer, 9);
				EngineerController::selectEngineer("gender", EmployeeDB::Model::getGenderString(engineer.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(engineer, 10);
				EngineerController::selectEngineer("dateOfJoining", engineer.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(engineer, 11);
				EngineerController::selectEngineer("mentorID", std::to_string(engineer.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(engineer, 12);
				EngineerController::selectEngineer("performanceMetric", std::to_string(engineer.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(engineer, 13);
				EngineerController::selectEngineer("bonus", std::to_string(engineer.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				getViewEngineerInput(engineer, 14);
				EngineerController::selectEngineer("technology", engineer.getTechnology());
				break;
			}
			else if (userInput == 15) {
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