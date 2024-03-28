#include "../../include/fixtures/SalaryFixture.h"

TEST_F(SalaryFixture, Test_computeSalary) {
	double computedSalary = salary->computeSalary();
	double actualSalary = 74046;

	ASSERT_DOUBLE_EQ(computedSalary, actualSalary);
}

TEST_F(SalaryFixture, Test_emptySalary) {
	double computedSalary = emptySalary->computeSalary();
	double actualSalary = 0.0;

	ASSERT_DOUBLE_EQ(computedSalary, actualSalary);
}