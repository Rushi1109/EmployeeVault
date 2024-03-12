#include <iostream>
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool FinanceController::insertFinance(Finance& e) {
	int departmentID = DepartmentController::selectDepartmentIDbyName("Finance");

	if (departmentID == -1) {
		std::cerr << "Finance department not found.";
		return false;
	}

	e.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(e);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(e.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" + std::to_string(employeeID) + ", \"" + e.getAccountingSoftware() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool FinanceController::selectAllFinance() {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Finance;";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}