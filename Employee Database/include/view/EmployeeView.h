#ifndef __EmployeeView_h__
#define __EmployeeView_h__

#include "EmployeeController.h"

namespace EmployeeDB::View {
	class EmployeeView {
	public:
		static void printEmployeeFields();
		static void getInsertEmployeeInput(Employee& employee);
		static void getUpdateEmployeeInput(Employee& employee, int fieldNumber);
	};
}

#endif // !__EmployeeView_h__
