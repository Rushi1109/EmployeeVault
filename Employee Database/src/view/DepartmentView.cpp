#include <iostream>
#include "DepartmentView.h"
#include "DepartmentController.h"
#include "Validator.h"
#include "Utility.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::Validator;

void DepartmentView::printDepartmentFields() {
	std::cout << "Fields with * are required fields\n";
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
	printDepartmentFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertDepartmentInput(obj);
	DepartmentController::insertDepartment(obj);

	return Utility::repeatOperation("insert", "Department");
}

bool DepartmentView::deleteDepartment() {
	if (!Utility::proceedFurther("deletion")) {
		return false;
	}

	std::string userInput;
	std::cout << "Please enter ID of department to delete : \n";

	while (true) {
		std::getline(std::cin, userInput);
		if (userInput.size() == 0) {
			std::cout << "Department id is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (std::stoi(userInput) > 0) {
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	DepartmentController::deleteDepartment(std::stoi(userInput));

	return Utility::repeatOperation("delete", "Department");
}