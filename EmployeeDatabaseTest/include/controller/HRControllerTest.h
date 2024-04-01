#ifndef __HRControllerTest_h__
#define __HRControllerTest_h__

#include "./include/controller/HRController.h"

using EmployeeDB::Controller::HRController;

class HRControllerTest : public HRController {
public:
	static std::string getUpdateQueryCondition(HR& hr) {
		return HRController::getUpdateQueryCondition(hr);
	}
};

#endif // !__HRControllerTest_h__
