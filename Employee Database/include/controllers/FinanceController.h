#ifndef __FinanceController_H__
#define __FinanceController_H__

#include "Finance.h"

using EmployeeDB::Model::Finance;

namespace EmployeeDB::Controller {

	class FinanceController {
	public:
		static bool insertFinance(Finance& finance);
		static bool selectFinance(const std::string& attributeName = "", const std::string& attributeValue = "");
	};
}

#endif