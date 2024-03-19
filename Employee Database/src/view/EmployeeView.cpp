#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Validator;

void EmployeeView::printEmployeeFields() {
	std::cout << "Fields with * are required fields\n";
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining*:" << '\n';
	std::cout << "10. managerID*:" << '\n';
	std::cout << "11. performanceMetric*:" << '\n';
	std::cout << "12. bonus*:" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& obj) {
	std::string userInput;
	std::cin.ignore();

	while (true) {
		std::cout << "firstName*: ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "First Name is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			obj.setFirstName(userInput);
			break;
		}
	}

	{
		std::cout << "middleName : ";
		char userChoice = std::cin.get();

		if (userChoice != '\n') {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setMiddleName(userInput);
		}
	}

	while (true) {
		std::cout << "lastName* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Last Name is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			obj.setLastName(userInput);
			break;
		}
	}

	{
		while (true) {
			std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			char userChoice = std::cin.get();

			if (userChoice == '\n') {
				break;
			}
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			if (Validator::validateDate(userInput)) {
				obj.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy]\n";
			}
		}
	}

	while (true) {
		std::cout << "mobileNo* (Starting from [6-9]) : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "mobileNo is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			if (Validator::validateMobile(userInput)) {
				obj.setMobileNo(std::stoll(userInput));
				break;
			}
			else {
				std::cerr << "Wrong mobileNo...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "email* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "email is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			if (Validator::validateEmail(userInput)) {
				obj.setEmail(userInput);
				break;
			}
			else {
				std::cerr << "Wrong email...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "address* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Address is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setAddress(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "gender* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Gender is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			if (Validator::validateGender(userInput)) {
				obj.setGender(EmployeeDB::Model::getGenderFromString(userInput));
				break;
			}
			else {
				std::cerr << "Wrong input...Please enter again!!\n";
			}
		}
	}

	while (true) {
		std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		char userChoice = std::cin.get();

		if (userChoice == '\n') {
			std::cout << "dateOfJoining is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			if (Validator::validateDate(userInput)) {
				obj.setDateOfJoining(userInput);
				break;
			}
			else {
				std::cerr << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			}
		}
	}

	while (true) {
		std::cout << "mentorID* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "mentorID is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				obj.setMentorID(std::stoi(userInput));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter again!!\n";
				continue;
			}
			break;
		}
	}

	{
		while (true) {
			std::cout << "performanceMetric : ";
			char userChoice = std::cin.get();

			if (userChoice == '\n') {
				break;
			}
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				obj.setPerformanceMetric(std::stod(userInput));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter real number!!\n";
				continue;
			}
			break;
		}
	}

	{
		while (true) {
			std::cout << "bonus : ";
			char userChoice = std::cin.get();

			if (userChoice == '\n') {
				break;
			}
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				obj.setBonus(std::stod(userInput));
			}
			catch (...) {
				std::cout << "Wrong input...Please enter real number!!\n";
				continue;
			}
			break;
		}
	}
};

bool EmployeeView::deleteEmployee() {
	std::cout << "Please enter ID of employee to delete : \n";

	bool isInvalidInput{ false };
	int employeeID;

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		std::cin >> employeeID;
		if (!std::cin.fail()) {
			if (employeeID > 0) {
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

	EmployeeController::deleteEmployee(employeeID);

	isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to delete another Employee? [y/n] : ";
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