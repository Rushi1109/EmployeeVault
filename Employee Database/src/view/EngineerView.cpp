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
	Engineer obj;

	system("cls");
	std::cout << "------------------------------------------Insert Engineer-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "technology* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Technology is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setTechnology(userInput);
			break;
		}
	}

	EngineerController::insertEngineer(obj);

	return Utility::repeatOperation("insert", "Engineer");
}

bool EngineerView::deleteEngineer() {
	Engineer obj;

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Engineer");

	system("cls");
	std::cout << "------------------------------------------Delete Engineer-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	EngineerController::deleteEngineerByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Engineer");
}

bool EngineerView::updateEngineer() {
	Engineer obj{ true };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Engineer");

	system("cls");
	std::cout << "------------------------------------------Update Engineer-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Engineer-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. technology* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/14 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-14]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);

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
			else if (userInput == 13) {
				while (true) {
					std::cout << "technology* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "Technology is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTechnology(inputLine);
						break;
					}
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

	EngineerController::updateEngineer(obj);

	return Utility::repeatOperation("update", "Engineer");
}