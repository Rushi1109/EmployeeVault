#ifndef __EngineerControllerTest_h__
#define __EngineerControllerTest_h__

#include "./include/controller/EngineerController.h"

using EmployeeDB::Controller::EngineerController;

class EngineerControllerTest : public EngineerController {
public:
	static std::string getUpdateQueryCondition(Engineer& engineer) {
		return EngineerController::getUpdateQueryCondition(engineer);
	}
};

#endif // !__EngineerControllerTest_h__
