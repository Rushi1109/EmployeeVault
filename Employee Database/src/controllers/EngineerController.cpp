#include <iostream>
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EngineerController;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::DBManager;

bool EngineerController::insertEngineer(const Engineer& e) {
	bool employeeResult = EmployeeController::insertEmployee(e);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(e.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" + std::to_string(employeeID) + ", \"" + e.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}