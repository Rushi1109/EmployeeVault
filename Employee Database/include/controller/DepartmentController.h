#ifndef __DepartmentController_h__
#define __DepartmentController_h__

#include "Department.h"

using EmployeeDB::Model::Department;

namespace EmployeeDB::Controller {

	class DepartmentController {
	public:
		static bool insertDepartment(const Department& department);
		static bool deleteDepartmentByID(int departmentID);
		static bool selectDepartment(const std::string& attributeName = "", const std::string& attributeValue = "");
		static int getDepartmentIDbyName(const std::string& departmentName);
		static bool updateDepartment(Department& department);
		static bool checkDepartmentExistence(const std::string& departmentID);
	protected:
		static std::string getUpdateQueryCondition(Department& department);
	};
}

#endif // !__DepartmentController_H__
