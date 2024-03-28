#ifndef __ManagerView_h__
#define __ManagerView_h__

#include "ManagerController.h"

namespace EmployeeDB::View {
	class ManagerView {
	public:
		static bool insertManager();
		static bool deleteManager();
		static bool updateManager();
		static bool viewManager();
	private:
		static void printManagerFields();
		static void printViewManagerFields();
		static void getInsertManagerInput(Manager& manager);
		static bool getManagerIDInput(Manager& obj, const std::string& operation);
		static void printUpdateManagerFields();
		static void getUpdateManagerInput(Manager& manager, int fieldNumber);
		static void getViewManagerInput(Manager& manager, int fieldNumber);
		static bool viewManagerConditional();
	};
}

#endif // __ManagerView_h__
