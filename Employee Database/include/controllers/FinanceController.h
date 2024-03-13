#ifndef __FinanceController_H__
#define __FinanceController_H__

#include "Finance.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Finance;

	class FinanceController {
	public:
		static bool insertFinance(Finance& finance);
		static bool selectFinance(const std::string& attributeName = "", const std::string& attributeValue = "");
	};
}

#endif