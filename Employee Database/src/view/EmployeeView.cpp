#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validator.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
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
	std::cout << "9. dateOfJoining* :" << '\n';
	std::cout << "10. mentorID* :" << '\n';
	std::cout << "11. performanceMetric :" << '\n';
	std::cout << "12. bonus :" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& obj) {
	std::string userInput;

	while (true) {
		std::cout << "firstName* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "First Name is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setFirstName(userInput);
			break;
		}
	}

	{
		std::cout << "middleName : ";
		std::getline(std::cin, userInput);
		if (userInput.size() != 0) {
			obj.setMiddleName(userInput);
		}
	}

	while (true) {
		std::cout << "lastName* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Last Name is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setLastName(userInput);
			break;
		}
	}

	{
		std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		while (true) {
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			if (Validator::validateDate(userInput)) {
				obj.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			}
		}
	}

	while (true) {
		std::cout << "mobileNo* (Starting from [6-9]) : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "mobileNo is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "email is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Address is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setAddress(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "gender* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Gender is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);

		if (userInput.size() == 0) {
			std::cout << "dateOfJoining is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "mentorID is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stoi(userInput) > 0) {
					obj.setMentorID(stoi(userInput));
				}
				else {
					throw "Negative Number";
				}
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
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setPerformanceMetric(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
			}
		}
	}

	{
		while (true) {
			std::cout << "bonus : ";
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBonus(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
			}
		}
	}
}

void EmployeeView::getUpdateEmployeeInput(Employee& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "firstName* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "First Name is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setFirstName(userInput);
				break;
			}
		}
		break;
	case 2:
	{
		std::cout << "middleName : ";
		std::getline(std::cin, userInput);
		if (userInput.size() != 0) {
			obj.setMiddleName(userInput);
		}
	}
	break;
	case 3:
		while (true) {
			std::cout << "lastName* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "Last Name is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setLastName(userInput);
				break;
			}
		}
		break;
	case 4:
	{
		std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		while (true) {
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			if (Validator::validateDate(userInput)) {
				obj.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			}
		}
	}
	break;
	case 5:
		while (true) {
			std::cout << "mobileNo* (Starting from [6-9]) : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "mobileNo is mandatory...Please enter again!!" << '\n';
			}
			else {
				if (Validator::validateMobile(userInput)) {
					obj.setMobileNo(std::stoll(userInput));
					break;
				}
				else {
					std::cerr << "Wrong mobileNo...Please enter again!!\n";
				}
			}
		}
		break;
	case 6:
		while (true) {
			std::cout << "email* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "email is mandatory...Please enter again!!" << '\n';
			}
			else {
				if (Validator::validateEmail(userInput)) {
					obj.setEmail(userInput);
					break;
				}
				else {
					std::cerr << "Wrong email...Please enter again!!\n";
				}
			}
		}
		break;
	case 7:
		while (true) {
			std::cout << "address* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "Address is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setAddress(userInput);
				break;
			}
		}
		break;
	case 8:
		while (true) {
			std::cout << "gender* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "Gender is mandatory...Please enter again!!" << '\n';
			}
			else {
				if (Validator::validateGender(userInput)) {
					obj.setGender(EmployeeDB::Model::getGenderFromString(userInput));
					break;
				}
				else {
					std::cerr << "Wrong input...Please enter again!!\n";
				}
			}
		}
		break;
	case 9:
		while (true) {
			std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				std::cout << "dateOfJoining is mandatory...Please enter again!!" << '\n';
			}
			else {
				if (Validator::validateDate(userInput)) {
					obj.setDateOfJoining(userInput);
					break;
				}
				else {
					std::cerr << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
				}
			}
		}
		break;
	case 10:
		while (true) {
			std::cout << "mentorID* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "mentorID is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						obj.setMentorID(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "Wrong input...Please enter again!!\n";
					continue;
				}
				break;
			}
		}
		break;
	case 11:
	{
		while (true) {
			std::cout << "performanceMetric : ";
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setPerformanceMetric(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
			}
		}
	}
	break;
	case 12:
	{
		while (true) {
			std::cout << "bonus : ";
			std::getline(std::cin, userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBonus(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
			}
		}
	}
	break;
	}
}