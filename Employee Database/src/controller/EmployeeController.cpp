#include <iostream>
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::DepartmentController;

bool EmployeeController::insertEmployee(const Employee& employee) {
	std::string queryString = "INSERT INTO Employee (firstName, middleName, lastName, dateOfBirth, mobileNo, email, address, gender, dateOfJoining, departmentID, mentorID, performanceMetric, bonus)"
		+ std::string{ "VALUES (" } +
		"\"" + employee.getFirstName() + "\"" + ", " +
		(employee.getMiddleName().size() == 0 ? "NULL" : "\"" + employee.getMiddleName() + "\"") + ", " +
		"\"" + employee.getLastName() + "\"" + ", " +
		(employee.getDateOfBirth().size() == 0 ? "NULL" : "\"" + employee.getDateOfBirth() + "\"") + ", " + 
		std::to_string(employee.getMobileNo()) + ", " +
		"\"" + employee.getEmail() + "\"" + ", " +
		"\"" + employee.getAddress() + "\"" + ", " +
		"\"" + EmployeeDB::Model::getGenderString(employee.getGender()) + "\"" + ", " +
		"\"" + employee.getDateOfJoining() + "\"" + ", " +
		std::to_string(employee.getDepartmentID()) + ", " +
		(employee.getMentorID() == 0 ? "NULL" : std::to_string(employee.getMentorID())) + ", " +
		(employee.getPerformanceMetric() == 0.0 ? "NULL" : std::to_string(employee.getPerformanceMetric())) + ", " +
		(employee.getBonus() == 0.0 ? "NULL" : std::to_string(employee.getBonus())) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool EmployeeController::deleteEmployeeByID(int employeeID) {
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

bool EmployeeController::updateEmployee(Employee& employee) {

	std::string updateQueryCondition = getUpdateQueryCondition(employee);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Employee SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(employee.getEmployeeID()) + ";";

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

bool EmployeeController::checkEmployeeExistence(const std::string& employeeID, const std::string& departmentName) {
	int departmentID{ -1 };

	if (departmentName != "*") {
		departmentID = DepartmentController::getDepartmentIDbyName(departmentName);
		if (departmentID == -1) {
			return false;
		}
	}

	std::string queryString = "SELECT employeeID FROM Employee WHERE employeeID = " + employeeID + (departmentID == -1 ? "" : " AND departmentID = " + std::to_string(departmentID)) + ";";

	int callbackCount{ 0 };

	try {
		callbackCount = DBManager::instance().executeRowCountQuery(queryString.c_str());
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
	std::string queryString = "SELECT employeeID FROM Employee WHERE email=\"" + email + "\" COLLATE NOCASE;";
	int employeeID{ -1 };

	auto getEmployeeIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eID = static_cast<int*>(data);
		if (!strcmp(*azColName, "employeeID")) {
			*eID = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeCustomQuery(queryString.c_str(), getEmployeeIDCallback, &employeeID);
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
		DBManager::instance().executeCustomQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}
	return departmentID;
}

std::string EmployeeController::getUpdateQueryCondition(Employee& employee) {
	std::string updateQueryCondition{ "" };

	if (employee.getFirstName() != "#") {
		updateQueryCondition += "firstName = \"" + employee.getFirstName() + "\"";
	}
	if (employee.getMiddleName() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "middleName = \"" + employee.getMiddleName() + "\"";
	}
	if (employee.getLastName() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "lastName = \"" + employee.getLastName() + "\"";
	}
	if (employee.getDateOfBirth() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "dateOfBirth = \"" + employee.getDateOfBirth() + "\"";
	}
	if (employee.getMobileNo() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "mobileNo = " + std::to_string(employee.getMobileNo());
	}
	if (employee.getEmail() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "email = \"" + employee.getEmail() + "\"";
	}
	if (employee.getAddress() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "address = \"" + employee.getAddress() + "\"";
	}
	if (employee.getGender() != EmployeeDB::Model::Gender::Other) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "gender = \"" + EmployeeDB::Model::getGenderString(employee.getGender()) + "\"";
	}
	if (employee.getDateOfJoining() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "dateOfJoining = \"" + employee.getDateOfJoining() + "\"";
	}
	if (employee.getMentorID() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "mentorID = " + std::to_string(employee.getMentorID());
	}
	if (employee.getPerformanceMetric() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "performanceMetric = " + std::to_string(employee.getPerformanceMetric());
	}
	if (employee.getBonus() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "bonus = " + std::to_string(employee.getBonus());
	}

	return updateQueryCondition;
}

bool EmployeeController::getSalaryDetails(Salary& salary) {
	std::string queryString = "SELECT * FROM SalaryView WHERE employeeID = " + std::to_string(salary.getEmployeeID()) + ";";

	auto getSalaryDetailsCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		Salary* salaryObj = static_cast<Salary*>(data);

		salaryObj->setDepartmentID((argv[1] ? std::stoi(argv[1]) : 0));
		salaryObj->setPerformanceMetric((argv[2] ? std::stod(argv[2]) : 0.0));
		salaryObj->setBonus((argv[3] ? std::stod(argv[3]) : 0.0));
		salaryObj->setBaseSalary((argv[4] ? std::stod(argv[4]) : 0.0));
		salaryObj->setAllowance((argv[5] ? std::stod(argv[5]) : 0.0));
		salaryObj->setDeduction((argv[6] ? std::stod(argv[6]) : 0.0));
		return 0;
		};

	try {
		DBManager::instance().executeCustomQuery(queryString.c_str(), getSalaryDetailsCallback, &salary);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}