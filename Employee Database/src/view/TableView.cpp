#include <iostream>
#include <array>
#include <vector>
#include "Table.h"
#include "TableView.h"
#include "TableController.h"
#include "Utility.h"

using EmployeeDB::Controller::TableController;
using EmployeeDB::View::TableView;
using EmployeeDB::Model::Table;

bool TableView::createTableView() {
	Table table;

	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << "Create Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "Fields with * are required fields" << '\n';

	while (true) {
		std::string tableName;
		std::cout << "Table name* : ";
		std::getline(std::cin, tableName);
		Utility::removeEmptySpaces(tableName);

		if (tableName.size() == 0) {
			std::cout << "\033[0;31m" << "Table Name is mandatory...Please enter again!!" << '\n' << "\033[0m";
		}
		else {
			table.setTableName(tableName);
			break;
		}
	}

	std::vector<std::array<std::string, 3>> attributesVector;
	attributesVector.reserve(10);

	getColumnsInput(attributesVector);
	
	std::vector<std::array<std::string, 4>> foreignKeysVector;
	foreignKeysVector.reserve(4);

	getForeignKeysInput(foreignKeysVector);

	table.setAttributesVector(attributesVector);
	table.setForeignKeysVector(std::move(foreignKeysVector));

	TableController::createTable(table);

	return Utility::repeatOperation("Create", "table");
}

void TableView::getColumnsInput(std::vector<std::array<std::string, 3>>& columnsVector) {
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

		std::string columnConstrains{ "" };
		{
			std::cout << "Column constrains : ";
			std::getline(std::cin, columnConstrains);
			Utility::removeEmptySpaces(columnConstrains);
		}

		columnsVector.emplace_back(std::move(std::array<std::string, 3>{columnName, columnType, columnConstrains}));

		if (!Utility::repeatOperation("add", "column")) {
			break;
		}
	}
}

void TableView::getForeignKeysInput(std::vector<std::array<std::string, 4>>& foreignKeysVector) {
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

		foreignKeysVector.emplace_back(std::move(std::array<std::string, 4>{columnName, parentTableName, parentTableFieldName, columnConstrains}));

		if (!Utility::repeatOperation("add", "foreign key")) {
			foreignKeyInsertion = false;
		}
	}
}

bool TableView::deleteTableView() {
	Table table;

	system("cls");
	std::cout << "------------------------------------------" << "\033[36m" << "Delete Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\033[33m" << "Enter the name of the Table you want to delete." << "\033[0m\n";

	std::string tableName;
	while (true) {
		std::cout << "Table name* : ";
		std::getline(std::cin, tableName);
		Utility::removeEmptySpaces(tableName);

		if (tableName.size() == 0) {
			std::cout << "\033[33m" << "Table Name is mandatory...Please enter again!!" << "\033[0m\n";
		}
		else {
			table.setTableName(tableName);
			break;
		}
	}

	TableController::deleteTable(tableName);

	return Utility::repeatOperation("Delete", "Table");
}