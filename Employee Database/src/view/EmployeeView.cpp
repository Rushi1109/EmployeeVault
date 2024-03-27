#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validator.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Validator;

void EmployeeView::printEmployeeFields() {
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining* :" << '\n';
	std::cout << "10. mentorID :" << '\n';
	std::cout << "11. performanceMetric :" << '\n';
	std::cout << "12. bonus :" << '\n';
}

void EmployeeView::printViewEmployeeFields() {
	std::cout << "1. employeeID* : " << '\n';
	std::cout << "2. firstName* : " << '\n';
	std::cout << "3. middleName* : " << '\n';
	std::cout << "4. lastName* : " << '\n';
	std::cout << "5. dateOfBirth* : " << '\n';
	std::cout << "6. mobileNo* : " << '\n';
	std::cout << "7. email* :" << '\n';
	std::cout << "8. address* :" << '\n';
	std::cout << "9. gender* :" << '\n';
	std::cout << "10. dateOfJoining* :" << '\n';
	std::cout << "11. mentorID* :" << '\n';
	std::cout << "12. performanceMetric* :" << '\n';
	std::cout << "13. bonus* :" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& employee) {
	std::string userInput;

	while (true) {
		std::cout << "firstName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "First Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			employee.setFirstName(userInput);
			break;
		}
	}

	{
		std::cout << "middleName : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			employee.setMiddleName(userInput);
		}
	}

	while (true) {
		std::cout << "lastName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "Last Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			employee.setLastName(userInput);
			break;
		}
	}

	{
		std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : \n";
		while (true) {
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			if (Validator::validateDate(userInput)) {
				employee.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : \n" << "\033[0m";
			}
		}
	}

	while (true) {
		std::cout << "mobileNo* (Starting from [6-9]) : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "mobileNo is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateMobile(userInput)) {
				employee.setMobileNo(std::stoll(userInput));
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Wrong mobileNo...Please enter again!!\n" << "\033[0m";
			}
		}
	}

	while (true) {
		std::cout << "email* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "email is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateEmail(userInput)) {
				employee.setEmail(userInput);
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Wrong email...Please enter again!!\n" << "\033[0m";
			}
		}
	}

	while (true) {
		std::cout << "address* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "Address is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			employee.setAddress(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "gender* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "Gender is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateGender(userInput)) {
				employee.setGender(EmployeeDB::Model::getGenderFromString(userInput));
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
			}
		}
	}

	while (true) {
		std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : \n";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "dateOfJoining is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateDate(userInput)) {
				employee.setDateOfJoining(userInput);
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : \n" << "\033[0m";
			}
		}
	}

	{
		while (true) {
			std::cout << "mentorID : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stoi(userInput) > 0) {
					employee.setMentorID(stoi(userInput));
					break;
				}
				else {
					throw "Negative number  entered!";
				}
			}
			catch (...) {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter Positive real number!!\n" << "\033[0m";
			}
		}
	}

	{
		while (true) {
			std::cout << "performanceMetric : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					employee.setPerformanceMetric(stod(userInput));
					break;
				}
				else {
					throw "Negative number  entered!";
				}
			}
			catch (...) {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter Positive real number!!\n" << "\033[0m";
			}
		}
	}

	{
		while (true) {
			std::cout << "bonus : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					employee.setBonus(stod(userInput));
					break;
				}
				else {
					throw "Negative number  entered!";
				}
			}
			catch (...) {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter Positive real number!!\n" << "\033[0m";
			}
		}
	}
}

