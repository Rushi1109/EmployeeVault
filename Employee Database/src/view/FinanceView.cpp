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

bool FinanceView::getFinanceIDInput(Finance& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " Finance-------------------------------------------------\n";
	std::cout << "Please enter Financier ID.\n";

	while (true) {
		std::cout << "Financier ID* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Financier ID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateEmployeeID(userInput)) {
				obj.setEmployeeID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------" + operation + " Finance-------------------------------------------------\n";
	FinanceController::selectFinance("employeeID", userInput);

	return Utility::proceedFurther(operation);
}

bool FinanceView::deleteFinance() {
	Finance obj;

	if (!getFinanceIDInput(obj, "Delete")) {
		return false;
	}

	FinanceController::deleteFinanceByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Finance");
}