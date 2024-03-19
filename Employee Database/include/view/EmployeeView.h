#ifndef __EmployeeView_h__
#define __EmployeeView_h__

#include "EmployeeController.h"

namespace EmployeeDB::View {
	class EmployeeView {
	public:
		static void printEmployeeFields();
		static void getEmployeeInput(Employee& employee);
		static bool deleteEmployee();
	};
}

#endif // !__EmployeeView_h__
