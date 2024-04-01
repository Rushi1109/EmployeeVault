#include "../../include/fixtures/TableFixture.h"
#include "../../include/controller/TableControllerTest.h"

TEST_F(TableFixture, Test_getCreateTableQueryEmpty) {
	ASSERT_STREQ("CREATE TABLE \"Roles\" ();", TableControllerTest::getUpdateQueryCondition(*emptyTable).c_str());
}

TEST_F(TableFixture, Test_getCreateTableQuery) {
	ASSERT_STREQ("CREATE TABLE \"Manager\" (\"ID\" INT NOT NULL UNIQUE PRIMARY KEY, \"DepartmentName\" TEXT NOT NULL, \"teamSize\" INT , FOREIGN KEY (\"DepartmentName\") REFERENCES \"Department\"(\"departmentName\") ON DELETE CASCADE);",
		TableControllerTest::getUpdateQueryCondition(*table).c_str());
}