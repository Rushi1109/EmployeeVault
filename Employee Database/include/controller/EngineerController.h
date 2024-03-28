#ifndef __EngineerController_h__
#define __EngineerController_h__

#include "Engineer.h"

using EmployeeDB::Model::Engineer;

namespace EmployeeDB::Controller {

	class EngineerController {
	public:
		static bool insertEngineer(Engineer& engineer);
		static bool selectEngineer(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool updateEngineer(Engineer& engineer);
		static bool deleteEngineerByID(int ID);
	protected:
		static std::string getUpdateQueryCondition(Engineer& engineer);
	};
}

#endif