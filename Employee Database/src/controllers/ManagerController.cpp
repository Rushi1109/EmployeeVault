#include <iostream>
#include "ManagerController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::DBManager;

bool ManagerController::insertManager(Manager& manager) {
	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, technology) VALUES (" +
		std::to_string(manager.getManagerID()) + ", " +
		std::to_string(manager.getDepartmentID()) + ", " +
		std::to_string(manager.getTeamSize()) + ", " +
		std::to_string(manager.getYearsOfExperience()) + ", " +
		"\"" + manager.getProjectTitle() + "\", " +
		"\"" + manager.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool ManagerController::selectAllManager() {
	std::string queryString = "SELECT * FROM ManagerView;";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}