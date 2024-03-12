#ifndef __HRController_H__
#define __HRController_H__

#include "HR.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::HR;

	class HRController {
	public:
		static bool insertHR(HR&);
		static bool selectAllHR();
	};
}

#endif