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
		std::cerr << "\033[0;31m" << "Finance department not found. Please insert a department named Finance.\n" << "\033[0m";
		return false;
	}

	finance.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(finance);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "Financier could not be inserted.\n" << "\033[0m";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(finance.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" + std::to_string(employeeID) + ", \"" + finance.getAccountingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully inserted a Financier.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "Financier could not be inserted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool FinanceController::selectFinance(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Finance " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool FinanceController::updateFinance(Finance& finance) {

	bool employeeResult = EmployeeController::updateEmployee(finance);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "Financier could not be updated.\n" << "\033[0m";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(finance);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Finance SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(finance.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\033[0;32m" << "Successfully updated a financier.\n" << "\033[0m";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "\033[0;31m" << "Financier could not be updated.\n" << "\033[0m";
			return false;
		}
	}
	else {
		std::cout << "\033[0;32m" << "Successfully updated a financier.\n" << "\033[0m";
	}
	return true;
}

bool FinanceController::deleteFinanceByID(int ID) {
	bool deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\033[0;32m" << "Successfully deleted a Financier.\n" << "\033[0m";
	}
	else {
		std::cerr << "\033[0;31m" << "Financier could not be deleted.\n" << "\033[0m";
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