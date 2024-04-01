#include "./controller/EmployeeController.h"
#include "../../include/fixtures/EmployeeFixture.h"
#include "../../include/fixtures/SalaryFixture.h"
#include "../../include/controller/EmployeeControllerTest.h"

using EmployeeDB::Controller::EmployeeController;

TEST_F(EmployeeFixture, Test_insertEmployeeSuccess) {
	ASSERT_TRUE(EmployeeController::insertEmployee(*employee));

	std::string_view queryString = "SELECT * FROM Employee WHERE mobileNo = 7283902430 COLLATE NOCASE;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, Test_insertEmployeeFailure) {
	employee->setEmail("emily.williams@example.com");
	ASSERT_FALSE(EmployeeController::insertEmployee(*employee));

	std::string_view queryString = "SELECT * FROM Employee WHERE email = \"emily.williams@example.com\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, Test_deleteEmployeeByID) {
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(3));

	std::string_view queryString = "SELECT * FROM Employee WHERE employeeID = 3;";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));

	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(1));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(2));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(4));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(5));


	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, Test_updateEmployeeSuccess) {
	emptyEmployee->setEmployeeID(5);
	emptyEmployee->setLastName("Woods");

	ASSERT_TRUE(EmployeeController::updateEmployee(*emptyEmployee));

	std::string_view queryString = "SELECT * FROM Employee WHERE lastName = \"Williams\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE lastName = \"Woods\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, Test_updateEmployeeFailure) {
	emptyEmployee->setEmployeeID(5);
	emptyEmployee->setMobileNo(9876543211);

	ASSERT_FALSE(EmployeeController::updateEmployee(*emptyEmployee));
}

TEST_F(EmployeeFixture, Test_checkEmployeeExistenceTrue) {
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("1", "Engineer"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("3", "Finance"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("4", "HR"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("5", "QA"));
}

TEST_F(EmployeeFixture, Test_checkEmployeeExistenceFalse) {
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("2", "HR"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("15", "R&D"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("10", "Marketing"));
}

TEST_F(EmployeeFixture, Test_getEmployeeIDbyEmail) {
	ASSERT_EQ(1, EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"));
	ASSERT_NE(2, EmployeeController::getEmployeeIDbyEmail("john.smith@example.com"));
	ASSERT_NE(5, EmployeeController::getEmployeeIDbyEmail("rushi.gandhi@gmail.com"));
}

TEST_F(EmployeeFixture, Test_getDepartmentIDByEmployeeID) {
	ASSERT_EQ(1, EmployeeController::getDepartmentIDbyEmployeeID(1));
	ASSERT_EQ(1, EmployeeController::getDepartmentIDbyEmployeeID(2));
	ASSERT_EQ(2, EmployeeController::getDepartmentIDbyEmployeeID(3));
	ASSERT_EQ(3, EmployeeController::getDepartmentIDbyEmployeeID(4));
	ASSERT_NE(1, EmployeeController::getDepartmentIDbyEmployeeID(5));
}

TEST_F(EmployeeFixture, Test_getSalaryDetails) {
	std::unique_ptr<Salary> salary = std::make_unique<Salary>();
	salary->setEmployeeID(1);
	salary->setDepartmentID(1);
	ASSERT_TRUE(EmployeeController::getSalaryDetails(*salary));

	ASSERT_DOUBLE_EQ(500.0, salary->getBonus());
	ASSERT_DOUBLE_EQ(0.85, salary->getPerformanceMetric());
	ASSERT_DOUBLE_EQ(3000.0, salary->getDeduction());
	ASSERT_DOUBLE_EQ(65000.0, salary->getBaseSalary());
	ASSERT_DOUBLE_EQ(7000.0, salary->getAllowance());
}

TEST_F(EmployeeFixture, Test_getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", EmployeeControllerTest::getUpdateQueryCondition(*emptyEmployee).c_str());
}

TEST_F(EmployeeFixture, Test_getUpdateQueryCondition) {
	emptyEmployee->setMiddleName("Singh");

	ASSERT_STREQ("middleName = \"Singh\"", EmployeeControllerTest::getUpdateQueryCondition(*emptyEmployee).c_str());

	emptyEmployee->setBonus(50000.000000);
	emptyEmployee->setDateOfBirth("21/04/1995");

	ASSERT_STREQ("middleName = \"Singh\", dateOfBirth = \"21/04/1995\", bonus = 50000.000000", EmployeeControllerTest::getUpdateQueryCondition(*emptyEmployee).c_str());
}