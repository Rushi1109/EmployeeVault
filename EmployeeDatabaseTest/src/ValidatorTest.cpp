#include "../pch.h"
#include "gmock/gmock.h"
#include "include/Validator.h"
#include "./controller/DepartmentController.h"
#include "../include/fixtures/DepartmentFixture.h"
#include "../include/fixtures/EmployeeFixture.h"
#include "../include/fixtures/ManagerFixture.h"

using EmployeeDB::Controller::DepartmentController;

TEST(TestValidator, Test_validateEmailTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@gmail.com"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.com"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.co.in"));
}

TEST(TestValidator, Test_validateEmailFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zu$ru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhizu$ru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@@zuru.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@.com"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushii.com"));
}

TEST(TestValidator, Test_validateMobileTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateMobile("8467298340"));
	ASSERT_TRUE(EmployeeDB::Validator::validateMobile("9767298340"));
	ASSERT_TRUE(EmployeeDB::Validator::validateMobile("6767298340"));
}

TEST(TestValidator, Test_validateMobileFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("3467298340"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983456"));
	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("84672@5634"));
}

TEST(TestValidator, Test_validateDateTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("11/09/2002"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("29/2/2024"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("2-2-2023"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDate("2.2.2023"));
}

TEST(TestValidator, Test_validateDateFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("00/9/1902"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("29/2/2023"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("30/2/2024"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDate("14/1/1093"));
}

TEST(TestValidator, Test_validateGenderTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("male")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Male")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("female")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Female")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("FemALe")));
	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("OTHEr")));
}

TEST(TestValidator, Test_validateGenderFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("emale")));
	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("m")));
	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("f")));
	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("oth")));
}

TEST_F(EmployeeFixture, Test_validateEmployeeIDTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("1", "Engineer"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("3", "Finance"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("4", "hr"));
	ASSERT_TRUE(EmployeeDB::Validator::validateEmployeeID("5", "qA"));
}

TEST_F(EmployeeFixture, Test_validateEmployeeIDFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateEmployeeID("3", "Engineer"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmployeeID("2", "Finance"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmployeeID("1", "hr"));
	ASSERT_FALSE(EmployeeDB::Validator::validateEmployeeID("4", "qA"));
}

TEST_F(ManagerFixture, Test_validateManagerIDTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateManagerID("1"));
	ASSERT_TRUE(EmployeeDB::Validator::validateManagerID("3"));
}

TEST_F(ManagerFixture, Test_validateManagerIDFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateManagerID("4"));
	ASSERT_FALSE(EmployeeDB::Validator::validateManagerID("19"));
}

TEST_F(DepartmentFixture, Test_validateDepartmentIDTrue) {
	ASSERT_TRUE(EmployeeDB::Validator::validateDepartmentID("1"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDepartmentID("2"));
	ASSERT_TRUE(EmployeeDB::Validator::validateDepartmentID("3"));
}

TEST_F(DepartmentFixture, Test_validateDepartmentIDFalse) {
	ASSERT_FALSE(EmployeeDB::Validator::validateDepartmentID("5"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDepartmentID("6"));
	ASSERT_FALSE(EmployeeDB::Validator::validateDepartmentID("40"));
}