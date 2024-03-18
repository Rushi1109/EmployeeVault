#ifndef __FinanceController_h__
#define __FinanceController_h__

#include "Finance.h"

using EmployeeDB::Model::Finance;

namespace EmployeeDB::Controller {

	class FinanceController {
	public:
		static bool insertFinance(Finance& finance);
		static bool selectFinance(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool updateFinance(Finance& finance);
	private:
		static std::string getUpdateQueryCondition(Finance& finance);
	};
}

#endif