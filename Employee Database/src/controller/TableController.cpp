#include <iostream>
#include "TableController.h"
#include "DBManager.h"

using EmployeeDB::Controller::TableController;

bool TableController::createTable(Table& table) {
	std::string queryString = getCreateTableQuery(table);

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[32m" << "Successfully Created Table : " << table.getTableName() << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
		std::cerr << "\033[31m" << "Table " << table.getTableName() << " could not be created." << "\033[0m\n";
		return false;
	}
	return true;
}

std::string TableController::getCreateTableQuery(Table& table) {
	std::string queryString = "CREATE TABLE \"" + table.getTableName() + "\" (";

	auto isFirstAttribute{ true };

	for (const auto& [columnName, columnType, columnConstraints] : table.getAttributesVector()) {

		if (!isFirstAttribute) {
			queryString += ", ";
		}
		else {
			isFirstAttribute = false;
		}

		queryString += "\"" + columnName + "\" ";
		queryString += columnType + " ";

		if (columnConstraints.size() != 0) {
			queryString += columnConstraints;
		}
	}

	for (const auto& [keyColumnName, parentTableName, parenTableColumn, keyConstraints] : table.getForeignKeysVector()) {

		queryString += ", ";

		queryString += "FOREIGN KEY (\"" + keyColumnName + "\") ";
		queryString += "REFERENCES \"" + parentTableName + "\"(\"" + parenTableColumn + "\") ";
		queryString += keyConstraints;
	}

	queryString += ");";

	return std::move(queryString);
}

bool TableController::deleteTable(const std::string& tableName) {
	std::string queryString = "DROP TABLE " + tableName;

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[32m" << "Successfully Deleted Table : " << tableName << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
		std::cerr << "\033[31m" << "Table " << tableName << " could not be deleted." << "\033[0m\n";
		return false;
	}
	return true;
}