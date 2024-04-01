#ifndef __ManagerFixture_h__
#define __ManagerFixture_h__

#include "../../pch.h"
#include "./model/Manager.h"

using EmployeeDB::Model::Manager;

class ManagerFixture : public ::testing::Test {
protected:
	void SetUp() override {
		manager = std::make_unique<Manager>();
		manager->setEmployeeID(3);
		manager->setFirstName("Daniel");
		manager->setMiddleName("Joseph");
		manager->setLastName("Garcia");
		manager->setDateOfBirth("22-06-1989");
		manager->setMobileNo(9675021123);
		manager->setEmail("dalien.garcia@example.com");
		manager->setAddress("234 Cedar St, City, Country");
		manager->setGender(EmployeeDB::Model::Gender::Male);
		manager->setDateOfJoining("30-08-2018");
		manager->setDepartmentID(1);
		manager->setMentorID(3);
		manager->setPerformanceMetric(0.85);
		manager->setBonus(550.0);
		manager->setManagerID(3);
		manager->setTeamSize(6);
		manager->setYearsOfExperience(4.5);
		manager->setProjectTitle("Heartbeat Tracker");
		manager->setRole("Lead C++ developer");

		emptyManager = std::make_unique<Manager>(true);
	}

	std::unique_ptr<Manager> manager;
	std::unique_ptr<Manager> emptyManager;
};

#endif // !__ManagerFixture_h__
