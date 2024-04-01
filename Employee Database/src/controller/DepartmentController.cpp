#include <iostream>
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool DepartmentController::insertDepartment(const Department& department) {
	std::string queryString = "INSERT INTO Department (departmentName, baseSalary, allowance, deduction)"
		+ std::string{ "VALUES (" } +
		"\"" + department.getDepartmentName() + "\"" + ", " +
		std::to_string(department.getBaseSalary()) + ","+
		std::to_string(department.getAllowance()) + ","+
		std::to_string(department.getDeduction()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully inserted a Department.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "Department could not be inserted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool DepartmentController::deleteDepartmentByID(int departmentID) {
	std::string queryString = "DELETE FROM Department WHERE departmentID=" + std::to_string(departmentID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "Successfully deleted a Department.\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cerr << "\033[0;31m" << "Department could not be deleted.\n" << "\033[0m";
		return false;
	}
	return true;
}

bool DepartmentController::selectDepartment(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Department " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"  COLLATE NOCASE" : "") + ";";

	try {
		auto rowCount = DBManager::instance().executeSelectQuery(queryString.c_str());
		std::cout << "\033[0;32m" << "----------> " << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found <----------\n" << "\033[0m";
	}
	catch (const std::exception& e) {
		std::cerr << "\033[0;31m" << e.what() << "\033[0m\n";
		return false;
	}
	return true;
};

int DepartmentController::getDepartmentIDbyName(const std::string& departmentName) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentName=\"" + departmentName + "\" COLLATE NOCASE;";
	auto departmentID{ -1 };

	auto getDepartmentIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* dID = static_cast<int*>(data);
		if (!strcmp(azColName[0], "departmentID")) {
			*dID = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeCustomQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return departmentID;
}

bool DepartmentController::updateDepartment(Department& department) {
	std::string updateQueryCondition = getUpdateQueryCondition(department);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Department SET " + updateQueryCondition + " WHERE departmentID = " + std::to_string(department.getDepartmentID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\033[0;32m" << "Successfully updated a Department.\n" << "\033[0m";
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			std::cerr << "\033[0;31m" << "Department could not be updated.\n" << "\033[0m";
			return false;
		}
	}
	return true;
}

std::string DepartmentController::getUpdateQueryCondition(Department& department) {
	std::string updateQueryCondition{ "" };

	if (department.getDepartmentName() != "#") {
		updateQueryCondition += "departmentName = \"" + department.getDepartmentName() + "\"";
	}
	if (department.getBaseSalary() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "baseSalary = " + std::to_string(department.getBaseSalary());
	}
	if (department.getAllowance() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "allowance = " + std::to_string(department.getAllowance());
	}
	if (department.getDeduction() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "deduction = " + std::to_string(department.getDeduction());
	}

	return updateQueryCondition;
}

bool DepartmentController::checkDepartmentExistence(const std::string& departmentID) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentID = " + departmentID + ";";

	auto callbackCount{ 0 };
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