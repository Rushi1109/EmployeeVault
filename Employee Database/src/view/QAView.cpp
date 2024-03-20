#include <iostream>
#include "EmployeeView.h"
#include "QAView.h"
#include "QAController.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::QAView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::QAController;

bool QAView::insertQA() {
	QA obj;

	system("cls");
	std::cout << "------------------------------------------Insert QA-------------------------------------------------\n";
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