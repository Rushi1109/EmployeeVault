#ifndef __DepartmentController_H__
#define __DepartmentController_H__

#include "Department.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Department;

	class DepartmentController {
	public:
		static bool insertDepartment(const Department& department);
		static bool deleteDepartment(int departmentID);
		static bool selectDepartment(const std::string& attributeName = "", const std::string& attributeValue = "");
		static int selectDepartmentIDbyName(const std::string& departmentName);
		static bool selectAllDepartmentIDAndName();
	};
}

#endif // !__DepartmentController_H__
