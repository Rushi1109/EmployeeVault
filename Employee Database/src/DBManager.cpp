#include "../include/DBManager.h"
#include "../include/Config.h"
#include <iostream>

using EmployeeDB::Database;

Database& Database::instance() {
	static Database DB;
	return DB;
}

void Database::openConnection() {
	status = sqlite3_open(EmployeeDB::Config::dbFilePath, &db);

	if (status != SQLITE_OK) {
		std::cerr << "Error opening DB file" << sqlite3_errmsg(db) << '\n';
	}
	else {
		std::cout << "Opened database file successfully" << '\n';
	}
}

void Database::closeConnection() {
	sqlite3_close(db);
}

Database::Database() {
	openConnection();
}

Database::~Database() {
	closeConnection();
}