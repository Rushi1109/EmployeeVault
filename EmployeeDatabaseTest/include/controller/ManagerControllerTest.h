#ifndef __ManagerControllerTest_h__
#define __ManagerControllerTest_h__

#include "./include/controller/ManagerController.h"

using EmployeeDB::Controller::ManagerController;

class ManagerControllerTest : public ManagerController {
public:
	static std::string getUpdateQueryCondition(Manager& manager) {
		return ManagerController::getUpdateQueryCondition(manager);
	}
};

#endif // !__ManagerControllerTest_h__
