#include <iostream>
#include <exception>
#include "DBManager.h"
#include "HRController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::HRController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool HRController::insertHR(HR& hr) {
	int departmentID = DepartmentController::getDepartmentIDbyName("HR");

	if (departmentID == -1) {
		std::cerr << "HR department not found. Please insert a department named HR.\n";
		return false;
	}

	hr.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(hr);

	if (!employeeResult) {
		std::cerr << "HR could not be inserted";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(hr.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + hr.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully inserted an HR.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "HR could not be inserted.\n";
		return false;
	}
	return true;
}

bool HRController::selectHR(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN HR " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

	try {
		int rowCount = DBManager::instance().executeSelectSalaryQuery(queryString.c_str());
		std::cout << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found < ----------\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool HRController::updateHR(HR& hr) {

	bool employeeResult = EmployeeController::updateEmployee(hr);

	if (!employeeResult) {
		std::cerr << "HR could not be updated.\n";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(hr);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE HR SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(hr.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "Successfully updated an HR.\n";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "HR could not be updated.\n";
			return false;
		}
	}
	else {
		std::cout << "Successfully updated an HR.\n";
	}
	return true;
}

bool HRController::deleteHRByID(int ID) {
	int deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "Successfully deleted an HR.\n";
	}
	else {
		std::cerr << "HR could not be deleted.\n";
	}
	return deleteResult;
}

std::string HRController::getUpdateQueryCondition(HR& hr) {
	std::string updateQueryCondition{ "" };

	if (hr.getHRSpecialization() != "#") {
		updateQueryCondition = "hrSpecialization = \"" + hr.getHRSpecialization() + "\"";
	}

	return updateQueryCondition;
}