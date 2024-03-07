#include <iostream>
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EmployeeController;

bool EmployeeController::insertEmployee(const Employee& e) {
	std::string queryString = "INSERT INTO Employee (firstName, middleName, lastName, dateOfBirth, mobileNo, email, address, gender, dateOfJoining, departmentID, managerID, performanceMetric, bonus)"
		+ std::string{ "VALUES (" } +
		"\"" + e.getFirstName() + "\"" + ", " +
		"\"" + e.getMiddleName() + "\"" + ", " +
		"\"" + e.getLastName() + "\"" + ", " +
		"\"" + e.getDateOfBirth() + "\"" + ", " +
		std::to_string(e.getMobileNo()) + ", " +
		"\"" + e.getEmail() + "\"" + ", " +
		"\"" + e.getAddress() + "\"" + ", " +
		"\"" + EmployeeDB::Model::getGenderString(e.getGender()) + "\"" + ", " +
		"\"" + e.getDateOfJoining() + "\"" + ", " +
		std::to_string(e.getDepartmentID()) + ", " +
		std::to_string(e.getManagerID()) + ", " +
		std::to_string(e.getPerformanceMetric()) + ", " +
		std::to_string(e.getBonus()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

int EmployeeController::selectEmployeeIDbyEmail(const std::string& email) {
	std::string queryString = "SELECT employeeID FROM Employee WHERE email=\"" + email + "\";";
	int employeeID{ 0 };

	auto getEmployeeIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eID = static_cast<int*>(data);
		if (!strcmp(*azColName,"employeeID")) {
			*eID = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), getEmployeeIDCallback, &employeeID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return employeeID;
}