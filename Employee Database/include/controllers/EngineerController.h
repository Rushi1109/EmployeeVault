#ifndef __EngineerController_H__
#define __EngineerController_H__

#include "Engineer.h"

using EmployeeDB::Model::Engineer;

namespace EmployeeDB::Controller {

	class EngineerController {
	public:
		static bool insertEngineer(Engineer& engineer);
		static bool selectEngineer(const std::string& attributeName = "", const std::string& attributeValue = "");
	};
}

#endif