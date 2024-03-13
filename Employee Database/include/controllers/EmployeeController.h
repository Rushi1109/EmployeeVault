#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include "Employee.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Employee;

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& employee);
		static int selectEmployeeIDbyEmail(const std::string& email);
		static bool deleteEmployee(int employeeID);
	};
}

#endif