#ifndef __FinanceFixture_h__
#define __FinanceFixture_h__

#include "../../pch.h"
#include "./model/Finance.h"

using EmployeeDB::Model::Finance;

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
		finance->setEmail("aln23.wlkr@gmail.com");
		finance->setAddress("88, V.K.");
		finance->setGender(EmployeeDB::Model::Gender::Male);
		finance->setDateOfJoining("01-01-2024");
		finance->setDepartmentID(2);
		finance->setMentorID(13);
		finance->setPerformanceMetric(7);
		finance->setBonus(30000);
		finance->setAccountingTool("Excel");
		
		emptyFinance = std::make_unique<Finance>(true);
	}

	std::unique_ptr<Finance> finance;
	std::unique_ptr<Finance> emptyFinance;
};

#endif // !__FinanceFixture_h__
