#include <iostream>
#include "Utility.h"

using EmployeeDB::View::Utility;

bool Utility::proceedFurther(const std::string& operation) {
	bool isInvalidInput{ false };

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to proceed with " + operation + "? [y/n] : ";
		}

		std::string inputLine;
		std::getline(std::cin, inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "Wrong Input, Please enter character [y/n] : ";
			isInvalidInput = true;
		}
	}

	return false;
}

bool Utility::repeatOperation(const std::string& operation, const std::string& Entity) {
	bool isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to "+ operation + " another " + Entity + " ? [y / n] : ";
		}

		std::string inputLine;
		std::getline(std::cin, inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "Wrong Input, Please enter character [y/n] : ";
			isInvalidInput = true;
		}
	}

	return false;
}