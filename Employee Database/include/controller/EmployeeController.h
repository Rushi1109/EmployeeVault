#ifndef __EmployeeController_h__
#define __EmployeeController_h__

#include "Employee.h"
#include "Salary.h"

using EmployeeDB::Model::Employee, EmployeeDB::Model::Salary;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& employee);
		static bool deleteEmployeeByID(int employeeID);
		static bool updateEmployee(Employee& employee);
		static bool checkEmployeeExistence(const std::string& employeeID, const std::string& departmentName);
		static int getEmployeeIDbyEmail(const std::string& email);
		static int getDepartmentIDbyEmployeeID(int employeeID);
		static bool getSalaryDetails(Salary& obj);
	private:
		static std::string getUpdateQueryCondition(Employee& employee);
	};
}

#endif