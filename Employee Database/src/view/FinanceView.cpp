#include <iostream>
#include "EmployeeView.h"
#include "FinanceView.h"
#include "FinanceController.h"'
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::FinanceView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::FinanceController;

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