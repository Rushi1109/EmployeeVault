#include "../../include/fixtures/FinanceFixture.h"
#include "../../include/controller/FinanceControllerTest.h"

TEST_F(FinanceFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());
}

TEST_F(FinanceFixture, Test_getUpdateQueryCondition) {
	emptyFinance->setAccountingTool("Excel");

	ASSERT_STREQ("accountingTool = \"Excel\"", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());

	emptyFinance->setMiddleName("Yadav");

	ASSERT_STREQ("accountingTool = \"Excel\"", FinanceControllerTest::getUpdateQueryCondition(*emptyFinance).c_str());
}