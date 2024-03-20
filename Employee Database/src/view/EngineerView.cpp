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

bool EngineerView::getEngineerIDInput(Engineer& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " Engineer-------------------------------------------------\n";
	std::cout << "Please enter Engineer ID.\n";

	while (true) {
		std::cout << "Engineer ID* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Engineer ID is mandatory...Please enter again!!" << '\n';
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
	std::cout << "------------------------------------------" + operation + " Engineer-------------------------------------------------\n";
	EngineerController::selectEngineer("employeeID", userInput);

	return Utility::proceedFurther(operation);
}

bool EngineerView::deleteEngineer() {
	Engineer obj;

	if (!getEngineerIDInput(obj, "Delete")) {
		return false;
	}

	EngineerController::deleteEngineerByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Engineer");
}