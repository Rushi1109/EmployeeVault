#ifndef __QAControllerTest_h__
#define __QAControllerTest_h__

#include "../../include/controller/QAController.h"

using EmployeeDB::Controller::QAController;

class QAControllerTest : public QAController {
public:
	static std::string getUpdateQueryCondition(QA& qa) {
		return QAController::getUpdateQueryCondition(qa);
	}
};

#endif // !__QAControllerTest_h__
