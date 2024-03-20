#ifndef __HRView_h__
#define __HRView_h__

#include "HRController.h"

namespace EmployeeDB::View {

	class HRView {
	public:
		static bool insertHR();
		static bool getHRIDInput(HR& obj, const std::string& operation);
		static bool deleteHR();
	};
}

#endif