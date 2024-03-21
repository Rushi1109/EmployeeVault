#include <iostream>
#include "Views.h"
#include "DBManager.h"

using EmployeeDB::View::MainView, EmployeeDB::View::EmployeeView, EmployeeDB::View::DepartmentView, EmployeeDB::View::ManagerView;
using EmployeeDB::View::EngineerView, EmployeeDB::View::FinanceView, EmployeeDB::View::QAView, EmployeeDB::View::HRView;
using EmployeeDB::DBManager;

void MainView::mainMenuView() {
	DBManager::executeConfigQuery();

	bool isInvalidInput{ false };

	while (true) {
		printMainMenu();

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-5]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
	std::cout << "------------------------------------------Welcome to Employee Database-------------------------------------------------\n";
	std::cout << "0. Exit\n";
	std::cout << "1. Create Table\n";
	std::cout << "2. Insert Data\n";
	std::cout << "3. Update Data\n";
	std::cout << "4. Delete Data\n";
	std::cout << "5. View Data\n";
	std::cout << "Please select an operation to perform:\n";
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
		std::cout << "------------------------------------------Insert Menu-------------------------------------------------\n";
		printTableMenu();
		std::cout << "Please select an entity to insert:\n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-7]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
		std::cout << "------------------------------------------Update Menu-------------------------------------------------\n";
		printTableMenu();
		std::cout << "Please select an entity to update:\n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-7]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
		std::cout << "------------------------------------------Delete Menu-------------------------------------------------\n";
		printTableMenu();
		std::cout << "Please select an entity to delete:\n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-7]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
		std::cout << "------------------------------------------View Menu-------------------------------------------------\n";
		printTableMenu();
		std::cout << "Please select an entity to view:\n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-7]\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeWhiteSpaces(inputLine);

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
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		//DepartmentView::select();
		break;
	case 2:
		//EngineerView::select();
		break;
	case 3:
		//FinanceView::select();
		break;
	case 4:
		//HRView::select();
		break;
	case 5:
		//QAView::select();
		break;
	case 6:
		//ManagerView::select();
		break;
	}
}