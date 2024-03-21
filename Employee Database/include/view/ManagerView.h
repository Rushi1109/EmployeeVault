#ifndef __ManagerView_h__
#define __ManagerView_h__

#include "ManagerController.h"

namespace EmployeeDB::View {
	class ManagerView {
	public:
		static void printManagerFields();
		static void getInsertManagerInput(Manager& manager);
		static bool insertManager();
		static bool getManagerIDInput(Manager& obj, const std::string& operation);
		static bool deleteManager();
		static void printUpdateManagerFields();
		static void getUpdateManagerInput(Manager& manager, int fieldNumber);
		static bool updateManager();
	};
}

#endif // __ManagerView_h__
