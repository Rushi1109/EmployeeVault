#ifndef __HRFixture_h__
#define __HRFixture_h__

#include "../../pch.h"
#include "HR.h"

using EmployeeDB::Model::HR;

class HRFixture : public ::testing::Test {
protected:
    void SetUp() override {
        hr = std::make_unique<HR>();
        hr->setEmployeeID(30);
        hr->setFirstName("Johnieee");
        hr->setMiddleName("Doeyy");
        hr->setLastName("Swan");
        hr->setDateOfBirth("15/05/1995");
        hr->setMobileNo(8690785692);
        hr->setEmail("john.wan.steven234@example.com");
        hr->setAddress("123 Main St");
        hr->setGender(EmployeeDB::Model::Gender::Male);
        hr->setDateOfJoining("10/07/1994");
        hr->setDepartmentID(3);
        hr->setMentorID(16);
        hr->setPerformanceMetric(6);
        hr->setBonus(30000);
        hr->setHRSpecialization("HR Executive");

        emptyHR = std::make_unique<HR>(true);
    }

    std::unique_ptr<HR> hr;
    std::unique_ptr<HR> emptyHR;
};

#endif // !__HRFixture_h__
