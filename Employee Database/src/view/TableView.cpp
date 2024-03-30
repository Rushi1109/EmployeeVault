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

	{
		auto tableName = Utility::getUserInputString("Table Name*");
		table.setTableName(tableName.value());
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
		auto columnName = Utility::getUserInputString("Column name");

		auto columnType = Utility::getUserInputString("Column type");

		auto columnConstrains = Utility::getUserInputString("Column constraints", 0, false);

		columnsVector.emplace_back(std::move(std::array<std::string, 3>{columnName.value(), columnType.value(), columnConstrains.value_or("")}));

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
		auto columnName = Utility::getUserInputString("Column name(foreign key)");

		auto parentTableName = Utility::getUserInputString("Parent table name");

		auto parentTableFieldName = Utility::getUserInputString("Parent table field name");

		auto columnConstrains = Utility::getUserInputString("Column constrains", 0, false);

		foreignKeysVector.emplace_back(std::move(std::array<std::string, 4>{columnName.value(), parentTableName.value(), parentTableFieldName.value(), columnConstrains.value_or("")}));

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

	auto tableName = Utility::getUserInputString("Table name");
	table.setTableName(tableName.value());

	TableController::deleteTable(table.getTableName());

	return Utility::repeatOperation("Delete", "Table");
}