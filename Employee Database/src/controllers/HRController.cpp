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

bool HRController::insertHR(HR& e) {
	int departmentID = DepartmentController::selectDepartmentIDbyName("HR");

	if (departmentID == -1) {
		std::cerr << "HR department not found.";
		return false;
	}

	e.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(e);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(e.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + e.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool HRController::selectAllHR() {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN HR;";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}