#include <iostream>
#include <map>
#include "Table.h"
#include "TableView.h"
#include "Utility.h"

using EmployeeDB::View::TableView;
using EmployeeDB::Model::Table;

bool TableView::createTableView() {
	Table table;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Create Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields" << '\n';

	while (true) {
		std::string userInput;
		std::cout << "Table name* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\033[0;31m" << "Table Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			table.setTableName(userInput);
			break;
		}
	}

	std::vector<std::array<std::string, 3>> attributesVector(10);

	while (true) {
		std::string columnName;
		while (true) {
			std::cout << "Column name* : ";
			std::getline(std::cin, columnName);
			Utility::removeEmptySpaces(columnName);

			if (columnName.size() == 0) {
				std::cout << "\033[0;31m" << "Column Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				break;
			}
		}

		std::string columnType;
		while (true) {
			std::cout << "Column type* : ";
			std::getline(std::cin, columnType);
			Utility::removeEmptySpaces(columnType);

			if (columnType.size() == 0) {
				std::cout << "\033[0;31m" << "Column Type is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				break;
			}
		}

		std::string columnConstrains{""};
		{
			std::cout << "Column constrains : ";
			std::getline(std::cin, columnConstrains);
			Utility::removeEmptySpaces(columnConstrains);
		}

		attributesVector.emplace_back(columnName, columnType, columnConstrains);

		if (!Utility::repeatOperation("add", "column")) {
			break;
		}
	}
	
	std::vector<std::array<std::string, 4>> foreignKeysVector;

	auto foreignKeyInsertion{ true };
	if (!Utility::proceedFurther("foreign key insertion")) {
		foreignKeyInsertion = false;
	}

	while (foreignKeyInsertion) {
		std::string columnName;
		while (true) {
			std::cout << "Column name(foreign key)* : ";
			std::getline(std::cin, columnName);
			Utility::removeEmptySpaces(columnName);

			if (columnName.size() == 0) {
				std::cout << "\033[0;31m" << "Column Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				break;
			}
		}

		std::string parentTableName;
		while (true) {
			std::cout << "Parent table name* : ";
			std::getline(std::cin, parentTableName);
			Utility::removeEmptySpaces(parentTableName);

			if (columnName.size() == 0) {
				std::cout << "\033[0;31m" << "Parent Table is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				break;
			}
		}

		std::string parentTableFieldName;
		while (true) {
			std::cout << "Parent table field name* : ";
			std::getline(std::cin, parentTableFieldName);
			Utility::removeEmptySpaces(parentTableFieldName);

			if (parentTableFieldName.size() == 0) {
				std::cout << "\033[0;31m" << "Parent table field is mandatory...Please enter again!!" << '\n' << "\033[0m";
			}
			else {
				break;
			}
		}

		std::string columnConstrains;
		{
			std::cout << "Column constrains : ";
			std::getline(std::cin, columnConstrains);
			Utility::removeEmptySpaces(columnConstrains);
		}

		foreignKeysVector.emplace_back(columnName, parentTableName, parentTableFieldName, columnConstrains);

		if (!Utility::repeatOperation("add", "foreign key")) {
			foreignKeyInsertion = false;
		}
	}

	table.setAttributesVector(attributesVector);
	table.setForeignKeysVector(std::move(foreignKeysVector));

	// TableController::createTable(Table)

	return true;
}