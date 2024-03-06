#include <iostream>
#include "./include/DBManager.h"

using EmployeeDB::DBManager;

int main() {
	DBManager& db = DBManager::instance();

	const char* createTableSQL = "CREATE TABLE IF NOT EXISTS Company ("
		"ID INT PRIMARY KEY NOT NULL,"
		"Name TEXT NOT NULL,"
		"Age INT NOT NULL,"
		"Salary REAL NOT NULL);";

	db.executeQuery(createTableSQL);

	/*const char* insertDataSQL = "INSERT INTO Company (ID,Name,Age,Salary)"
								"VALUES (16, 'Paul', 32, 20000.00 );"
								"INSERT INTO Company "
								"VALUES (140, 'Paolo', 26, 2222000.00);";

	db.executeQuery(insertDataSQL);*/
	
	const char* selectSQL = "SELECT * FROM Company";

	db.executeSelectQuery(selectSQL);

	std::cout << db.getResultString() << '\n';

	return 0;
}