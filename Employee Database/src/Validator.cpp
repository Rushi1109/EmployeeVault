#include "Validator.h"
#include "EmployeeController.h"
#include "DepartmentController.h"
#include "ManagerController.h"

using EmployeeDB::Controller::EmployeeController, EmployeeDB::Controller::DepartmentController, EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validator;

bool Validator::validateEmail(const std::string& email) {
	return std::regex_match(email, std::regex("(^[a-zA-Z0-9\\.]+@([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,4}$)"));
}

bool Validator::validateMobile(const std::string& number) {
	return std::regex_match(number, std::regex("(^[6-9]{1}[0-9]{9}$)"));
}

bool Validator::validateDate(const std::string& date) {
	return std::regex_match(date, std::regex(R"(^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[13-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$)"));
}

bool Validator::validateGender(std::string& gender) {
	std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	return (gender == "male" || gender == "female" || gender == "other");
}

bool Validator::validateEmployeeID(const std::string& employeeID, const std::string& departmentName) {
	auto regexResult = std::regex_match(employeeID, std::regex("(^[0-9]+$)"));

	if (!regexResult) {
		return false;
	}

	return EmployeeController::checkEmployeeExistence(employeeID, departmentName);
}

bool Validator::validateManagerID(const std::string& managerID) {
	auto regexResult = std::regex_match(managerID, std::regex("(^[0-9]+$)"));

	if (!regexResult) {
		return false;
	}

	return ManagerController::checkManagerExistence(managerID);
}

bool Validator::validateDepartmentID(const std::string& departmentID) {
	auto regexResult = std::regex_match(departmentID, std::regex("(^[0-9]+$)"));

	if (!regexResult) {
		return false;
	}

	return DepartmentController::checkDepartmentExistence(departmentID);
}