#include <iostream>
#include "Views.h"
#include "DBManager.h"

using EmployeeDB::View::MainView, EmployeeDB::View::EmployeeView, EmployeeDB::View::DepartmentView, EmployeeDB::View::ManagerView;
using EmployeeDB::View::EngineerView, EmployeeDB::View::FinanceView, EmployeeDB::View::QAView, EmployeeDB::View::HRView;
using EmployeeDB::DBManager;

void MainView::mainMenuView() {
	bool isInvalidInput{ false };

	while (true) {
		printMainMenu();

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
			if (userInput >= 0 && userInput <= 5) {
				mainMenuSelection(userInput);
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

void MainView::printMainMenu() {
	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Welcome to Employee Database" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "0. Exit\n";
	std::cout << "1. Create Table\n";
	std::cout << "2. Insert Data\n";
	std::cout << "3. Update Data\n";
	std::cout << "4. Delete Data\n";
	std::cout << "5. View Data\n";
	std::cout << "\033[0;33m" << "Please select an operation to perform:\n" << "\033[0m";
}

void MainView::mainMenuSelection(short int userInput) {
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		//createTableView();
		break;
	case 2:
		insertMenuView();
		break;
	case 3:
		updateMenuView();
		break;
	case 4:
		deleteMenuView();
		break;
	case 5:
		viewMenuView();
		break;
	}
};

void MainView::printTableMenu() {
	std::cout << "0. Exit\n";
	std::cout << "1. Department\n";
	std::cout << "2. Engineer\n";
	std::cout << "3. Finance\n";
	std::cout << "4. HR\n";
	std::cout << "5. QA\n";
	std::cout << "6. Manager\n";
	std::cout << "7. Main Menu\n";
}

void MainView::insertMenuView() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "Insert Menu" << "\033[0m" << "------------------------------------------------- \n";
		printTableMenu();
		std::cout << "\033[0;33m" << "Please select an entity to insert:\n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-7]\n" << "\033[0m";
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
			if (userInput >= 0 && userInput <= 6) {
				insertMenuSelection(userInput);
			}
			else if (userInput == 7) {
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

void MainView::insertMenuSelection(short int userInput) {
	bool continueInsertion{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueInsertion) {
			continueInsertion = DepartmentView::insertDepartment();
		}
		break;
	case 2:
		while (continueInsertion) {
			continueInsertion = EngineerView::insertEngineer();
		}
		break;
	case 3:
		while (continueInsertion) {
			continueInsertion = FinanceView::insertFinance();
		}
		break;
	case 4:
		while (continueInsertion) {
			continueInsertion = HRView::insertHR();
		}
		break;
	case 5:
		while (continueInsertion) {
			continueInsertion = QAView::insertQA();
		}
		break;
	case 6:
		while (continueInsertion) {
			continueInsertion = ManagerView::insertManager();
		}
		break;
	}
}

void MainView::updateMenuView() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "Update Menu" << "\033[0m" << "------------------------------------------------- \n";
		printTableMenu();
		std::cout << "\033[0;33m" << "Please select an entity to update:\n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-7]\n" << "\033[0m";
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
			if (userInput >= 0 && userInput <= 6) {
				updateMenuSelection(userInput);
			}
			else if (userInput == 7) {
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

void MainView::updateMenuSelection(short int userInput) {
	bool continueUpdation{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueUpdation) {
			continueUpdation = DepartmentView::updateDepartment();
		}
		break;
	case 2:
		while (continueUpdation) {
			continueUpdation = EngineerView::updateEngineer();
		}
		break;
	case 3:
		while (continueUpdation) {
			continueUpdation = FinanceView::updateFinance();
		}
		break;
	case 4:
		while (continueUpdation) {
			continueUpdation = HRView::updateHR();
		}
		break;
	case 5:
		while (continueUpdation) {
			continueUpdation = QAView::updateQA();
		}
		break;
	case 6:
		while (continueUpdation) {
			continueUpdation = ManagerView::updateManager();
		}
		break;
	}
}

void MainView::deleteMenuView() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "Delete Menu" << "\033[0m" << "------------------------------------------------- \n";
		printTableMenu();
		std::cout << "\033[0;33m" << "Please select an entity to delete:\n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-7]\n" << "\033[0m";
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
			if (userInput >= 0 && userInput <= 6) {
				deleteMenuSelection(userInput);
			}
			else if (userInput == 7) {
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

void MainView::deleteMenuSelection(short int userInput) {
	bool continueDeletion{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueDeletion) {
			continueDeletion = DepartmentView::deleteDepartment();
		}
		break;
	case 2:
		while (continueDeletion) {
			continueDeletion = EngineerView::deleteEngineer();
		}
		break;
	case 3:
		while (continueDeletion) {
			continueDeletion = FinanceView::deleteFinance();
		}
		break;
	case 4:
		while (continueDeletion) {
			continueDeletion = HRView::deleteHR();
		}
		break;
	case 5:
		while (continueDeletion) {
			continueDeletion = QAView::deleteQA();
		}
		break;
	case 6:
		while (continueDeletion) {
			continueDeletion = ManagerView::deleteManager();
		}
		break;
}
}

void MainView::viewMenuView() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\033[0;36m" << "View Menu" << "\033[0m" << "------------------------------------------------- \n";
		printTableMenu();
		std::cout << "\033[0;33m" << "Please select an entity to view:\n" << "\033[0m";

		if (isInvalidInput) {
			std::cerr << "\033[0;31m" << "Wrong Input, Please enter an input in the range: [0-7]\n" << "\033[0m";
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
			if (userInput >= 0 && userInput <= 6) {
				viewMenuSelection(userInput);
			}
			else if (userInput == 7) {
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

void MainView::viewMenuSelection(short int userInput) {
	bool continueViewing{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueViewing) {
			continueViewing = DepartmentView::viewDepartment();
		}
		break;
	case 2:
		while (continueViewing) {
			continueViewing = EngineerView::viewEngineer();
		}
		break;
	case 3:
		while (continueViewing) {
			continueViewing = FinanceView::viewFinance();
		}
		break;
	case 4:
		while (continueViewing) {
			continueViewing = HRView::viewHR();
		}
		break;
	case 5:
		while (continueViewing) {
			continueViewing = QAView::viewQA();
		}
		break;
	case 6:
		while (continueViewing) {
			continueViewing = ManagerView::viewManager();
		}
		break;
	}
}