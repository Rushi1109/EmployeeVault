#ifndef __ManagerController_h__
#define __ManagerController_h__

#include "Manager.h"

using EmployeeDB::Model::Manager;

namespace EmployeeDB::Controller {

	class ManagerController {
	public:
		static bool insertManager(Manager& manager);
		static bool selectManager(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteManager(int managerID);
	};
}

#endif // !__ManagerController_h__