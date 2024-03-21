#ifndef __EmployeeController_h__
#define __EmployeeController_h__

#include "Employee.h"

using EmployeeDB::Model::Employee;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& employee);
		static bool deleteEmployeeByID(int employeeID);
		static bool updateEmployee(Employee& employee);
		static bool checkEmployeeExistence(const std::string& employeeID, const std::string& departmentName);
		static int getEmployeeIDbyEmail(const std::string& email);
		static int getDepartmentIDbyEmployeeID(int employeeID);
	private:
		static std::string getUpdateQueryCondition(Employee& employee);
	};
}

#endif