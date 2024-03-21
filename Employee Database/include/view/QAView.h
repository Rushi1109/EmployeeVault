#ifndef __QAView_h__
#define __QAView_h__

#include "QAController.h"

namespace EmployeeDB::View {

	class QAView {
	public:
		static bool insertQA();
		static bool deleteQA();
		static bool updateQA();
	};
}

#endif