#ifndef __HRView_h__
#define __HRView_h__

#include "HRController.h"

namespace EmployeeDB::View {

	class HRView {
	public:
		static bool insertHR();
		static bool deleteHR();
		static bool updateHR();
		static bool viewHR();

	private:
		static void printViewHRFields();
		static void getViewHRInput(HR& hr, int fieldNumber);
		static bool viewHRConditional();
	};
}

#endif