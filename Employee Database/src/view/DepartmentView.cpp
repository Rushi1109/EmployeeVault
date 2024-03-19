#include <iostream>
#include "DepartmentView.h"
#include "DepartmentController.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::Controller::DepartmentController;

bool DepartmentView::deleteDepartment() {
	std::cout << "Please enter ID of department to delete : \n";

	bool isInvalidInput{ false };
	int departmentID;

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		std::cin >> departmentID;
		if (!std::cin.fail()) {
			if (departmentID > 0) {
				break;
			}
			else {
				isInvalidInput = true;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			isInvalidInput = true;
		}
	}

	DepartmentController::deleteDepartment(departmentID);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to delete another Department? [y/n] : ";
		}
		unsigned char userChoice;
		std::cin >> userChoice;

		if (userChoice == 'y' || userChoice == 'Y') {
			return true;
		}
		else if (userChoice == 'n' || userChoice == 'N') {
			return false;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Wrong Input, Please enter character [y/n] : ";
			isInvalidInput = true;
		}
	}

	return false;
}