void EmployeeView::getUpdateEmployeeInput(Employee& employee, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "firstName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "First Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setFirstName(userInput);
				break;
			}
		}
		break;
	case 2:
	{
		std::cout << "middleName : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			employee.setMiddleName(userInput);
		}
	}
	break;
	case 3:
		while (true) {
			std::cout << "lastName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Last Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setLastName(userInput);
				break;
			}
		}
		break;
	case 4:
	{
		std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		while (true) {
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			if (Validator::validateDate(userInput)) {
				employee.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\033[0m";
			}
		}
	}
	break;
	case 5:
		while (true) {
			std::cout << "mobileNo* (Starting from [6-9]) : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "mobileNo is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateMobile(userInput)) {
					employee.setMobileNo(std::stoll(userInput));
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong mobileNo...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 6:
		while (true) {
			std::cout << "email* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "email is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateEmail(userInput)) {
					employee.setEmail(userInput);
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong email...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 7:
		while (true) {
			std::cout << "address* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Address is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setAddress(userInput);
				break;
			}
		}
		break;
	case 8:
		while (true) {
			std::cout << "gender* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Gender is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateGender(userInput)) {
					employee.setGender(EmployeeDB::Model::getGenderFromString(userInput));
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 9:
		while (true) {
			std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "dateOfJoining is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateDate(userInput)) {
					employee.setDateOfJoining(userInput);
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\033[0m";
				}
			}
		}
		break;
	case 10:
		while (true) {
			std::cout << "mentorID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "mentorID is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						employee.setMentorID(stoi(userInput));
					}
					else {
						throw "Negative number  entered!";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
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
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					employee.setPerformanceMetric(stod(userInput));
					break;
				}
				else {
					throw "Negative number  entered!";
				}
			}
			catch (...) {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter Positive real number!!\n" << "\033[0m";
			}
		}
	}
	break;
	case 12:
	{
		while (true) {
			std::cout << "bonus : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					employee.setBonus(stod(userInput));
					break;
				}
				else {
					throw "Negative number  entered!";
				}
			}
			catch (...) {
				std::cerr << "\033[0;31m" << "Wrong input...Please enter Positive real number!!\n" << "\033[0m";
			}
		}
	}
	break;
	}
}

void EmployeeView::getViewEmployeeInput(Employee& employee, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1: 
		while (true) {
			std::cout << "employeeID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "employeeID is mandatory...Please enter again!!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						employee.setEmployeeID(stoi(userInput));
					}
					else {
						throw "Negative number entered!";
					}
				}
				catch (std::exception& e) {
					std::cout << "\033[0;31m" << "Wrong Input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 2:
		while (true) {
			std::cout << "firstName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "First Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setFirstName(userInput);
				break;
			}
		}
		break;
	case 3:
		while (true) {
			std::cout << "middleName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Middle Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setMiddleName(userInput);
				break;
			}
		}
		break;
	case 4:
		while (true) {
			std::cout << "lastName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Last Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setLastName(userInput);
				break;
			}
		}
		break;
	case 5:
		while (true) {
			std::cout << "dateOfBirth* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "dateOfBirth is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateDate(userInput)) {
					employee.setDateOfBirth(userInput);
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\033[0m";
				}
			}
		}
		break;
	case 6:
		while (true) {
			std::cout << "mobileNo* (Starting from [6-9]) : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "mobileNo is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateMobile(userInput)) {
					employee.setMobileNo(std::stoll(userInput));
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong mobileNo...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 7:
		while (true) {
			std::cout << "email* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "email is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateEmail(userInput)) {
					employee.setEmail(userInput);
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong email...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 8:
		while (true) {
			std::cout << "address* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Address is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				employee.setAddress(userInput);
				break;
			}
		}
		break;
	case 9:
		while (true) {
			std::cout << "gender* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Gender is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateGender(userInput)) {
					employee.setGender(EmployeeDB::Model::getGenderFromString(userInput));
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
				}
			}
		}
		break;
	case 10:
		while (true) {
			std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "dateOfJoining is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				if (Validator::validateDate(userInput)) {
					employee.setDateOfJoining(userInput);
					break;
				}
				else {
					std::cerr << "\033[0;31m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\033[0m";
				}
			}
		}
		break;
	case 11:
		while (true) {
			std::cout << "mentorID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "mentorID is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						employee.setMentorID(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 12:
		while (true) {
			std::cout << "performanceMetric* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "performanceMetric is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stod(userInput) > 0.0) {
						employee.setPerformanceMetric(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	case 13:
		while (true) {
			std::cout << "bonus* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "bonus is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				try {
					if (stod(userInput) > 0.0) {
						employee.setBonus(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\033[0;31m" << "Wrong input...Please enter again!!\n" << "\033[0m";
					continue;
				}
				break;
			}
		}
		break;
	}
}

void EmployeeView::getEmployeeIDInput(Employee& employee, const std::string& operation, const std::string& entity) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " " + entity << "\033[0m" << "------------------------------------------------- \n";
	std::cout << "Please enter employeeID.\n";

	while (true) {
		std::cout << "employeeID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "employeeID is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			if (Validator::validateEmployeeID(userInput, entity)) {
				employee.setEmployeeID(stoi(userInput));
				break;
			}
			else {
				std::cout << "\033[0;31m" << "Wrong input...Please enter positive integer number!!\n" << "\033[0m";
			}
		}
	}
}