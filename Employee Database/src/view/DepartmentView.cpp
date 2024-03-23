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
	std::string userInput;

	while (true) {
		std::cout << "departmentName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
		}
		else {
			department.setDepartmentName(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "baseSalary* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					department.setBaseSalary(stod(userInput));
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
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "allowance is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					department.setAllowance(stod(userInput));
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
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "deduction is mandatory...Please enter again!!" << '\n';
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					department.setDeduction(stod(userInput));
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
	Department department;

	system("cls");
	std::cout << "------------------------------------------Insert Department-------------------------------------------------\n";
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
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" + operation + " Department-------------------------------------------------\n";
	std::cout << "Please enter Department ID.\n";

	while (true) {
		std::cout << "Department ID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "Department ID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validator::validateDepartmentID(userInput)) {
				department.setDepartmentID(stoi(userInput));
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
	Department department;

	if (!getDepartmentIDInput(department, "Delete")) {
		return false;
	}

	DepartmentController::deleteDepartmentByID(department.getDepartmentID());

	return Utility::repeatOperation("delete", "Department");
}

void DepartmentView::getUpdateDepartmentInput(Department& department, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "departmentName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
			}
			else {
				department.setDepartmentName(userInput);
				break;
			}
		}
		break;

	case 2:
		while (true) {
			std::cout << "baseSalary* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setBaseSalary(stod(userInput));
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
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "allowance is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setAllowance(stod(userInput));
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
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "deduction is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setDeduction(stod(userInput));
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
	Department department{ true };

	if (!getDepartmentIDInput(department, "Update")) {
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
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "departmentID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "departmentID is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						department.setDepartmentID(stoi(userInput));
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
	case 2:
		while (true) {
			std::cout << "departmentName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
			}
			else {
				department.setDepartmentName(userInput);
				break;
			}
		}
		break;

	case 3:
		while (true) {
			std::cout << "baseSalary* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setBaseSalary(stod(userInput));
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

	case 4:
		while (true) {
			std::cout << "allowance* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "allowance is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setAllowance(stod(userInput));
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

	case 5:
		while (true) {
			std::cout << "deduction* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "deduction is mandatory...Please enter again!!" << '\n';
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						department.setDeduction(stod(userInput));
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

void DepartmentView::viewDepartmentConditional() {
	Department department;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Department-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		printViewDepartmentFields();
		std::cout << "6. Go Back" << '\n';
		std::cout << "Select the field by which you want to view the Department, or select 0/6 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-6]\n";
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
				getViewDepartmentInput(department, 3);
				DepartmentController::selectDepartment("allowance", std::to_string(department.getAllowance()));
				break;
			}
			else if (userInput == 5) {
				getViewDepartmentInput(department, 3);
				DepartmentController::selectDepartment("deduction", std::to_string(department.getDeduction()));
				break;
			}
			else if (userInput == 6) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

bool DepartmentView::viewDepartment() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Department-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Department based on a field" << '\n';
		std::cout << "2. View all Department" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "Select the operation [0-3]: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-3]\n";
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
				viewDepartmentConditional();
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