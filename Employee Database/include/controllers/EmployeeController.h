#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include "Employee.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Employee;

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee&);
		static int selectEmployeeIDbyEmail(const std::string&);
		static bool deleteEmployee(int);
	};
}

#endif