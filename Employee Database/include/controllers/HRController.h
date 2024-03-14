#ifndef __HRController_H__
#define __HRController_H__

#include "HR.h"

using EmployeeDB::Model::HR;

namespace EmployeeDB::Controller {

	class HRController {
	public:
		static bool insertHR(HR& hr);
		static bool selectHR(const std::string& attributeName = "", const std::string& attributeValue = "");
	};
}

#endif