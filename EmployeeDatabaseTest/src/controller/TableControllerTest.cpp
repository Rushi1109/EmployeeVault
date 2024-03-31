#include "../../include/fixtures/TableFixture.h"
#include "../../include/controller/TableControllerTest.h"

TEST_F(TableFixture, Test_getCreateTableQueryEmpty) {
	ASSERT_STREQ("CREATE TABLE Roles (", TableControllerTest::getUpdateQueryCondition(*emptyTable).c_str());
}