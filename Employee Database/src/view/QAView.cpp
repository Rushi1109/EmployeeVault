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

bool QAView::getQAIDInput(QA& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " QA-------------------------------------------------\n";
	std::cout << "Please enter QA ID.\n";

	while (true) {
		std::cout << "QA ID* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "QA ID is mandatory...Please enter again!!" << '\n';
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
	std::cout << "------------------------------------------" + operation + " QA-------------------------------------------------\n";
	QAController::selectQA("employeeID", userInput);

	return Utility::proceedFurther(operation);
}

bool QAView::deleteQA() {
	QA obj;

	if (!getQAIDInput(obj, "Delete")) {
		return false;
	}

	QAController::deleteQAByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "QA");
}