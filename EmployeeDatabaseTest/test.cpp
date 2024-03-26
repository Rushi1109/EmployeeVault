#include "pch.h"
#include "include/Validator.h"

TEST(TestValidator, Test_validateEmail) {
	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.com"));
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

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}