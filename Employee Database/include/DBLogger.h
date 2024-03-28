#ifndef __DBLogger_h__
#define __DBLogger_h__

#include "Config.h"
#include "LogPulse.h"

namespace EmployeeDB::DBLogger {
	LogPulse::Log logger{ "DBLogger", LogPulse::Level::Debug, EmployeeDB::Config::dbLogPath };
}

#endif // !__DBLogger_h__
