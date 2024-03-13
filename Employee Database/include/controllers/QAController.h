#ifndef __QAController_H__
#define __QAController_H__

#include "QA.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::QA;

	class QAController {
	public:
		static bool insertQA(QA& qa);
		static bool selectQA(const std::string& attributeName = "", const std::string& attributeValue = "");
	};
}

#endif