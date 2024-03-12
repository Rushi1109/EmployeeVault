#ifndef __DepartmentController_H__
#define __DepartmentController_H__

#include "Department.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Department;

	class DepartmentController {
	public:
		static bool insertDepartment(const Department&);
		static bool deleteDepartment(int);
		static bool selectAllDepartment();
		static int selectDepartmentIDbyName(const std::string&);
		static bool selectAllDepartmentIDAndName();
	};
}

#endif // !__DepartmentController_H__
