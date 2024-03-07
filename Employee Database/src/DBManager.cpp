#include "DBManager.h"
#include "Config.h"
#include "exception"
#include <iostream>

using EmployeeDB::DBManager;

DBManager& DBManager::instance() {
	static DBManager DB;
	return DB;
}

DBManager::DBManager() {
	openConnection();
}

DBManager::~DBManager() {
	closeConnection();
}

void DBManager::openConnection() {
	resultCode = sqlite3_open(EmployeeDB::Config::dbFilePath, &db);

	if (resultCode != SQLITE_OK) {
		throw std::runtime_error(sqlite3_errmsg(db));
	}
	else {
		std::cout << "Opened database file successfully" << '\n';
	}
}

void DBManager::closeConnection() {
	resultCode = sqlite3_close(db);

	if (resultCode != SQLITE_OK) {
		throw std::runtime_error(sqlite3_errmsg(db));
	}
	else {
		std::cout << "Closed database file successfully" << '\n';
	}
}

int DBManager::executeQuery(const char* queryString) {
	resultCode = sqlite3_exec(db, queryString, 0, 0, &errMsg);

	if (resultCode == SQLITE_OK) {
		std::cout << "Successfully executed Query" << '\n';
	}
	else {
		throw std::runtime_error{ errMsg };
	}

	return resultCode;
}

int DBManager::callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		resultString += azColName[i] + std::string{ " : " } + (argv[i] ? argv[i] : "NULL") + "\n";
	}
	std::cout << '\n';
	return 0;
}

int DBManager::executeSelectQuery(const char* queryString, int (*callback)(void*, int, char**, char**), void* arg) {
	resultCode = sqlite3_exec(db, queryString, callback, arg, &errMsg);

	if (resultCode == SQLITE_OK) {
		std::cout << "Successfully executed Query" << '\n';
	}
	else {
		throw std::runtime_error{ errMsg };
	}

	return resultCode;
}