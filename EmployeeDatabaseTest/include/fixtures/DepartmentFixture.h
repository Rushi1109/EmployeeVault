#ifndef __DepartmentFixture_h__
#define __DepartmentFixture_h__

#include "../../pch.h"
#include "Department.h"
#include <memory>

using EmployeeDB::Model::Department;

class DepartmentFixture : public ::testing::Test {
protected:
	void SetUp() override {
		department = std::make_unique<Department>();
		department->setDepartmentID(8);
		department->setDepartmentName("R & D");
		department->setBaseSalary(50000.00);
		department->setAllowance(24000.00);
		department->setDeduction(500.00);

		emptyDepartment = std::make_unique<Department>(true);
	}

	std::unique_ptr<Department> department;
	std::unique_ptr<Department> emptyDepartment;
};

#endif // !__DepartmentFixture_h__
