#include "pch.h"
#include "include/Validator.h"

TEST(TestEmail, Test_validateEmail) {
	ASSERT_EQ(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.com"), true);
	ASSERT_EQ(EmployeeDB::Validator::validateEmail("rushi.gandhi@@zuru.com"), false);
	ASSERT_EQ(EmployeeDB::Validator::validateEmail("rushi.gandhi@.com"), false);
}

TEST(TestMobile, Test_validateMobile) {
	ASSERT_EQ(EmployeeDB::Validator::validateMobile("8467298340"), true);
	ASSERT_EQ(EmployeeDB::Validator::validateMobile("3467298340"), false);
	ASSERT_EQ(EmployeeDB::Validator::validateMobile("34672983"), false);
	ASSERT_EQ(EmployeeDB::Validator::validateMobile("34672983456"), false);
}

TEST(TestDate, Test_validateDate) {
	ASSERT_EQ(EmployeeDB::Validator::validateDate("11/09/2002"), true);
	ASSERT_EQ(EmployeeDB::Validator::validateDate("00/9/1902"), false);
	ASSERT_EQ(EmployeeDB::Validator::validateDate("29/2/2024"), true);
	ASSERT_EQ(EmployeeDB::Validator::validateDate("29/2/2023"), false);
}

TEST(TestGender, Test_validateGender) {
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("male")), true);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("Male")), true);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("female")), true);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("Female")), true);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("FemALe")), true);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("emale")), false);
	ASSERT_EQ(EmployeeDB::Validator::validateGender(std::string("OTHEr")), true);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}