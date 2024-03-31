#include "../../include/fixtures/EngineerFixture.h"
#include "../../include/controller/EngineerControllerTest.h"

TEST_F(EngineerFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());
}

TEST_F(EngineerFixture, Test_getUpdateQueryCondition) {
	emptyEngineer->setTechnology("c++");

	ASSERT_STREQ("technology = \"c++\"", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());

	emptyEngineer->setMiddleName("Patel");

	ASSERT_STREQ("technology = \"c++\"", EngineerControllerTest::getUpdateQueryCondition(*emptyEngineer).c_str());
}