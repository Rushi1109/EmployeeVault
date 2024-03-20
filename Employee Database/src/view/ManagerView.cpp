#include <iostream>
#include "ManagerView.h"
#include "ManagerController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::ManagerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validator;

void ManagerView::printManagerFields() {
	std::cout << "Fields with * are required fields\n";
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
		if (userInput.size() == 0) {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateEmployeeID(userInput)) {
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
		if (userInput.size() != 0) {
			obj.setProjectTitle(userInput);
		}
	}

	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		if (userInput.size() != 0) {
			obj.setRole(userInput);
		}
	}
};

bool ManagerView::insertManager() {
	Manager obj;

	system("cls");
	std::cout << "------------------------------------------Insert Manager-------------------------------------------------\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(obj);
	ManagerController::insertManager(obj);

	return Utility::repeatOperation("insert", "Manager");
}

bool ManagerView::deleteManager() {
	if (!Utility::proceedFurther("deletion")) {
		return false;
	}

	std::string userInput;
	std::cout << "Please enter ID of manager to delete : \n";
	while (true) {
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (std::stoi(userInput) > 0) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	ManagerController::deleteManager(std::stoi(userInput));

	return Utility::repeatOperation("delete", "Manager");
}