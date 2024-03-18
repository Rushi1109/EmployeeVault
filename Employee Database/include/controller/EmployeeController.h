#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include "Employee.h"

using EmployeeDB::Model::Employee;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& employee);
		static bool deleteEmployee(int employeeID);
		static bool updateEmployee(Employee& employee);
		static int getEmployeeIDbyEmail(const std::string& email);
		static int getDepartmentIDbyEmployeeID(int employeeID);
	private:
		static std::string getUpdateQueryCondition(Employee& employee);
	};
}

#endif