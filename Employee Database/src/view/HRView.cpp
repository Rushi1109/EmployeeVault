#include <iostream>
#include "EmployeeView.h"
#include "HRView.h"
#include "HRController.h"
#include "Utility.h"
#include "Validator.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::HRController;
using EmployeeDB::Validator;

bool HRView::insertHR() {
	HR hr;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Insert HR" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. hrSpecialization* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(hr);

	{
		auto hrSpecialization = Utility::getUserInputString("hrSpecialization");
		hr.setHRSpecialization(hrSpecialization.value());
	}

	HRController::insertHR(hr);

	return Utility::repeatOperation("insert", "HR");
}

bool HRView::deleteHR() {
	HR hr;

	EmployeeView::getEmployeeIDInput(hr, "Delete", "HR");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Delete HR" << "\033[0m" << "-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(hr.getEmployeeID()));

	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	HRController::deleteHRByID(hr.getEmployeeID());

	return Utility::repeatOperation("delete", "HR");
}

bool HRView::updateHR() {
	HR hr{ true };

	EmployeeView::getEmployeeIDInput(hr, "Update", "HR");

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Update HR" << "\033[0m" << "-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(hr.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	auto isInvalidInput{ false };
	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update HR-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. hrSpecialization* : " << '\n';
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
				EmployeeView::getUpdateEmployeeInput(hr, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 13) {
				{
					auto hrSpecialization = Utility::getUserInputString("hrSpecialization");
					hr.setHRSpecialization(hrSpecialization.value());
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

	HRController::updateHR(hr);

	return Utility::repeatOperation("update", "HR");
}

bool HRView::viewHR() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View HR" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View HR based on a field" << '\n';
		std::cout << "2. View all HR" << '\n';
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
				if (!viewHRConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				HRController::selectHR();
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

	return Utility::repeatOperation("view", "HR");
}

void HRView::printViewHRFields() {
	std::cout << "14. hrSpecialization* :" << '\n';
}

void HRView::getViewHRInput(HR& hr, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
		case 14:
		{
			auto hrSpecialization = Utility::getUserInputString("hrSpecialization");
			hr.setHRSpecialization(hrSpecialization.value());
		}
		break;
	}
}

bool HRView::viewHRConditional() {
	HR hr;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View HR" << "\033[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewHRFields();
		std::cout << "15. Go back" << '\n';
		std::cout << "\033[0;33m" << "Select the field by which you want to view a HR, or select 0/15 for operations: \n" << "\033[0m";

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
				EmployeeView::getViewEmployeeInput(hr, 1);
				HRController::selectHR("employeeID", std::to_string(hr.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(hr, 2);
				HRController::selectHR("firstName", hr.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(hr, 3);
				HRController::selectHR("middleName", hr.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(hr, 4);
				HRController::selectHR("lastName", hr.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(hr, 5);
				HRController::selectHR("dateOfBirth", hr.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(hr, 6);
				HRController::selectHR("mobileNo", std::to_string(hr.getMobileNo()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(hr, 7);
				HRController::selectHR("email", hr.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(hr, 8);
				HRController::selectHR("address", hr.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(hr, 9);
				HRController::selectHR("gender", EmployeeDB::Model::getGenderString(hr.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(hr, 10);
				HRController::selectHR("dateOfJoining", hr.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(hr, 11);
				HRController::selectHR("mentorID", std::to_string(hr.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(hr, 12);
				HRController::selectHR("performanceMetric", std::to_string(hr.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(hr, 13);
				HRController::selectHR("bonus", std::to_string(hr.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				getViewHRInput(hr, 14);
				HRController::selectHR("hrSpecialization", hr.getHRSpecialization());
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
	return true;
}