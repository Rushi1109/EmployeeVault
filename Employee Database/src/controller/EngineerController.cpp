#include <iostream>
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EngineerController, EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool EngineerController::insertEngineer(Engineer& engineer) {
	int departmentID = DepartmentController::getDepartmentIDbyName("Engineer");

	if (departmentID == -1) {
		std::cerr << "Engineer department not found. Please insert a department named Engineer.\n";
		return false;
	}

	engineer.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::insertEmployee(engineer);

	if (!employeeResult) {
		std::cerr << "Engineer could not be inserted.\n";
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(engineer.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" + std::to_string(employeeID) + ", \"" + engineer.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully inserted an Engineer\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "Engineer could not be inserted.\n";
		return false;
	}
	return true;
}

bool EngineerController::selectEngineer(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Engineer " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool EngineerController::updateEngineer(Engineer& engineer) {

	bool employeeResult = EmployeeController::updateEmployee(engineer);

	if (!employeeResult) {
		std::cerr << "Engineer could not be updated.\n";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(engineer);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Engineer SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(engineer.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "Successfully updated an Engineer.\n";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "Engineer could not be updated.\n";
			return false;
		}
	}
	return true;
}

bool EngineerController::deleteEngineerByID(int ID) {
	bool deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "Successfully deleted an Engineer.\n";
	}
	else {
		std::cerr << "Engineer could not be deleted.\n";
	}
	return deleteResult;
}

std::string EngineerController::getUpdateQueryCondition(Engineer& engineer) {
	std::string updateQueryCondition{ "" };

	if (engineer.getTechnology() != "#") {
		updateQueryCondition = "technology = \"" + engineer.getTechnology() + "\"";
	}

	return updateQueryCondition;
}