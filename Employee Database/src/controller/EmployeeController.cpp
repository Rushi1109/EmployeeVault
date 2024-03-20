#include <iostream>
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EmployeeController;

bool EmployeeController::insertEmployee(const Employee& obj) {
	std::string queryString = "INSERT INTO Employee (firstName, middleName, lastName, dateOfBirth, mobileNo, email, address, gender, dateOfJoining, departmentID, mentorID, performanceMetric, bonus)"
		+ std::string{ "VALUES (" } +
		"\"" + obj.getFirstName() + "\"" + ", " +
		"\"" + obj.getMiddleName() + "\"" + ", " +
		"\"" + obj.getLastName() + "\"" + ", " +
		"\"" + obj.getDateOfBirth() + "\"" + ", " +
		std::to_string(obj.getMobileNo()) + ", " +
		"\"" + obj.getEmail() + "\"" + ", " +
		"\"" + obj.getAddress() + "\"" + ", " +
		"\"" + EmployeeDB::Model::getGenderString(obj.getGender()) + "\"" + ", " +
		"\"" + obj.getDateOfJoining() + "\"" + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getMentorID()) + ", " +
		std::to_string(obj.getPerformanceMetric()) + ", " +
		std::to_string(obj.getBonus()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool EmployeeController::deleteEmployee(int employeeID) {
	std::string queryString = "DELETE FROM Employee WHERE employeeID=" + std::to_string(employeeID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool EmployeeController::updateEmployee(Employee& obj) {

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Employee SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			return false;
		}
	}
	return true;
}

bool EmployeeController::checkEmployeeExistence(const std::string& employeeID) {
	std::string queryString = "SELECT EmployeeID FROM Employee WHERE EmployeeID = " + employeeID + ";";

	int callbackCount{ 0 };
	auto validateManagerIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* count = static_cast<int*>(data);
		(*count)++;
		return 0;
		};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), validateManagerIDCallback, &callbackCount);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	if (callbackCount == 0) {
		return false;
	}

	return true;
}

int EmployeeController::getEmployeeIDbyEmail(const std::string& email) {
	std::string queryString = "SELECT employeeID FROM Employee WHERE email=\"" + email + "\";";
	int employeeID{ -1 };

	auto getEmployeeIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eID = static_cast<int*>(data);
		if (!strcmp(*azColName, "employeeID")) {
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

int EmployeeController::getDepartmentIDbyEmployeeID(int employeeID) {
	std::string queryString = "SELECT departmentID FROM Employee WHERE employeeID = " + std::to_string(employeeID) + ";";
	int departmentID{ -1 };

	auto getDepartmentIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eID = static_cast<int*>(data);
		if (!strcmp(*azColName, "departmentID")) {
			*eID = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}
	return departmentID;
}

std::string EmployeeController::getUpdateQueryCondition(Employee& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getFirstName() != "#") {
		updateQueryCondition += "firstName = \"" + obj.getFirstName() + "\"";
	}
	if (obj.getMiddleName() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "middleName = \"" + obj.getMiddleName() + "\"";
	}
	if (obj.getLastName() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "lastName = \"" + obj.getLastName() + "\"";
	}
	if (obj.getDateOfBirth() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "dateOfBirth = \"" + obj.getDateOfBirth() + "\"";
	}
	if (obj.getMobileNo() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "mobileNo = " + std::to_string(obj.getMobileNo());
	}
	if (obj.getEmail() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "email = \"" + obj.getEmail() + "\"";
	}
	if (obj.getAddress() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "address = \"" + obj.getAddress() + "\"";
	}
	if (obj.getGender() != EmployeeDB::Model::Gender::Other) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "gender = \"" + EmployeeDB::Model::getGenderString(obj.getGender()) + "\"";
	}
	if (obj.getDateOfJoining() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "dateOfJoining = \"" + obj.getDateOfJoining() + "\"";
	}
	if (obj.getMentorID() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "mentorID = " + std::to_string(obj.getMentorID());
	}
	if (obj.getPerformanceMetric() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "performanceMetric = " + std::to_string(obj.getPerformanceMetric());
	}
	if (obj.getBonus() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "bonus = " + std::to_string(obj.getBonus());
	}

	return updateQueryCondition;
}