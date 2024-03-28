#include "../pch.h"
#include "gmock/gmock.h"
#include "include/Validator.h"
#include "include/controller/DepartmentController.h"

using EmployeeDB::Controller::DepartmentController;

TEST(TestValidator, Test_validateEmailTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@gmail.com"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zu$ru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhizu$ru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@@zuru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushii.com"));
}

TEST(TestValidator, Test_validateMobile) {
	ASSERT_TRUE(EmployeeDB::Validator::validateMobile("8467298340"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("3467298340"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983456"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("84672@5634"));
}

TEST(TestValidator, Test_validateDate) {
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("11/09/2002"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("00/9/1902"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("29/2/2024"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("29/2/2023"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("2-2-2023"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("2.2.2023"));
}

TEST(TestValidator, Test_validateGender) {
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("male")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Male")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("female")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Female")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("FemALe")));
	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("emale")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("OTHEr")));
}

TEST(TestValidator, Test_validateEmployeeID) {
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("1", "Engineer"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("8", "Finance"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("16", "hr"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("25", "qA"));
}

TEST(TestValidator, Test_validateManagerID) {
	ASSERT_TRUE(EmployeeDB::Validator::validateManagerID("1"));
	ASSERT_FALSE(EmployeeDB::Validator::validateManagerID("19"));
}

TEST(TestValidator, Test_validateDepartmentID) {
	ASSERT_TRUE(EmployeeDB::Validator::validateDepartmentID("1"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDepartmentID("40"));
}