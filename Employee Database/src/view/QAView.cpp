#include <iostream>
#include "EmployeeView.h"
#include "QAView.h"
#include "QAController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::QAView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::QAController;
using EmployeeDB::Validator;

bool QAView::insertQA() {
	QA qa;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert QA" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. testingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(qa);

	std::string userInput;

	while (true) {
		std::cout << "testingTool* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "testingTool is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			qa.setTestingTool(userInput);
			break;
		}
	}

	QAController::insertQA(qa);

	return Utility::repeatOperation("insert", "QA");
}

bool QAView::deleteQA() {
	QA qa;

	EmployeeView::getEmployeeIDInput(qa, "Delete", "QA");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Delete QA" << "\033[0m" << "-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(qa.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	QAController::deleteQAByID(qa.getEmployeeID());

	return Utility::repeatOperation("delete", "QA");
}

bool QAView::updateQA() {
	QA qa{ true };

	EmployeeView::getEmployeeIDInput(qa, "Update", "QA");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Update QA" << "\033[0m" << "-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(qa.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	bool isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update QA-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. testingTool* : " << '\n';
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
				EmployeeView::getUpdateEmployeeInput(qa, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 13) {
				while (true) {
					std::cout << "testingTool* : ";
					std::getline(std::cin, inputLine);
					Utility::removeEmptySpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
					}
					else {
						qa.setTestingTool(inputLine);
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

	QAController::updateQA(qa);

	return Utility::repeatOperation("update", "QA");
}

bool QAView::viewQA() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View QA" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View QA based on a field" << '\n';
		std::cout << "2. View all QA" << '\n';
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
				viewQAConditional();
				break;
			}
			else if (userInput == 2) {
				QAController::selectQA();
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

	return Utility::repeatOperation("view", "QA");
}

void QAView::printViewQAFields() {
	std::cout << "14. testingTool* :" << '\n';
}

void QAView::getViewQAInput(QA& qa, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 14:
		while (true) {
			std::cout << "testingTool* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\033[0;31m" << "Testing tool is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				qa.setTestingTool(userInput);
				break;
			}
		}
		break;
	}
}

void QAView::viewQAConditional() {
	QA qa;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View QA" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewQAFields();
		std::cout << "15. Go back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view a QA, or select 0/15 for operations: \n" << "\033[0m";

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
				EmployeeView::getViewEmployeeInput(qa, 1);
				QAController::selectQA("employeeID", std::to_string(qa.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(qa, 2);
				QAController::selectQA("firstName", qa.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(qa, 3);
				QAController::selectQA("middleName", qa.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(qa, 4);
				QAController::selectQA("lastName", qa.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(qa, 5);
				QAController::selectQA("dateOfBirth", qa.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(qa, 6);
				QAController::selectQA("mobileNo", std::to_string(qa.getMobileNo()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(qa, 7);
				QAController::selectQA("email", qa.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(qa, 8);
				QAController::selectQA("address", qa.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(qa, 9);
				QAController::selectQA("gender", EmployeeDB::Model::getGenderString(qa.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(qa, 10);
				QAController::selectQA("dateOfJoining", qa.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(qa, 11);
				QAController::selectQA("mentorID", std::to_string(qa.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(qa, 12);
				QAController::selectQA("performanceMetric", std::to_string(qa.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(qa, 13);
				QAController::selectQA("bonus", std::to_string(qa.getBonus()));
				break;
			}
			else if (userInput == 14) {
				getViewQAInput(qa, 14);
				QAController::selectQA("testingTool", qa.getTestingTool());
				break;
			}
			else if (userInput == 15) {
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