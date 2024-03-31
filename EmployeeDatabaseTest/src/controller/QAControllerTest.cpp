#include "../../include/fixtures/QAFixture.h"
#include "../../include/controller/QAControllerTest.h"

TEST_F(QAFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());
}

TEST_F(QAFixture, Test_getUpdateQueryCondition) {
	emptyQA->setTestingTool("Mocha");

	ASSERT_STREQ("testingTool = \"Mocha\"", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());

	emptyQA->setBonus(25000.00);

	ASSERT_STREQ("testingTool = \"Mocha\"", QAControllerTest::getUpdateQueryCondition(*emptyQA).c_str());
}