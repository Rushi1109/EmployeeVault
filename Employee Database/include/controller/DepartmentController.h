#ifndef __DepartmentController_h__
#define __DepartmentController_h__

#include "Department.h"

using EmployeeDB::Model::Department;

namespace EmployeeDB::Controller {

	class DepartmentController {
	public:
		static bool insertDepartment(const Department& department);
		static bool deleteDepartment(int departmentID);
		static bool selectDepartment(const std::string& attributeName = "", const std::string& attributeValue = "");
		static int selectDepartmentIDbyName(const std::string& departmentName);
		static bool selectAllDepartmentIDAndName();
		static bool updateDepartment(Department& department);
	private:
		static std::string getUpdateQueryCondition(Department& department);
	};
}

#endif // !__DepartmentController_H__
