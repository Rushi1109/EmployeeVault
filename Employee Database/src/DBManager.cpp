#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "DBLogger.h"
#include "DBManager.h"
#include "Config.h"
#include "exception"
#include "Salary.h"
#include "EmployeeController.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::Salary;
using EmployeeDB::Controller::EmployeeController;

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
	resultCode = sqlite3_open(EmployeeDB::Config::dbFilePath.string().c_str(), &db);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", "Opened database file");
	}
	else {
		DBLogger::logger.error("Failed : ", sqlite3_errmsg(db));
		throw std::runtime_error(sqlite3_errmsg(db));
	}
}

void DBManager::closeConnection() {
	resultCode = sqlite3_close(db);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", "Closed database file");
	}
	else {
		DBLogger::logger.error("Failed : ", sqlite3_errmsg(db));
		throw std::runtime_error(sqlite3_errmsg(db));
	}
}

int DBManager::executeQuery(const char* queryString) {
	resultCode = sqlite3_exec(db, queryString, 0, 0, &errMsg);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", queryString);
	}
	else {
		DBLogger::logger.error("Failed : ", queryString);
		throw std::runtime_error{ errMsg };
	}

	return resultCode;
}

int DBManager::selectCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;

	std::cout << "|--------------------|----------------------------------------|\n";
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	}
	std::cout << "|--------------------|----------------------------------------|\n";
	std::cout << std::endl;
	return 0;
}

int DBManager::executeSelectQuery(const char* queryString) {
	int rowCount{ 0 };
	resultCode = sqlite3_exec(db, queryString, selectCallback, &rowCount, &errMsg);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", queryString);
	}
	else {
		DBLogger::logger.error("Failed : ", queryString);
		throw std::runtime_error{ errMsg };
	}

	return rowCount;
}

int DBManager::selectSalaryCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;

	Salary obj;

	std::cout << "|--------------------|----------------------------------------|\n";
	int i;
	for (i = 0; i < argc; i++) {
		if (!strcmp(azColName[i], "employeeID")) {
			obj.setEmployeeID(std::stoi(argv[i]));
		}
		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	}
	EmployeeController::getSalaryDetails(obj);
	double totalSalary = obj.computeSalary();
	std::cout << "|" << std::setw(20) << std::left << "Total Salary" << "|" << std::setw(40) << std::left << totalSalary << "|\n";
	std::cout << "|--------------------|----------------------------------------|\n";
	std::cout << std::endl;
	return 0;
}

int DBManager::executeSelectSalaryQuery(const char* queryString) {
	int rowCount{ 0 };
	resultCode = sqlite3_exec(db, queryString, selectSalaryCallback, &rowCount, &errMsg);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", queryString);
	}
	else {
		DBLogger::logger.error("Failed : ", queryString);
		throw std::runtime_error{ errMsg };
	}
	return rowCount;
}

int DBManager::executeCustomQuery(const char* queryString, int (*callback)(void*, int, char**, char**), void* arg) {
	resultCode = sqlite3_exec(db, queryString, callback, arg, &errMsg);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", queryString);
	}
	else {
		DBLogger::logger.error("Failed : ", queryString);
		throw std::runtime_error{ errMsg };
	}

	return resultCode;
}

int DBManager::executeRowCountQuery(const char* queryString) {
	int rowCount{ 0 };
	resultCode = sqlite3_exec(db, queryString, rowCountCallback, &rowCount, &errMsg);

	if (resultCode == SQLITE_OK) {
		DBLogger::logger.info("Success : ", queryString);
	}
	else {
		DBLogger::logger.error("Failed : ", queryString);
		throw std::runtime_error{ errMsg };
	}
	return rowCount;
}

int DBManager::rowCountCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;
	return 0;
}

void DBManager::executeConfigQuery() {
	std::string queryString = "PRAGMA foreign_keys = ON";

	try {
		instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}