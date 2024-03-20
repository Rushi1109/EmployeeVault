#ifndef __ManagerView_h__
#define __ManagerView_h__

#include "ManagerController.h"

namespace EmployeeDB::View {
	class ManagerView {
	public:
		static void printManagerFields();
		static void getInsertManagerInput(Manager& manager);
		static bool insertManager();
		static bool deleteManager();
	};
}

#endif // __ManagerView_h__
