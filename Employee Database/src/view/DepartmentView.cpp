#include <iostream>
#include "DepartmentView.h"
#include "DepartmentController.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::Controller::DepartmentController;

bool DepartmentView::deleteDepartment() {
	std::cout << "Please enter ID of department to delete : \n";

	bool isInvalidInput{ false };

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		int departmentID;
		std::cin >> departmentID;
		if (!std::cin.fail()) {
			if (departmentID > 0) {
				DepartmentController::deleteDepartment(departmentID);
				return true;
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
}