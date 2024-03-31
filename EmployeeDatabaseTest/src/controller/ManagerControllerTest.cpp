#include "../../include/fixtures/ManagerFixture.h"
#include "../../include/controller/ManagerControllerTest.h"

TEST(TestManagerController, Test_checkManagerExistence) {
	ASSERT_TRUE(ManagerController::checkManagerExistence("1"));
	ASSERT_TRUE(ManagerController::checkManagerExistence("15"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("18"));
}

TEST_F(ManagerFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", ManagerControllerTest::getUpdateQueryCondition(*emptyManager).c_str());
}

TEST_F(ManagerFixture, Test_getUpdateQueryCondition) {
	emptyManager->setYearsOfExperience(8);

	ASSERT_STREQ("yearsOfExp = 8.000000", ManagerControllerTest::getUpdateQueryCondition(*emptyManager).c_str());

	emptyManager->setRole("Backend Lead");
	emptyManager->setTeamSize(10);

	ASSERT_STREQ("teamSize = 10, yearsOfExp = 8.000000, role = \"Backend Lead\"", ManagerControllerTest::getUpdateQueryCondition(*emptyManager).c_str());
}