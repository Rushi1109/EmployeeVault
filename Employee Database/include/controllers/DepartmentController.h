#ifndef __DepartmentController_H__
#define __DepartmentController_H__

#include "Department.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Department;

	class DepartmentController {
	public:
		static bool insertDepartment(const Department&);
		static int selectDepartmentIDbyName(const std::string&);
		static bool deleteDepartment(int);
	};
}

#endif // !__DepartmentController_H__
