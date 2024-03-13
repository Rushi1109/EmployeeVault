#ifndef __ManagerController_h__
#define __ManagerController_h__

#include "Manager.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Manager;

	class ManagerController {
	public:
		static bool insertManager(Manager&);
		static bool selectAllManager();
		static bool deleteManager(int managerID);
	};
}

#endif // !__ManagerController_h__