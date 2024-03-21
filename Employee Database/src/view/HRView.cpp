#include <iostream>
#include "EmployeeView.h"
#include "HRView.h"
#include "HRController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::HRController;
using EmployeeDB::Validator;

bool HRView::insertHR() {
	HR obj;

	system("cls");
	std::cout << "------------------------------------------Insert HR-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. hrSpecialization* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "hrSpecialization* : ";
		std::getline(std::cin, userInput);
		Utility::removeWhiteSpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setHRSpecialization(userInput);
			break;
		}
	}

	HRController::insertHR(obj);

	return Utility::repeatOperation("insert", "HR");
}

bool HRView::deleteHR() {
	HR obj;

	EmployeeView::getEmployeeIDInput(obj, "Delete", "HR");

	system("cls");
	std::cout << "-------------------------------------------Delete HR-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	HRController::deleteHRByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "HR");
}

bool HRView::updateHR() {
	HR obj{ true };

	EmployeeView::getEmployeeIDInput(obj, "Update", "HR");

	system("cls");
	std::cout << "------------------------------------------Update HR-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update HR-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. hrSpecialization* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/14 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-14]\n";
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
			else if (userInput == 13) {
				while (true) {
					std::cout << "hrSpecialization* : ";
					std::getline(std::cin, inputLine);
					Utility::removeWhiteSpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setHRSpecialization(inputLine);
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

	HRController::updateHR(obj);

	return Utility::repeatOperation("update", "HR");
}