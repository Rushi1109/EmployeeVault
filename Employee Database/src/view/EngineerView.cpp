#include <iostream>
#include "EmployeeView.h"
#include "EngineerView.h"
#include "EngineerController.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::EngineerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EngineerController;

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