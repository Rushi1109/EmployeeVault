#include <iostream>
#include "EmployeeView.h"
#include "HRView.h"
#include "HRController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView;
using EmployeeDB::Controller::HRController;

bool HRView::insertHR() {
	HR obj;

	system("cls");
	std::cout << "-------------------------------------------Insert HR---------------------------------------------------\n";

	EmployeeView::printEmployeeFields();
	std::cout << "13. HR Specialization* : " << '\n';

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
		std::cout << "HR Specialization* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "HR Specialization is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setHRSpecialization(userInput);
			break;
		}
	}

	HRController::insertHR(obj);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to insert another HR? [y/n] : ";
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