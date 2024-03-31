#include "../../include/fixtures/HRFixture.h"
#include "../../include/controller/HRControllerTest.h"

TEST_F(HRFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());
}

TEST_F(HRFixture, Test_getUpdateQueryCondition) {
	emptyHR->setHRSpecialization("Sr. HR Executive");

	ASSERT_STREQ("hrSpecialization = \"Sr. HR Executive\"", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());

	emptyHR->setFirstName("Himanshu");

	ASSERT_STREQ("hrSpecialization = \"Sr. HR Executive\"", HRControllerTest::getUpdateQueryCondition(*emptyHR).c_str());
}