#include "pch.h"
#include "include/Validator.h"

TEST(TestEmail, Test_validateEmail) {
	ASSERT_EQ(EmployeeDB::Validator::validateEmail("rushi.gandhi@@zuru.com"), true);
}