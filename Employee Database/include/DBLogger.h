#ifndef __DBLogger_h__
#define __DBLogger_h__

#include "LogPulse.h"

namespace EmployeeDB::DBLogger {
	LogPulse::Log logger{ "DBLogger", LogPulse::Level::Debug, "D:\\Work\\C++ Training Projects\\Project-2 Employee Database\\Employee Database\\logs\\dblogs.log" };
}

#endif // !__DBLogger_h__
