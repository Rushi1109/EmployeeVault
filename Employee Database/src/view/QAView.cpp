#include <iostream>
#include "EmployeeView.h"
#include "QAView.h"
#include "QAController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::QAView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::QAController;
using EmployeeDB::Validator;

bool QAView::insertQA() {
	QA obj;

	system("cls");
	std::cout << "------------------------------------------Insert QA-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. testingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "testingTool* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setTestingTool(userInput);
			break;
		}
	}

	QAController::insertQA(obj);

	return Utility::repeatOperation("insert", "QA");
}

bool QAView::deleteQA() {
	QA obj;

	EmployeeView::getEmployeeIDInput(obj, "Delete", "QA");

	system("cls");
	std::cout << "-------------------------------------------Delete QA-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(obj.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	QAController::deleteQAByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "QA");
}

bool QAView::updateQA() {
	QA obj{ true };

	EmployeeView::getEmployeeIDInput(obj, "Update", "QA");

	system("cls");
	std::cout << "------------------------------------------Update QA-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update QA-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. testingTool* : " << '\n';
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
					std::cout << "testingTool* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTestingTool(inputLine);
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

	QAController::updateQA(obj);

	return Utility::repeatOperation("update", "QA");
}