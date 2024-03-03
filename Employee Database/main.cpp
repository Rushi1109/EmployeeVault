#include <iostream>
#include "sqlite3.h"

int main() {
	sqlite3* db;
	int status = 0;
	char* errMsg = 0;

	status = sqlite3_open("./data/Employee.db", &db);

	if (status) {
		std::cerr << "Error creating DB file" << sqlite3_errmsg(db) << '\n';
		return -1;
	}
	else {
		std::cout << "Created database file successfully" << '\n';
	}

	const char* createTableSQL = "CREATE TABLE IF NOT EXISTS Employee ("
		"ID INT PRIMARY KEY NOT NULL,"
		"Name TEXT NOT NULL,"
		"Age INT NOT NULL,"
		"Salary REAL NOT NULL);";

	status = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

	if (status != SQLITE_OK) {
		std::cerr << "Cannot create Employee table: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else {
		std::cout << "Employee table created successfully." << std::endl;
	}

	const char* insertDataSQL = "INSERT INTO Employee (ID,Name,Age,Salary)"
								"VALUES (16, 'Paul', 32, 20000.00 );"
								"INSERT INTO Employee "
								"VALUES (140, 'Paolo', 26, 2222000.00);";

	status = sqlite3_exec(db, insertDataSQL, 0, 0, &errMsg);

	if (status != SQLITE_OK) {
		std::cerr << "Cannot insert Employee record: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else {
		std::cout << "Employee record inserted successfully." << std::endl;
	}

	sqlite3_close(db);
	return 0;
}