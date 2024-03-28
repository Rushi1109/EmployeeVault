#include "../../include/fixtures/DepartmentFixture.h"
#include "include/controller/DepartmentController.h"
#include "../../include/controller/DepartmentControllerTest.h"

using EmployeeDB::Controller::DepartmentController;

TEST(TestDepartmentController, Test_getDepartmentIDbyName) {
	ASSERT_EQ(1, DepartmentController::getDepartmentIDbyName("Engineer"));
	ASSERT_EQ(2, DepartmentController::getDepartmentIDbyName("Finance"));
	ASSERT_EQ(3, DepartmentController::getDepartmentIDbyName("HR"));
	ASSERT_EQ(4, DepartmentController::getDepartmentIDbyName("QA"));
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("Robo"));
}

TEST(TestDepartmentController, Test_checkDepartmentExistence) {
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("3"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("1"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("2"));
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("45"));
}

TEST_F(DepartmentFixture, Test_getUpdateQueryCondition) {
	emptyDepartment->setDepartmentName("Marketing");

	ASSERT_STREQ("departmentName = \"Marketing\"", DepartmentControllerTest::getUpdateQueryCondition(*emptyDepartment).c_str());
}