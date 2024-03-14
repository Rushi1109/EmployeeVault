#include <iostream>
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool FinanceController::insertFinance(Finance& obj) {
	int departmentID = DepartmentController::selectDepartmentIDbyName("Finance");

	if (departmentID == -1) {
		std::cerr << "Finance department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" + std::to_string(employeeID) + ", \"" + obj.getAccountingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool FinanceController::selectFinance(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Finance " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool FinanceController::updateFinance(Finance& obj) {

	bool employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Finance SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

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

std::string FinanceController::getUpdateQueryCondition(Finance& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getAccountingTool() != "#") {
		updateQueryCondition = "accountingTool = \"" + obj.getAccountingTool() + "\"";
	}

	return updateQueryCondition;
}