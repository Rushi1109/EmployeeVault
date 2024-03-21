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

void ManagerView::getInsertManagerInput(Manager& obj) {
	std::string userInput;

	while (true) {
		std::cout << "managerID* : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateEmployeeID(userInput, "*")) {
				obj.setManagerID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	while (true) {
		std::cout << "teamSize* : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (std::stoi(userInput) >= 0) {
					obj.setTeamSize(std::stoi(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "yearsOfExperience* : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (std::stod(userInput) >= 0.0) {
					obj.setYearsOfExperience(std::stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter positive real number!!\n";
				continue;
			}
			break;
		}
	}

	{
		std::cout << "projectTitle : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() != 0) {
			obj.setProjectTitle(userInput);
		}
	}

	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() != 0) {
			obj.setRole(userInput);
		}
	}
};

bool ManagerView::insertManager() {
	Manager obj;

	system("cls");
	std::cout << "------------------------------------------Insert Manager-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(obj);
	ManagerController::insertManager(obj);

	return Utility::repeatOperation("insert", "Manager");
}

bool ManagerView::getManagerIDInput(Manager& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " Manager-------------------------------------------------\n";
	std::cout << "Please enter Manager ID.\n";

	while (true) {
		std::cout << "Manager ID* : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "Manager ID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateManagerID(userInput)) {
				obj.setEmployeeID(stoi(userInput));
				obj.setManagerID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------" + operation + " Manager-------------------------------------------------\n";
	ManagerController::selectManager("employeeID", userInput);

	return Utility::proceedFurther(operation);
}

bool ManagerView::deleteManager() {
	Manager obj;

	if (!getManagerIDInput(obj, "Delete")) {
		return false;
	}

	ManagerController::deleteManagerByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Manager");
}

void ManagerView::printUpdateManagerFields() {
	std::cout << "13. teamSize* : " << '\n';
	std::cout << "14. yearsOfExperience* : " << '\n';
	std::cout << "15. projectTitle : " << '\n';
	std::cout << "16. role : " << '\n';
}

void ManagerView::getUpdateManagerInput(Manager& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 13:
		while (true) {
			std::cout << "teamSize* : ";
			std::getline(std::cin, userInput);
			Utility::removeWhiteSpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (std::stoi(userInput) >= 0) {
						obj.setTeamSize(std::stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "Wrong input...Please enter positive integer number!!\n";
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
			Utility::removeWhiteSpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (std::stod(userInput) >= 0.0) {
						obj.setYearsOfExperience(std::stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "Wrong input...Please enter positive real number!!\n";
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
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() != 0) {
			obj.setProjectTitle(userInput);
		}
	}
	break;

	case 16:
	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() != 0) {
			obj.setRole(userInput);
		}
	}
	break;
	}
}

bool ManagerView::updateManager() {
	Manager obj{ true };

	if (!getManagerIDInput(obj, "Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Manager-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		printUpdateManagerFields();
		std::cout << "17. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/17 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-17]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
				EmployeeView::getUpdateEmployeeInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput >= 13 && userInput <= 16) {
				getUpdateManagerInput(obj, userInput);
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

	ManagerController::updateManager(obj);

	return Utility::repeatOperation("update", "Manager");
}