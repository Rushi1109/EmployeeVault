#include <iostream>
#include "EmployeeView.h"
#include "QAView.h"
#include "QAController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::QAView;
using EmployeeDB::Controller::QAController;

bool QAView::insertQA() {
	QA obj;

	system("cls");
	std::cout << "-------------------------------------------Insert QA---------------------------------------------------\n";

	EmployeeView::printEmployeeFields();
	std::cout << "13. Testing Tool* : " << '\n';

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
		std::cout << "Testing Tool* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Testing Tool is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setTestingTool(userInput);
			break;
		}
	}

	QAController::insertQA(obj);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to insert another QA? [y/n] : ";
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