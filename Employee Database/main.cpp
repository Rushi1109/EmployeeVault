#include <iostream>
#include "sqlite3.h"

int main() {
	sqlite3* db;
	int status = 0;

	status = sqlite3_open("Employee.db", &db);

	if (status) {
		std::cerr << "Error creating DB file" << sqlite3_errmsg(db) << '\n';
		return -1;
	}
	else {
		std::cout << "Created database file successfully" << '\n';
	}

	sqlite3_close(db);
	return 0;
}