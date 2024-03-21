#include "pch.h"
#include "include/view/Utility.h"

//TEST(TestEmail, Test_validateEmail) {
//	ASSERT_TRUE(EmployeeDB::Validator::validateEmail("rushi.gandhi@zuru.com"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@@zuru.com"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateEmail("rushi.gandhi@.com"));
//}
//
//TEST(TestMobile, Test_validateMobile) {
//	ASSERT_TRUE(EmployeeDB::Validator::validateMobile("8467298340"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("3467298340"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateMobile("34672983456"));
//}
//
//TEST(TestDate, Test_validateDate) {
//	ASSERT_TRUE(EmployeeDB::Validator::validateDate("11/09/2002"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateDate("00/9/1902"));
//	ASSERT_TRUE(EmployeeDB::Validator::validateDate("29/2/2024"));
//	ASSERT_FALSE(EmployeeDB::Validator::validateDate("29/2/2023"));
//}
//
//TEST(TestGender, Test_validateGender) {
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("male")));
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Male")));
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("female")));
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("Female")));
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("FemALe")));
//	ASSERT_FALSE(EmployeeDB::Validator::validateGender(std::string("emale")));
//	ASSERT_TRUE(EmployeeDB::Validator::validateGender(std::string("OTHEr")));
//}

TEST(TestUtility, Test_removeWhiteSpaces) {
	EXPECT_EQ(EmployeeDB::View::Utility::removeWhiteSpaces(std::string{ "  hel  lo " }), std::string{ "hel lo" });
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}