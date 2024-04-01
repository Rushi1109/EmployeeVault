#ifndef __QAFixture_h__
#define __QAFixture_h__

#include "../../pch.h"
#include "./model/QA.h"

using EmployeeDB::Model::QA;

class QAFixture : public ::testing::Test {
protected:
	void SetUp() override {
        qa = std::make_unique<QA>();
        qa->setEmployeeID(26);
        qa->setFirstName("Johnieee");
        qa->setMiddleName("Doeyy");
        qa->setLastName("Steven");
        qa->setDateOfBirth("15/05/1995");
        qa->setMobileNo(8690785697);
        qa->setEmail("john.doe.steven@example.com");
        qa->setAddress("123 Main St");
        qa->setGender(EmployeeDB::Model::Gender::Male);
        qa->setDateOfJoining("10/07/2003");
        qa->setDepartmentID(4);
        qa->setMentorID(25);
        qa->setPerformanceMetric(8.5);
        qa->setBonus(50000);
        qa->setTestingTool("JIRA");

        emptyQA = std::make_unique<QA>(true);
	}

    std::unique_ptr<QA> qa;
    std::unique_ptr<QA> emptyQA;
};

#endif // !__QAFixture_h__
