#ifndef __FinanceFixture_h__
#define __FinanceFixture_h__

#include "../../pch.h"
#include "./model/Finance.h"
#include "DBManager.h"

using EmployeeDB::Model::Finance;
using EmployeeDB::DBManager;

class FinanceFixture : public ::testing::Test {
protected:
	void SetUp() override {
		finance = std::make_unique<Finance>();
		finance->setEmployeeID(32);
		finance->setFirstName("Alan");
		finance->setMiddleName("Alex");
		finance->setLastName("Walker");
		finance->setDateOfBirth("23-05-1998");
		finance->setMobileNo(8756245903);
		finance->setEmail("aln23kr@gmail.com");
		finance->setAddress("88, V.K.");
		finance->setGender(EmployeeDB::Model::Gender::Male);
		finance->setDateOfJoining("01-01-2024");
		finance->setDepartmentID(2);
		finance->setMentorID(1);
		finance->setPerformanceMetric(7);
		finance->setBonus(30000);
		finance->setAccountingTool("SAP ERP");

		emptyFinance = std::make_unique<Finance>(true);

		DBManager::executeConfigQuery();

		std::string_view insertQuery = "INSERT INTO Department(\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES "
			"(1, 'Engineer', 65000, 7000, 3000),"
			"(2, 'Finance', 65000, 6000, 2500);";

		DBManager::instance().executeQuery(insertQuery.data());

		insertQuery = "INSERT INTO Employee (\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNo\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES "
			"(1, 'Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, 1, 0.75, 400),"
			"(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 2, 1, 0.88, 600);";

		DBManager::instance().executeQuery(insertQuery.data());

		insertQuery = "INSERT INTO Finance (\"employeeID\", \"accountingTool\") VALUES "
			"(1, 'Tally'),"
			"(2, 'Excel');";

		DBManager::instance().executeQuery(insertQuery.data());
	}

	void TearDown() override {
		DBManager::instance().executeTruncateQuery("Department");
		DBManager::instance().executeTruncateQuery("Employee");
		DBManager::instance().executeTruncateQuery("Finance");
	}

	std::unique_ptr<Finance> finance;
	std::unique_ptr<Finance> emptyFinance;
};

#endif // !__FinanceFixture_h__
