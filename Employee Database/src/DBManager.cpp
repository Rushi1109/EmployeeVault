#include "../include/DBManager.h"
#include "../include/Config.h"
#include "exception"
#include <iostream>

using EmployeeDB::Database;

Database& Database::instance() {
	static Database DB;
	return DB;
}

void Database::openConnection() {
	status = sqlite3_open(EmployeeDB::Config::dbFilePath, &db);

	if (status != SQLITE_OK) {
		throw std::runtime_error(sqlite3_errmsg(db));
	}
	else {
		std::cout << "Opened database file successfully" << '\n';
	}
}

void Database::closeConnection() {
	status = sqlite3_close(db);

	if (status != SQLITE_OK) {
		throw std::runtime_error(sqlite3_errmsg(db));
	}
	else {
		std::cout << "Closed database file successfully" << '\n';
	}
}

int Database::execute(const char* sql) {
	
};


Database::Database() {
	openConnection();
}

Database::~Database() {
	closeConnection();
}