#include <iostream>
#include "EmployeeView.h"
#include "FinanceView.h"
#include "FinanceController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::FinanceView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Validator;

bool FinanceView::insertFinance() {
	Finance obj;

	system("cls");
	std::cout << "------------------------------------------Insert Finance-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. accountingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "accountingTool* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "accountingTool is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setAccountingTool(userInput);
			break;
		}
	}

	FinanceController::insertFinance(obj);

	return Utility::repeatOperation("insert", "Finance");
}

bool FinanceView::deleteFinance() {
	Finance obj;

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Finance");

	system("cls");
	std::cout << "-------------------------------------------Delete Finance-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	FinanceController::deleteFinanceByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Finance");
}

bool FinanceView::updateFinance() {
	Finance obj{ true };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Finance");

	system("cls");
	std::cout << "------------------------------------------Update Finance-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Finance-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. accountingTool* : " << '\n';
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
					std::cout << "accountingTool* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "accountingTool is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setAccountingTool(inputLine);
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

	FinanceController::updateFinance(obj);

	return Utility::repeatOperation("update", "Finance");
}