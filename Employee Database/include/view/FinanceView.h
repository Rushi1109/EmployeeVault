#ifndef __FinanceView_h__
#define __FinanceView_h__

#include "FinanceController.h"

namespace EmployeeDB::View {

	class FinanceView {
	public:
		static bool insertFinance();
		static bool deleteFinance();
		static bool updateFinance();
		static bool viewFinance();

	private:
		static void printViewFinanceFields();
		static void getViewFinanceInput(Finance& finance, int fieldNumber);
		static bool viewFinanceConditional();
	};
}

#endif