#ifndef __DepartmentView_h__
#define __DepartmentView_h__

#include "DepartmentController.h"

namespace EmployeeDB::View {
	class DepartmentView {
	public:
		static bool insertDepartment();
		static bool updateDepartment();
		static bool deleteDepartment();
		static bool viewDepartment();

	private:
		static void printDepartmentFields();
		static void printViewDepartmentFields();
		static void getInsertDepartmentInput(Department& department);
		static bool getDepartmentIDInput(Department& obj, const std::string& operation);
		static void getUpdateDepartmentInput(Department& obj, int fieldNumber);
		static void getViewDepartmentInput(Department& obj, int fieldNumber);
		static void viewDepartmentConditional();
	};
}

#endif // __DepartmentView_h__
