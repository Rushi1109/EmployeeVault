#include <iostream>
#include "EmployeeView.h"
#include "HRView.h"
#include "HRController.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::HRController;

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