#ifndef __EngineerController_H__
#define __EngineerController_H__

#include "Engineer.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Engineer;

	class EngineerController {
	public:
		static bool insertEngineer(const Engineer&);
	};
}

#endif