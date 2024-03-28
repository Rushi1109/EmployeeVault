#ifndef __DBLogger_h__
#define __DBLogger_h__

#include "LogPulse.h"

namespace EmployeeDB::DBLogger {
	LogPulse::Log logger{ "DBLogger", LogPulse::Level::Debug, "./logs/dblogs.log" };
}

#endif // !__DBLogger_h__
