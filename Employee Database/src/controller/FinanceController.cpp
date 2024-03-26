#include <iostream>
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::FinanceController, EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool FinanceController::insertFinance(Finance& finance) {
	int departmentID = DepartmentController::getDepartmentIDbyName("Finance");

	if (departmentID == -1) {
		std::cerr << "Finance department not found. Please insert a department named Finance.\n";
		return false;
	}

	finance.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(finance);

	if (!employeeResult) {
		std::cerr << "Financier could not be inserted.\n";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(finance.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" + std::to_string(employeeID) + ", \"" + finance.getAccountingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully inserted a Financier.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "Financier could not be inserted.\n";
		return false;
	}
	return true;
}

bool FinanceController::selectFinance(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Finance " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool FinanceController::updateFinance(Finance& finance) {

	bool employeeResult = EmployeeController::updateEmployee(finance);

	if (!employeeResult) {
		std::cerr << "Financier could not be updated.\n";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(finance);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Finance SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(finance.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "Successfully updated a financier.\n";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "Financier could not be updated.\n";
			return false;
		}
	}
	else {
		std::cout << "Successfully updated a financier.\n";
	}
	return true;
}

bool FinanceController::deleteFinanceByID(int ID) {
	bool deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "Successfully deleted a Financier.\n";
	}
	else {
		std::cerr << "Financier could not be deleted.\n";
	}
	return deleteResult;
}

std::string FinanceController::getUpdateQueryCondition(Finance& finance) {
	std::string updateQueryCondition{ "" };

	if (finance.getAccountingTool() != "#") {
		updateQueryCondition = "accountingTool = \"" + finance.getAccountingTool() + "\"";
	}

	return updateQueryCondition;
}