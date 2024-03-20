#include <iostream>
#include <exception>
#include "DBManager.h"
#include "HRController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::HRController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool HRController::insertHR(HR& obj) {
	int departmentID = DepartmentController::getDepartmentIDbyName("HR");

	if (departmentID == -1) {
		std::cerr << "HR department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool HRController::selectHR(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN HR " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		int rowCount = DBManager::instance().executeSelectQuery(queryString.c_str());
		std::cout << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found < ----------\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool HRController::updateHR(HR& obj) {

	bool employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE HR SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

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

bool HRController::deleteHRByID(int ID) {
	return EmployeeController::deleteEmployee(ID);
}

std::string HRController::getUpdateQueryCondition(HR& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getHRSpecialization() != "#") {
		updateQueryCondition = "hrSpecialization = \"" + obj.getHRSpecialization() + "\"";
	}

	return updateQueryCondition;
}