#include "../../include/fixtures/ManagerFixture.h"
#include "../../include/controller/ManagerControllerTest.h"

TEST_F(ManagerFixture, Test_insertManagerSuccess) {
	ASSERT_TRUE(ManagerController::insertManager(*manager));

	std::string_view queryString = "SELECT * FROM Employee WHERE email = \"david.brown@example.com\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Manager WHERE teamSize = 6;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Manager";
	ASSERT_EQ(3, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, Test_insertManagerFailure) {
	manager->setManagerID(8);
	ASSERT_FALSE(ManagerController::insertManager(*manager));

	std::string_view queryString = "SELECT * FROM Manager WHERE managerID = 8;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, Test_selectManagerSuccess) {
	ASSERT_TRUE(ManagerController::selectManager("firstName", "John"));
}

TEST_F(ManagerFixture, Test_selectManagerFailure) {
	ASSERT_FALSE(ManagerController::selectManager("emote", "Thakkar"));
}

TEST_F(ManagerFixture, Test_updateManagerSuccess) {
	emptyManager->setManagerID(1);
	emptyManager->setEmployeeID(1);
	emptyManager->setFirstName("Alex");
	emptyManager->setEmail("Alex.smith@example.com");
	emptyManager->setTeamSize(7);

	ASSERT_TRUE(ManagerController::updateManager(*emptyManager));

	std::string_view queryString = "SELECT * FROM Employee WHERE firstName = \"Alex\" AND email = \"alex.smith@example.com\" COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE firstName = \"John\" COLLATE NOCASE;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Manager WHERE teamSize = 7;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, Test_updateManagerFailure) {
	emptyManager->setManagerID(2);
	emptyManager->setEmployeeID(2);
	emptyManager->setEmail("sarah.wilson@example.com");

	ASSERT_FALSE(ManagerController::updateManager(*emptyManager));
}

TEST_F(ManagerFixture, Test_deleteManagerByID) {
	ASSERT_TRUE(ManagerController::deleteManagerByID(1));

	std::string_view queryString = "SELECT * FROM Manager WHERE managerID = 1;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE employeeID = 1;";
	ASSERT_EQ(1, DBManager::instance().executeSelectQuery(queryString.data()));

	queryString = "SELECT * FROM Manager;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee;";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, Test_checkManagerExistenceTrue) {
	ASSERT_TRUE(ManagerController::checkManagerExistence("1"));
	ASSERT_TRUE(ManagerController::checkManagerExistence("3"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("18"));
}

TEST_F(ManagerFixture, Test_checkManagerExistenceFalse) {
	ASSERT_FALSE(ManagerController::checkManagerExistence("2"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("5"));
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