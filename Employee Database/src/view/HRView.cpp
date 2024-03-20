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

bool HRView::getHRIDInput(HR& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " HR-------------------------------------------------\n";
	std::cout << "Please enter HR ID.\n";

	while (true) {
		std::cout << "HR ID* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "HR ID is mandatory...Please enter again!!" << '\n';
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
	std::cout << "------------------------------------------" + operation + " HR-------------------------------------------------\n";
	HRController::selectHR("employeeID", userInput);

	return Utility::proceedFurther(operation);
}

bool HRView::deleteHR() {
	HR obj;

	if (!getHRIDInput(obj, "Delete")) {
		return false;
	}

	HRController::deleteHRByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "HR");
}