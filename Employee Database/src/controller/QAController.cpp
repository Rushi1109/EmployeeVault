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

bool QAController::insertQA(QA& obj) {
	int departmentID = DepartmentController::getDepartmentIDbyName("QA");

	if (departmentID == -1) {
		std::cerr << "QA department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getTestingTool() + "\");";

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
		int rowCount = DBManager::instance().executeSelectQuery(queryString.c_str());
		std::cout << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found < ----------\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool QAController::updateQA(QA& obj) {

	bool employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE QA SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

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

bool QAController::deleteQAByID(int ID) {
	return EmployeeController::deleteEmployee(ID);
}

std::string QAController::getUpdateQueryCondition(QA& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getTestingTool() != "#") {
		updateQueryCondition = "testingTool = \"" + obj.getTestingTool() + "\"";
	}

	return updateQueryCondition;
}