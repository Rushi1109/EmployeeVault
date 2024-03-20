#pragma once
#include "gtest/gtest.h"
#include "include/model/Employee.h"

class EmployeeFixture : public testing::Test {
protected:
	void SetUp() {

	}
	EmployeeDB::Model::Employee emp;
};