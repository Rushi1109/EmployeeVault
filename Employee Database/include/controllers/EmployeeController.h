#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include "Employee.h"

using EmployeeDB::Model::Employee;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& employee);
		static int selectEmployeeIDbyEmail(const std::string& email);
		static bool deleteEmployee(int employeeID);
		static bool updateEmployee(const Employee& employee);
	};
}

#endif