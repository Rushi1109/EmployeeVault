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

void DepartmentView::printViewDepartmentFields() {
	std::cout << "1. departmentID* : " << '\n';
	std::cout << "2. departmentName* : " << '\n';
	std::cout << "3. baseSalary* : " << '\n';
	std::cout << "4. allowance* : " << '\n';
	std::cout << "5. deduction* : " << '\n';
}

void DepartmentView::getInsertDepartmentInput(Department& department) {
	{
		auto departmentName = Utility::getUserInputString("departmentName");
		department.setDepartmentName(departmentName.value());
	}

	{
		auto baseSalary = Utility::getUserInputDouble("baseSalary");
		department.setBaseSalary(baseSalary.value());
	}

	{
		auto allowance = Utility::getUserInputDouble("allowance");
		department.setAllowance(allowance.value());
	}

	{
		auto deduction = Utility::getUserInputDouble("deduction");
		department.setDeduction(deduction.value());
	}
};

bool DepartmentView::insertDepartment() {
	Department department;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert Department" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	printDepartmentFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertDepartmentInput(department);
	DepartmentController::insertDepartment(department);

	return Utility::repeatOperation("insert", "Department");
}

bool DepartmentView::getDepartmentIDInput(Department& department, const std::string& operation) {
	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Department" << "\033[0m" << "------------------------------------------------\n";
	std::cout << "Please enter Department ID.\n";

	{
		auto departmentID = Utility::getUserInputInt("departmentID");
		department.setDepartmentID(departmentID.value());
	}

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " Department" << "\033[0m" << "------------------------------------------------\n";
	DepartmentController::selectDepartment("departmentID", std::to_string(department.getDepartmentID()));

	return Utility::proceedFurther(operation);
}

bool DepartmentView::deleteDepartment() {
	Department department;

	if (!getDepartmentIDInput(department, "Delete")) {
		return false;
	}

	DepartmentController::deleteDepartmentByID(department.getDepartmentID());

	return Utility::repeatOperation("delete", "Department");
}

void DepartmentView::getUpdateDepartmentInput(Department& department, int fieldNumber) {
	switch (fieldNumber) {
		case 1:
		{
			auto departmentName = Utility::getUserInputString("departmentName");
			department.setDepartmentName(departmentName.value());
		}
		break;

		case 2:
		{
			auto baseSalary = Utility::getUserInputDouble("baseSalary");
			department.setBaseSalary(baseSalary.value());
		}
		break;

		case 3:
		{
			auto allowance = Utility::getUserInputDouble("allowance");
			department.setAllowance(allowance.value());
		}
		break;

		case 4:
		{
			auto deduction = Utility::getUserInputDouble("deduction");
			department.setDeduction(deduction.value());
		}
		break;
	}
}

bool DepartmentView::updateDepartment() {
	Department department{ true };

	if (!getDepartmentIDInput(department, "Update")) {
		return false;
	}

	auto isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "Update Department" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		printDepartmentFields();
		std::cout << "5. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the field you want to update, or select 0/5 for other operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-5]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

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
				getUpdateDepartmentInput(department, userInput);
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

	DepartmentController::updateDepartment(department);

	return Utility::repeatOperation("update", "Department");
}

void DepartmentView::getViewDepartmentInput(Department& department, int fieldNumber) {
	switch (fieldNumber) {
		case 1:
		{
			auto departmentID = Utility::getUserInputInt("departmentID");
			department.setDepartmentID(departmentID.value());
		}
		break;

		case 2:
		{
			auto departmentName = Utility::getUserInputString("departmentName");
			department.setDepartmentName(departmentName.value());
		}
		break;

		case 3:
		{
			auto baseSalary = Utility::getUserInputDouble("baseSalary");
			department.setBaseSalary(baseSalary.value());
		}
		break;

		case 4:
		{
			auto allowance = Utility::getUserInputDouble("allowance");
			department.setAllowance(allowance.value());
		}
		break;

		case 5:
		{
			auto deduction = Utility::getUserInputDouble("deduction");
			department.setDeduction(deduction.value());
		}
		break;
	}
}

bool DepartmentView::viewDepartmentConditional() {
	Department department;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Department" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		printViewDepartmentFields();
		std::cout << "6. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view the Department, or select 0/6 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-6]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				getViewDepartmentInput(department, 1);
				DepartmentController::selectDepartment("departmentID", std::to_string(department.getDepartmentID()));
				break;
			}
			else if (userInput == 2) {
				getViewDepartmentInput(department, 2);
				DepartmentController::selectDepartment("departmentName", department.getDepartmentName());
				break;
			}
			else if (userInput == 3) {
				getViewDepartmentInput(department, 3);
				DepartmentController::selectDepartment("baseSalary", std::to_string(department.getBaseSalary()));
				break;
			}
			else if (userInput == 4) {
				getViewDepartmentInput(department, 4);
				DepartmentController::selectDepartment("allowance", std::to_string(department.getAllowance()));
				break;
			}
			else if (userInput == 5) {
				getViewDepartmentInput(department, 5);
				DepartmentController::selectDepartment("deduction", std::to_string(department.getDeduction()));
				break;
			}
			else if (userInput == 6) {
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
	return true;
}

bool DepartmentView::viewDepartment() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Department" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Department based on a field" << '\n';
		std::cout << "2. View all Department" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the operation [0-3]: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-3]\n" << "\033[0m";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				if (!viewDepartmentConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				DepartmentController::selectDepartment();
				break;
			}
			else if (userInput == 3) {
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

	return Utility::repeatOperation("view", "Department");
}