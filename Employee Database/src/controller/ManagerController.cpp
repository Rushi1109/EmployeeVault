#include <iostream>
#include "ManagerController.h"
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController, EmployeeDB::Controller::EmployeeController;
using EmployeeDB::DBManager;

bool ManagerController::insertManager(Manager& obj) {
	int departmentID = EmployeeController::getDepartmentIDbyEmployeeID(obj.getManagerID());

	if (departmentID == -1) {
		std::cerr << "Department could not be found for provided employeeID";
		return false;
	}

	obj.setDepartmentID(departmentID);

	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, role) VALUES (" +
		std::to_string(obj.getManagerID()) + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getTeamSize()) + ", " +
		std::to_string(obj.getYearsOfExperience()) + ", " +
		"\"" + obj.getProjectTitle() + "\", " +
		"\"" + obj.getRole() + "\");";

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
		int rowCount = DBManager::instance().executeSelectQuery(queryString.c_str());
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
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

bool ManagerController::updateManager(Manager& obj) {
	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Manager SET " + updateQueryCondition + " WHERE managerID = " + std::to_string(obj.getManagerID()) + ";";

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

std::string ManagerController::getUpdateQueryCondition(Manager& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getTeamSize() != -1) {
		updateQueryCondition += "teamSize = " + std::to_string(obj.getTeamSize());
	}
	if (obj.getYearsOfExperience() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "yearsOfExp = " + std::to_string(obj.getYearsOfExperience());
	}
	if (obj.getProjectTitle() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "projectTitle = \"" + obj.getProjectTitle() + "\"";
	}
	if (obj.getRole() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "role = \"" + obj.getRole() + "\"";
	}

	return updateQueryCondition;
}