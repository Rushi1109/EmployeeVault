#ifndef __EngineerFixture_h__
#define __EngineerFixture_h__

#include "../../pch.h"
#include "./model/Engineer.h"

using EmployeeDB::Model::Engineer;

class EngineerFixture : public ::testing::Test {
protected:
	void SetUp() override {
		engineer = std::make_unique<Engineer>();
		engineer->setEmployeeID(6);
		engineer->setFirstName("Alan");
		engineer->setMiddleName("");
		engineer->setLastName("Walker");
		engineer->setDateOfBirth("11-09-2002");
		engineer->setMobileNo(8756908765);
		engineer->setEmail("aln.wlkr@gmail.com");
		engineer->setAddress("88, V.K.");
		engineer->setGender(EmployeeDB::Model::Gender::Male);
		engineer->setDateOfJoining("01-01-2024");
		engineer->setDepartmentID(1);
		engineer->setMentorID(1);
		engineer->setPerformanceMetric(5.0);
		engineer->setBonus(100000);
		engineer->setTechnology("Django");

		emptyEngineer = std::make_unique<Engineer>(true);
	}

	std::unique_ptr<Engineer> engineer;
	std::unique_ptr<Engineer> emptyEngineer;
};

#endif // !__EngineerFixture_h__
