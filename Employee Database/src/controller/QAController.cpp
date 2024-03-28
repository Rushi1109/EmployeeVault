#include <iostream>
#include <exception>
#include "DBManager.h"
#include "QAController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::QAController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool QAController::insertQA(QA& qa) {
	auto departmentID = DepartmentController::getDepartmentIDbyName("QA");

	if (departmentID == -1) {
		std::cerr << "\033[0;31m" << "QA department not found. Please insert a department named QA.\n" << "\033[0m";
		return false;
	}

	qa.setDepartmentID(departmentID);

	auto employeeResult = EmployeeController::insertEmployee(qa);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "QA could not be inserted.\n" << "\033[0m";
		return false;
	}

	auto employeeID = EmployeeController::getEmployeeIDbyEmail(qa.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + qa.getTestingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully inserted a QA.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "QA could not be inserted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool QAController::selectQA(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

	try {
		auto rowCount = DBManager::instance().executeSelectSalaryQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found <----------\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool QAController::updateQA(QA& qa) {

	auto employeeResult = EmployeeController::updateEmployee(qa);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "QA could not be updated.\n" << "\033[0m";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(qa);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE QA SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(qa.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\033[0;32m" << "Successfully updated a QA.\n" << "\033[0m";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "\033[0;31m" << "QA could not be updated.\n" << "\033[0m";
			return false;
		}
	}
	else {
		std::cout << "\033[0;32m" << "Successfully updated a QA.\n" << "\033[0m";
	}
	return true;
}

bool QAController::deleteQAByID(int ID) {
	auto deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\033[0;32m" << "Successfully deleted a QA.\n" << "\033[0m";
	}
	else {
		std::cerr << "\033[0;31m" << "QA could not be deleted.\n" << "\033[0m";
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