#ifndef __FinanceView_h__
#define __FinanceView_h__

#include "FinanceController.h"

namespace EmployeeDB::View {

	class FinanceView {
	public:
		static bool insertFinance();
		static bool getFinanceIDInput(Finance& obj, const std::string& operation);
		static bool deleteFinance();
	};
}

#endif