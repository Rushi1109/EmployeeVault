#include <iostream>
#include "EmployeeView.h"
#include "FinanceView.h"
#include "FinanceController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::FinanceView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Validator;

bool FinanceView::insertFinance() {
	Finance obj;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert Finance" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. accountingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "accountingTool* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "accountingTool is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			obj.setAccountingTool(userInput);
			break;
		}
	}

	FinanceController::insertFinance(obj);

	return Utility::repeatOperation("insert", "Finance");
}

bool FinanceView::deleteFinance() {
	Finance obj;

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Finance");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Delete Finance" << "\033[0m" << "-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	FinanceController::deleteFinanceByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Finance");
}

bool FinanceView::updateFinance() {
	Finance obj{ true };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Finance");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Update Finance" << "\033[0m" << "-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	auto isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Finance-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. accountingTool* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "\033[0;33m" << "Select the field you want to update, or select 0/14 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-14]\n" << "\033[0m";
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
			else if (userInput >= 1 && userInput <= 12) {
				EmployeeView::getUpdateEmployeeInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 13) {
				while (true) {
					std::cout << "accountingTool* : ";
					std::getline(std::cin, inputLine);
					Utility::removeEmptySpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "\033[0;31m" << "accountingTool is mandatory...Please enter again!!" << '\n' << "\033[0m";
					}
					else {
						obj.setAccountingTool(inputLine);
						break;
					}
				}
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 14) {
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

	FinanceController::updateFinance(obj);

	return Utility::repeatOperation("update", "Finance");
}

bool FinanceView::viewFinance() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Finance" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Finance based on a field" << '\n';
		std::cout << "2. View all Finance" << '\n';
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
				if (!viewFinanceConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				FinanceController::selectFinance();
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

	return Utility::repeatOperation("view", "Finance");
}

void FinanceView::printViewFinanceFields() {
	std::cout << "14. accountingTool* :" << '\n';
}

void FinanceView::getViewFinanceInput(Finance& finance, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 14:
		while (true) {
			std::cout << "accountingTool* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Accounting Tool is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				finance.setAccountingTool(userInput);
				break;
			}
		}
		break;
	}
}

bool FinanceView::viewFinanceConditional() {
	Finance finance;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Finance" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewFinanceFields();
		std::cout << "15. Go back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view a Finance, or select 0/15 for operations: \n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-15]\n" << "\033[0m";
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
				EmployeeView::getViewEmployeeInput(finance, 1);
				FinanceController::selectFinance("employeeID", std::to_string(finance.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(finance, 2);
				FinanceController::selectFinance("firstName", finance.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(finance, 3);
				FinanceController::selectFinance("middleName", finance.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(finance, 4);
				FinanceController::selectFinance("lastName", finance.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(finance, 5);
				FinanceController::selectFinance("dateOfBirth", finance.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(finance, 6);
				FinanceController::selectFinance("mobileNo", std::to_string(finance.getMobileNo()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(finance, 7);
				FinanceController::selectFinance("email", finance.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(finance, 8);
				FinanceController::selectFinance("address", finance.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(finance, 9);
				FinanceController::selectFinance("gender", EmployeeDB::Model::getGenderString(finance.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(finance, 10);
				FinanceController::selectFinance("dateOfJoining", finance.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(finance, 11);
				FinanceController::selectFinance("mentorID", std::to_string(finance.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(finance, 12);
				FinanceController::selectFinance("performanceMetric", std::to_string(finance.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(finance, 13);
				FinanceController::selectFinance("bonus", std::to_string(finance.getBonus()));
				break;
			}
			else if (userInput == 14) {
				getViewFinanceInput(finance, 14);
				FinanceController::selectFinance("accountingTool", finance.getAccountingTool());
				break;
			}
			else if (userInput == 15) {
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
}