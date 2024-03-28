#ifndef __EngineerView_h__
#define __EngineerView_h__

#include "EngineerController.h"

namespace EmployeeDB::View {

	class EngineerView {
	public:
		static bool insertEngineer();
		static bool deleteEngineer();
		static bool updateEngineer();
		static bool viewEngineer();

	private:
		static void printViewEngineerFields();
		static void getViewEngineerInput(Engineer& engineer, int fieldNumber);
		static bool viewEngineerConditional();
	};
}

#endif