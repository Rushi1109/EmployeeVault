#ifndef __HRController_h__
#define __HRController_h__

#include "HR.h"

using EmployeeDB::Model::HR;

namespace EmployeeDB::Controller {

	class HRController {
	public:
		static bool insertHR(HR& hr);
		static bool selectHR(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool updateHR(HR& hr);
		static bool deleteHRByID(int ID);
	private:
		static std::string getUpdateQueryCondition(HR& hr);
	};
}

#endif