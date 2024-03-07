#include <iostream>
#include <exception>
#include "DBManager.h"
#include "HRController.h"
#include "EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::HRController;
using EmployeeDB::DBManager;

bool HRController::insertHR(const HR& obj) {
	bool employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\" " + obj.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}