#include <iostream>
#include "ManagerView.h"
#include "ManagerController.h"

using EmployeeDB::View::ManagerView, EmployeeDB::Controller::ManagerController;

bool ManagerView::deleteManager() {
	std::cout << "Please enter ID of manager to delete : \n";

	bool isInvalidInput{ false };
	int managerID;

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		std::cin >> managerID;
		if (!std::cin.fail()) {
			if (managerID > 0) {
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

	ManagerController::deleteManager(managerID);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to delete another Manager? [y/n] : ";
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