#include <iostream>
#include "ManagerView.h"
#include "ManagerController.h"

using EmployeeDB::View::ManagerView, EmployeeDB::Controller::ManagerController;

bool ManagerView::deleteManager() {
	std::cout << "Please enter ID of manager to delete : \n";

	bool isInvalidInput{ false };

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		int managerID;
		std::cin >> managerID;
		if (!std::cin.fail()) {
			if (managerID > 0) {
				ManagerController::deleteManager(managerID);
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