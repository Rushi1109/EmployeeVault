#ifndef __EmployeeView_h__
#define __EmployeeView_h__

#include "EmployeeController.h"

namespace EmployeeDB::View {
	class EmployeeView {
	public:
		static void printEmployeeFields();
		static void printViewEmployeeFields();
		static void getInsertEmployeeInput(Employee& employee);
		static void getUpdateEmployeeInput(Employee& employee, int fieldNumber);
		static void getViewEmployeeInput(Employee& employee, int fieldNumber);
		static void getEmployeeIDInput(Employee& employee, const std::string& operation, const std::string& entity);
	};
}

#endif // !__EmployeeView_h__
