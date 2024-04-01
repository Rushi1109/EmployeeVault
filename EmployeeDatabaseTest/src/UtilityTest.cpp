#include "./view/Utility.h"
#include "../pch.h"
using EmployeeDB::View::Utility;

TEST(TestUtility, Test_removeEmptySpacesEmptyString) {
	std::string emptyString{ "" };
	Utility::removeEmptySpaces(emptyString);

	ASSERT_STREQ("", emptyString.c_str());
}

TEST(TestUtility, Test_removeEmptySpacesOneSpace) {
	std::string stringToTest{" \n\v\f\r 123, xyz"};
	Utility::removeEmptySpaces(stringToTest);

	ASSERT_STREQ("123, xyz", stringToTest.c_str());
}

TEST(TestUtility, Test_removeEmptySpacesMultipleSpaces) {
	std::string stringToTest{ "    XY    ZY     XZ    \n  \v \v" };
	Utility::removeEmptySpaces(stringToTest);

	ASSERT_STREQ("XY ZY XZ", stringToTest.c_str());
}