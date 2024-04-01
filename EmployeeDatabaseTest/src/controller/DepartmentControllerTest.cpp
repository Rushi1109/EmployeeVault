#include "../../include/fixtures/DepartmentFixture.h"
#include "./controller/DepartmentController.h"
#include "../../include/controller/DepartmentControllerTest.h"
#include "DBManager.h"
#include <string_view>

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

TEST_F(DepartmentFixture, Test_insertDepartmentSuccess) {
	ASSERT_TRUE(DepartmentController::insertDepartment(*department));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentName = \"Engineering\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, Test_insertDepartmentFailure) {
	department->setDepartmentName("HR");
	ASSERT_FALSE(DepartmentController::insertDepartment(*department));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentName = \"HR\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, Test_deleteDepartmentByID) {
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(3));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentID = 3;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Department";
	ASSERT_EQ(3, DBManager::instance().executeRowCountQuery(queryString.data()));

	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(1));
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(2));
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(4));
	

	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, Test_selectDepartmentSuccess) {
	ASSERT_TRUE(DepartmentController::selectDepartment());

	ASSERT_TRUE(DepartmentController::selectDepartment("departmentID", "1"));
}

TEST_F(DepartmentFixture, Test_selectDepartmentFailure) {
	ASSERT_FALSE(DepartmentController::selectDepartment("deptID", "1"));
}

TEST_F(DepartmentFixture, Test_updateDepartmentSuccess) {
	emptyDepartment->setDepartmentID(3);
	emptyDepartment->setDepartmentName("Marketing");

	ASSERT_TRUE(DepartmentController::updateDepartment(*emptyDepartment));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentName = \"HR\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Department WHERE departmentName = \"Marketing\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, Test_updateDepartmentFailure) {
	emptyDepartment->setDepartmentID(3);
	emptyDepartment->setDepartmentName("QA");

	ASSERT_FALSE(DepartmentController::updateDepartment(*emptyDepartment));
}

TEST_F(DepartmentFixture, Test_getDepartmentIDbyName) {
	ASSERT_EQ(1, DepartmentController::getDepartmentIDbyName("Engineer"));
	ASSERT_EQ(2, DepartmentController::getDepartmentIDbyName("Finance"));
	ASSERT_EQ(3, DepartmentController::getDepartmentIDbyName("HR"));
	ASSERT_EQ(4, DepartmentController::getDepartmentIDbyName("QA"));
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("Robo"));
}

TEST_F(DepartmentFixture, Test_checkDepartmentExistenceTrue) {
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("3"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("1"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("2"));
}

TEST_F(DepartmentFixture, Test_checkDepartmentExistenceFalse) {
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("10"));
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("8"));
}

TEST_F(DepartmentFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", DepartmentControllerTest::getUpdateQueryCondition(*emptyDepartment).c_str());
}

TEST_F(DepartmentFixture, Test_getUpdateQueryCondition) {
	emptyDepartment->setDepartmentName("Marketing");

	ASSERT_STREQ("departmentName = \"Marketing\"", DepartmentControllerTest::getUpdateQueryCondition(*emptyDepartment).c_str());
}