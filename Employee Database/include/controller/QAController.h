#ifndef __QAController_H__
#define __QAController_H__

#include "QA.h"

using EmployeeDB::Model::QA;

namespace EmployeeDB::Controller {

	class QAController {
	public:
		static bool insertQA(QA& qa);
		static bool selectQA(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool updateQA(QA& qa);
	private:
		static std::string getUpdateQueryCondition(QA& qa);
	};
}

#endif