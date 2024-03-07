#include <iostream>
#include <exception>
#include "DBManager.h"
#include "QAController.h"
#include "EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::QAController;
using EmployeeDB::DBManager;

bool QAController::insertQA(const QA& obj) {
	bool employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\" " + obj.getTestingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}