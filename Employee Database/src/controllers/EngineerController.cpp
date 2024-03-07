#include <iostream>
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EngineerController;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool EngineerController::insertEngineer(const Engineer& e) {
	int departmentID = DepartmentController::selectDepartmentIDbyName("Engineer");

	if (departmentID == -1) {
		std::cerr << "Engineer department not found.";
		return false;
	}

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