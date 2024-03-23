#include <iostream>
#include "ManagerController.h"
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController, EmployeeDB::Controller::EmployeeController;
using EmployeeDB::DBManager;

bool ManagerController::insertManager(Manager& manager) {
	int departmentID = EmployeeController::getDepartmentIDbyEmployeeID(manager.getManagerID());

	if (departmentID == -1) {
		std::cerr << "Department could not be found for provided employeeID";
		return false;
	}

	manager.setDepartmentID(departmentID);

	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, role) VALUES (" +
		std::to_string(manager.getManagerID()) + ", " +
		std::to_string(manager.getDepartmentID()) + ", " +
		std::to_string(manager.getTeamSize()) + ", " +
		std::to_string(manager.getYearsOfExperience()) + ", " +
		(manager.getProjectTitle().size() == 0 ? "NULL" : "\"" + manager.getProjectTitle() + "\"") + "," +
		(manager.getRole().size() == 0 ? "NULL" : "\"" + manager.getRole() + "\"") + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully inserted a Manager.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "Manager could not be inserted.\n";
		return false;
	}
	return true;
}

bool ManagerController::selectManager(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM ManagerView " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

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

bool ManagerController::deleteManagerByID(int ID) {
	std::string queryString = "DELETE FROM Manager WHERE managerID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "Successfully deleted a Manager.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "Manager could not be deleted.\n";
		return false;
	}
	return true;
};

bool ManagerController::updateManager(Manager& manager) {
	bool employeeResult = EmployeeController::updateEmployee(manager);

	if (!employeeResult) {
		std::cerr << "Manager could not be updated.\n";
		return false;
	}

	std::string updateQueryCondition = getUpdateQueryCondition(manager);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Manager SET " + updateQueryCondition + " WHERE managerID = " + std::to_string(manager.getManagerID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cerr << "Successfully updated a Manager.\n";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "Manager could not be updated.\n";
			return false;
		}
	}
	return true;
}

std::string ManagerController::getUpdateQueryCondition(Manager& manager) {
	std::string updateQueryCondition{ "" };

	if (manager.getTeamSize() != -1) {
		updateQueryCondition += "teamSize = " + std::to_string(manager.getTeamSize());
	}
	if (manager.getYearsOfExperience() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "yearsOfExp = " + std::to_string(manager.getYearsOfExperience());
	}
	if (manager.getProjectTitle() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "projectTitle = \"" + manager.getProjectTitle() + "\"";
	}
	if (manager.getRole() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "role = \"" + manager.getRole() + "\"";
	}

	return updateQueryCondition;
}

bool ManagerController::checkManagerExistence(const std::string& managerID) {
	std::string queryString = "SELECT managerID FROM Manager WHERE managerID = " + managerID + ";";

	int callbackCount{ 0 };

	try {
		callbackCount = DBManager::instance().executeRowCountQuery(queryString.c_str());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	if (callbackCount == 0) {
		return false;
	}

	return true;
}