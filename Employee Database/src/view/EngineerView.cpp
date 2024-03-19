#include <iostream>
#include "EmployeeView.h"
#include "EngineerView.h"
#include "EngineerController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::EngineerView;
using EmployeeDB::Controller::EngineerController;

bool EngineerView::insertEngineer() {
	Engineer obj;

	system("cls");
	std::cout << "------------------------------------------Insert Engineer-------------------------------------------------\n";

	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	bool isInvalidInput{ false };

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to proceed with insertion? [y/n] : ";
		}
		unsigned char userChoice;
		std::cin >> userChoice;

		if (userChoice == 'y' || userChoice == 'Y') {
			break;
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

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "technology* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Technology is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setTechnology(userInput);
			break;
		}
	}

	EngineerController::insertEngineer(obj);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to insert another Engineer? [y/n] : ";
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