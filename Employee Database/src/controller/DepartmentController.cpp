#include <iostream>
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool DepartmentController::insertDepartment(const Department& d) {
	std::string queryString = "INSERT INTO Department (departmentName, baseSalary, allowance, deduction)"
		+ std::string{ "VALUES (" } +
		"\"" + d.getDepartmentName() + "\"" + ", " +
		std::to_string(d.getBaseSalary()) + ","+
		std::to_string(d.getAllowance()) + ","+
		std::to_string(d.getDeduction()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool DepartmentController::deleteDepartment(int departmentID) {
	std::string queryString = "DELETE FROM Department WHERE departmentID=" + std::to_string(departmentID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool DepartmentController::selectDepartment(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Department " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

int DepartmentController::selectDepartmentIDbyName(const std::string& departmentName) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentName=\"" + departmentName + "\";";
	int departmentID{ -1 };

	auto getDepartmentIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* dID = static_cast<int*>(data);
		if (!strcmp(*azColName, "departmentID")) {
			*dID = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return departmentID;
}

bool DepartmentController::selectAllDepartmentIDAndName() {
	std::string queryString = "SELECT departmentID,departmentName FROM Department ORDER BY departmentID";

	try {
		int i = 0;
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}

	return true;
}

bool DepartmentController::updateDepartment(Department& obj) {
	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Department SET " + updateQueryCondition + " WHERE departmentID = " + std::to_string(obj.getDepartmentID()) + ";";

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

std::string DepartmentController::getUpdateQueryCondition(Department& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getDepartmentName() != "#") {
		updateQueryCondition += "departmentName = \"" + obj.getDepartmentName() + "\"";
	}
	if (obj.getBaseSalary() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "baseSalary = " + std::to_string(obj.getBaseSalary());
	}
	if (obj.getAllowance() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "allowance = " + std::to_string(obj.getAllowance());
	}
	if (obj.getDeduction() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "deduction = " + std::to_string(obj.getDeduction());
	}

	return updateQueryCondition;
}