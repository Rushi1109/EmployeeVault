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
		std::cerr << "\033[0;31m" << "HR department not found. Please insert a department named HR.\n" << "\033[0m";
		return false;
	}

	hr.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(hr);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "HR could not be inserted.\n" << "\033[0m";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(hr.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + hr.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully inserted an HR.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "HR could not be inserted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool HRController::selectHR(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN HR " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

	try {
		int rowCount = DBManager::instance().executeSelectSalaryQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found <----------\n" << "\033[0m";
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
		std::cerr << "\033[0;31m" << "HR could not be updated.\n" << "\033[0m";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(hr);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE HR SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(hr.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\033[0;32m" << "Successfully updated an HR.\n" << "\033[0m";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "\033[0;31m" << "HR could not be updated.\n" << "\033[0m";
			return false;
		}
	}
	else {
		std::cout << "\033[0;31m" << "Successfully updated an HR.\n" << "\033[0m";
	}
	return true;
}

bool HRController::deleteHRByID(int ID) {
	int deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\033[0;32m" << "Successfully deleted an HR.\n" << "\033[0m";
	}
	else {
		std::cerr << "\033[0;31m" << "HR could not be deleted.\n" << "\033[0m";
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