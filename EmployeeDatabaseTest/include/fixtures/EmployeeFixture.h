#ifndef __EmployeeFixture_h__
#define __EmployeeFixture_h__

#include "../../pch.h"
#include "./model/Employee.h"
#include "DBManager.h"

using EmployeeDB::Model::Employee, EmployeeDB::Model::Salary;
using EmployeeDB::DBManager;

class EmployeeFixture : public ::testing::Test {
protected:
	void SetUp() override {
		emptyEmployee = std::make_unique<Employee>(true);
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


		std::string_view insertQuery = "INSERT INTO Department(\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES "
			"(1, 'Engineer', 65000, 7000, 3000),"
			"(2, 'Finance', 65000, 6000, 2500),"
			"(3, 'HR', 55000, 4000, 1500),"
			"(4, 'QA', 59000, 4800, 1900);";

		DBManager::instance().executeQuery(insertQuery.data());

		insertQuery = "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNo\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES "
			"(1, 'John', 'Doe', 'Smith', '15-05-1990', 1234567891, 'john.smith@example.com', '123 Main St, City, Country', 'Male', '10-01-2020', 1, 1, 0.85, 500),"
			"(2, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, 2, 0.78, 450),"
			"(3, 'Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, 8, 0.75, 400),"
			"(4, 'Michael', 'James', 'Johnson', '12-12-1985', 4567890128, 'michael.johnson@example.com', '789 Oak St, City, Country', 'Male', '05-03-2019', 3, 15, 0.9, 600),"
			"(5, 'Emily', 'Anne', 'Williams', '25-10-1988', 9870723456, 'emily.williams@example.com', '101 Pine St, City, Country', 'Female', '15-02-2021', 4, 22, 0.82, 550);";

		DBManager::instance().executeQuery(insertQuery.data());
	}

	void TearDown() override {
		DBManager::instance().executeTruncateQuery("Employee");
		DBManager::instance().executeTruncateQuery("Department");
	}

	std::unique_ptr<Employee> employee;
	std::unique_ptr<Employee> emptyEmployee;
};

#endif // !__EmployeeFixture_h__