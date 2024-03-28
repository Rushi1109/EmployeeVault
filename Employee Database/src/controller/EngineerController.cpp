#include <iostream>
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EngineerController, EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool EngineerController::insertEngineer(Engineer& engineer) {
	auto departmentID = DepartmentController::getDepartmentIDbyName("Engineer");

	if (departmentID == -1) {
		std::cerr << "\033[0;31m" << "Engineer department not found.Please insert a department named Engineer.\n" << "\033[0m";
		return false;
	}

	engineer.setDepartmentID(departmentID);

	auto employeeResult = EmployeeController::insertEmployee(engineer);

	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "Engineer could not be inserted.\n" << "\033[0m";
		return false;
	}

	auto employeeID = EmployeeController::getEmployeeIDbyEmail(engineer.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" + std::to_string(employeeID) + ", \"" + engineer.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully inserted an Engineer.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "Engineer could not be inserted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool EngineerController::selectEngineer(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Engineer " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool EngineerController::updateEngineer(Engineer& engineer) {

	auto employeeResult = EmployeeController::updateEmployee(engineer);
	
	if (!employeeResult) {
		std::cerr << "\033[0;31m" << "Engineer could not be updated.\n" << "\033[0m";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(engineer);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Engineer SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(engineer.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\033[0;32m" << "Successfully updated an Engineer.\n" << "\033[0m";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "\033[0;31m" << "Engineer could not be updated.\n" << "\033[0m";
			return false;
		}
	}
	else{
		std::cout << "\033[0;32m" << "Successfully updated an Engineer.\n" << "\033[0m";
	}
	return true;
}

bool EngineerController::deleteEngineerByID(int ID) {
	auto deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\033[0;32m" << "Successfully deleted an Engineer.\n" << "\033[0m";
	}
	else {
		std::cerr << "\033[0;31m" << "Engineer could not be deleted.\n" << "\033[0m";
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