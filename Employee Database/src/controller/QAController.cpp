#include <iostream>
#include <exception>
#include "DBManager.h"
#include "QAController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::QAController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool QAController::insertQA(QA& qa) {
	int departmentID = DepartmentController::getDepartmentIDbyName("QA");

	if (departmentID == -1) {
		std::cerr << "QA department not found. Please insert a department named QA.\n";
		return false;
	}

	qa.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(qa);

	if (!employeeResult) {
		std::cerr << "QA could not be inserted.\n";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(qa.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + qa.getTestingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully inserted a QA.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "QA could not be inserted.\n";
		return false;
	}
	return true;
}

bool QAController::selectQA(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool QAController::updateQA(QA& qa) {

	bool employeeResult = EmployeeController::updateEmployee(qa);

	if (!employeeResult) {
		std::cerr << "QA could not be updated.\n";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(qa);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE QA SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(qa.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "Successfully updated a QA.\n";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "QA could not be updated.\n";
			return false;
		}
	}
	else {
		std::cout << "Successfully updated a QA.\n";
	}
	return true;
}

bool QAController::deleteQAByID(int ID) {
	int deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "Successfully deleted a QA.\n";
	}
	else {
		std::cerr << "QA could not be deleted.\n";
	}
	return deleteResult;
}

std::string QAController::getUpdateQueryCondition(QA& qa) {
	std::string updateQueryCondition{ "" };

	if (qa.getTestingTool() != "#") {
		updateQueryCondition = "testingTool = \"" + qa.getTestingTool() + "\"";
	}

	return updateQueryCondition;
}