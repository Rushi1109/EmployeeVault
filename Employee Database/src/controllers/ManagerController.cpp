#include <iostream>
#include "ManagerController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::DBManager;

bool ManagerController::insertManager(Manager& manager) {
	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, role) VALUES (" +
		std::to_string(manager.getManagerID()) + ", " +
		std::to_string(manager.getDepartmentID()) + ", " +
		std::to_string(manager.getTeamSize()) + ", " +
		std::to_string(manager.getYearsOfExperience()) + ", " +
		"\"" + manager.getProjectTitle() + "\", " +
		"\"" + manager.getRole() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool ManagerController::selectManager(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM ManagerView " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool ManagerController::deleteManager(int ID) {
	std::string queryString = "DELETE FROM Manager WHERE managerID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};
