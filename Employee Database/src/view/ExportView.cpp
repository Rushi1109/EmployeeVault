#include <iostream>
#include <string>
#include "filesystem"
#include "ExportView.h"
#include "Utility.h"
#include "ExportController.h"

using EmployeeDB::View::ExportView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ExportController;

bool ExportView::exportToCSV(const std::string& entity) {
	system("cls");
	std::cout << "------------------------------------------" << "\033[36m" << "Export " << entity << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\033[33m" << "Enter filename for exporting " << entity << "Table to csv.\n" << "\033[0m\n";

	std::string userInput;
	while (true) {
		std::cout << "filename* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[33m" << "filename is mandatory...Please enter again!!" << "\033[0m\n";
		}
		else {
			break;
		}
	}

	std::filesystem::path filename{ userInput };

	ExportController::exportToCSV(entity, filename);

	return Utility::repeatOperation("Export", "table");
}

bool ExportView::exportAll() {
	system("cls");
	std::cout << "------------------------------------------" << "\033[36m" << "Backup Database (Export All) " << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\033[32m" << "Exporting All Tables...\n" << "\033[0m\n";

	ExportController::exportAll();

	return Utility::repeatOperation("Export", "Table");
}