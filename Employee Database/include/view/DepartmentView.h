#ifndef __DepartmentView_h__
#define __DepartmentView_h__

#include "DepartmentController.h"

namespace EmployeeDB::View {
	class DepartmentView {
	public:
		static void printDepartmentFields();
		static void getInsertDepartmentInput(Department& department);

		static bool insertDepartment();
		static bool getDepartmentIDInput(Department& obj, const std::string& operation);
		static bool deleteDepartment();
	};
}

#endif // __DepartmentView_h__
