#include "../include/Validator.h"
using EmployeeDB::Validator;

bool Validator::validateEmail(const std::string& email) {
	return std::regex_match(email, std::regex("(^[a-zA-Z0-9\\.]+@([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,4}$)"));
}

bool Validator::validateMobile(const std::string& number) {
	return std::regex_match(number, std::regex("(^[6-9]{1}[0-9]{9}$)"));
}