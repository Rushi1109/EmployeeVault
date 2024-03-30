#include "../../include/controller/EmployeeController.h"
#include "../../include/fixtures/EmployeeFixture.h"
#include "../../include/fixtures/SalaryFixture.h"
#include "../../include/controller/EmployeeControllerTest.h"

using EmployeeDB::Controller::EmployeeController;

TEST(TestEmployeeController, Test_checkEmployeeExistence) {
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("1", "Engineer"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("8", "Finance"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("17", "HR"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("26", "QA"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("2", "HR"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("15", "R&D"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("10", "Marketing"));
}

TEST(TestEmployeeController, Test_getEmployeeIDbyEmail) {
	ASSERT_EQ(1, EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"));
	ASSERT_NE(2, EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"));
	ASSERT_NE(5, EmployeeController::getEmployeeIDbyEmail("rushi.gandhi@gmail.com"));
}

TEST(TestEmployeeController, Test_getDepartmentIDByEmployeeID) {
	ASSERT_EQ(1, EmployeeController::getDepartmentIDbyEmployeeID(4));
	ASSERT_EQ(1, EmployeeController::getDepartmentIDbyEmployeeID(3));
	ASSERT_EQ(2, EmployeeController::getDepartmentIDbyEmployeeID(10));
	ASSERT_EQ(3, EmployeeController::getDepartmentIDbyEmployeeID(17));
	ASSERT_NE(1, EmployeeController::getDepartmentIDbyEmployeeID(17));
}

TEST_F(SalaryFixture, Test_getSalaryDetails) {
	ASSERT_TRUE(EmployeeController::getSalaryDetails(*salary));

	ASSERT_DOUBLE_EQ(500.0, salary->getBonus());
	ASSERT_DOUBLE_EQ(0.85, salary->getPerformanceMetric());
	ASSERT_DOUBLE_EQ(3000.0, salary->getDeduction());
	ASSERT_DOUBLE_EQ(65000.0, salary->getBaseSalary());
	ASSERT_DOUBLE_EQ(7000.0, salary->getAllowance());
}

TEST_F(EmployeeFixture, Test_getUpdateQueryCondition) {
	emptyEmployee->setBonus(50000.000000);
	emptyEmployee->setMiddleName("Singh");

	ASSERT_STREQ("middleName = \"Singh\", bonus = 50000.000000", EmployeeControllerTest::getUpdateQueryCondition(*emptyEmployee).c_str());
}