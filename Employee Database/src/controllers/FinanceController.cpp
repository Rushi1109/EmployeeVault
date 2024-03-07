#include <iostream>
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::DBManager;

bool FinanceController::insertFinance(const Finance& e) {
	bool employeeResult = EmployeeController::insertEmployee(e);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(e.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingSoftware) VALUES (" + std::to_string(employeeID) + ", \"" + e.getAccountingSoftware() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}