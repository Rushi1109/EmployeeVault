#ifndef __DepartmentControllerTest_h__
#define __DepartmentControllerTest_h__

#include "./include/controller/DepartmentController.h"

using EmployeeDB::Controller::DepartmentController;

class DepartmentControllerTest : public DepartmentController {
public:
	static std::string getUpdateQueryCondition(Department& department) {
		return DepartmentController::getUpdateQueryCondition(department);
	}
};

#endif // !__DepartmentControllerTest_h__
