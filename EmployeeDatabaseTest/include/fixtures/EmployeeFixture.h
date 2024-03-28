#ifndef __EmployeeFixture_h__
#define __EmployeeFixture_h__

#include "../../pch.h"
#include "Employee.h"

using EmployeeDB::Model::Employee;
using EmployeeDB::Model::Salary;

class EmployeeFixture : public ::testing::Test {
protected:
	void SetUp() override {
		employee = std::make_unique<Employee>();
		employee->setEmployeeID(1);
		employee->setFirstName("Rushi");
		employee->setMiddleName("Mineshkumar");
		employee->setLastName("Gandhi");
		employee->setDateOfBirth("11-09-2002");
		employee->setMobileNo(7283902430);
		employee->setEmail("rushi.gandhi@zuru.com");
		employee->setAddress("88, V.K.");
		employee->setGender(EmployeeDB::Model::Gender::Male);
		employee->setDateOfJoining("01-01-2024");
		employee->setDepartmentID(1);
		employee->setMentorID(1);
		employee->setPerformanceMetric(5.0);
		employee->setBonus(100000);

		emptyEmployee = std::make_unique<Employee>(true);
	}

	std::unique_ptr<Employee> employee;
	std::unique_ptr<Employee> emptyEmployee;
};

#endif // !__EmployeeFixture_h__