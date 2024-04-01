#ifndef __EmployeeControllerTest_h__
#define __EmployeeControllerTest_h__

#include "./include/controller/EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;

class EmployeeControllerTest : public EmployeeController {
public:
	static std::string getUpdateQueryCondition(Employee& employee) {
		return EmployeeController::getUpdateQueryCondition(employee);
	}
};

#endif // !__EmployeeControllerTest_h__
