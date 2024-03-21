#include <iostream>
#include "DepartmentView.h"
#include "DepartmentController.h"
#include "Validator.h"
#include "Utility.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::Validator;

void DepartmentView::printDepartmentFields() {
	std::cout << "1. departmentName* : " << '\n';
	std::cout << "2. baseSalary* : " << '\n';
	std::cout << "3. allowance* : " << '\n';
	std::cout << "4. deduction* : " << '\n';
}

void DepartmentView::getInsertDepartmentInput(Department& obj) {
	std::string userInput;

	while (true) {
		std::cout << "departmentName* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setDepartmentName(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "baseSalary* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBaseSalary(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter Positive real number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "allowance* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "allowance is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setAllowance(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please Positive enter real number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "deduction* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "deduction is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setDeduction(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
				continue;
			}
			break;
		}
	}
};

bool DepartmentView::insertDepartment() {
	Department obj;

	system("cls");
	std::cout << "------------------------------------------Insert Department-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	printDepartmentFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertDepartmentInput(obj);
	DepartmentController::insertDepartment(obj);

	return Utility::repeatOperation("insert", "Department");
}

bool DepartmentView::getDepartmentIDInput(Department& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " Department-------------------------------------------------\n";
	std::cout << "Please enter Department ID.\n";

	while (true) {
		std::cout << "Department ID* : ";
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Department ID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateEmployeeID(userInput)) {
				obj.setDepartmentID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------" + operation + " Department-------------------------------------------------\n";
	DepartmentController::selectDepartment("departmentID", userInput);

	return Utility::proceedFurther(operation);
}

bool DepartmentView::deleteDepartment() {
	Department obj;

	if (!getDepartmentIDInput(obj, "Delete")) {
		return false;
	}

	DepartmentController::deleteDepartmentByID(obj.getDepartmentID());

	return Utility::repeatOperation("delete", "Department");
}

void DepartmentView::getUpdateDepartmentInput(Department& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "departmentName* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setDepartmentName(userInput);
				break;
			}
		}
		break;

	case 2:
		while (true) {
			std::cout << "baseSalary* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setBaseSalary(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "Wrong input...Please enter Positive real number!!\n";
					continue;
				}
				break;
			}
		}
		break;

	case 3:
		while (true) {
			std::cout << "allowance* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "allowance is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setAllowance(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "Wrong input...Please Positive enter real number!!\n";
					continue;
				}
				break;
			}
		}
		break;

	case 4:
		while (true) {
			std::cout << "deduction* : ";
			std::getline(std::cin, userInput);
			if (userInput.size() == 0) {
				std::cout << "deduction is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setDeduction(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cerr << "Wrong input...Please enter Positive real number!!\n";
					continue;
				}
				break;
			}
		}
		break;
	}
}

bool DepartmentView::updateDepartment() {
	Department obj{ true };

	if (!getDepartmentIDInput(obj, "Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Department-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		printDepartmentFields();
		std::cout << "5. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/5 for other operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-5]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput >= 1 && userInput <= 4) {
				getUpdateDepartmentInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 5) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	DepartmentController::updateDepartment(obj);

	return Utility::repeatOperation("update", "Department");
}