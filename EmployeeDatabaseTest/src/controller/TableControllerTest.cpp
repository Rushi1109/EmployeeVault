#include "../../include/fixtures/TableFixture.h"
#include "../../include/controller/TableControllerTest.h"

TEST_F(TableFixture, Test_createTableSuccess) {
	ASSERT_TRUE(TableController::createTable(*table));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Salary\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, Test_createTableFailure) {
	ASSERT_FALSE(TableController::createTable(*emptyTable));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Roles\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, Test_deleteTableSuccess) {
	ASSERT_TRUE(TableController::createTable(*table));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Salary\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	ASSERT_TRUE(TableController::deleteTable("Salary"));

	queryString = "SELECT * FROM sqlite_schema WHERE name = \"Salary\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, Test_deleteTableFailure) {
	ASSERT_FALSE(TableController::deleteTable("Roles"));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Roles\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, Test_getCreateTableQueryEmpty) {
	ASSERT_STREQ("CREATE TABLE \"Roles\" ();", TableControllerTest::getCreateTableQuery(*emptyTable).c_str());
}

TEST_F(TableFixture, Test_getCreateTableQuery) {
	ASSERT_STREQ("CREATE TABLE \"Salary\" (\"ID\" INT NOT NULL UNIQUE PRIMARY KEY, \"baseSalary\" REAL NOT NULL, \"bonus\" REAL NOT NULL, \"allowance\" REAL , FOREIGN KEY (\"ID\") REFERENCES \"Employee\"(\"employeeID\") ON DELETE CASCADE);",
		TableControllerTest::getCreateTableQuery(*table).c_str());
}