#include "TableController.h"

using EmployeeDB::Controller::TableController;

bool TableController::createTable(Table& table) {

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