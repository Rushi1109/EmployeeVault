#include "../include/DBManager.h"
#include <iostream>

Database& Database::instance() {
	static Database DB;
	return DB;
}

void Database::openConnection() {
	status = sqlite3_open("./data/Employee.db", &db);

	if (status) {
		std::cerr << "Error creating DB file" << sqlite3_errmsg(db) << '\n';
	}
	else {
		std::cout << "Created database file successfully" << '\n';
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