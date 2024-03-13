#include <iostream>
#include <exception>
#include "DBManager.h"
#include "QAController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::QAController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool QAController::insertQA(QA& e) {
	int departmentID = DepartmentController::selectDepartmentIDbyName("QA");

	if (departmentID == -1) {
		std::cerr << "QA department not found.";
		return false;
	}

	e.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(e);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(e.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + e.getTestingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool QAController::selectQA(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";;

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}