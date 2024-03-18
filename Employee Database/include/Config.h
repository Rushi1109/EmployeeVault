#ifndef __Config_h__
#define __Config_h__

#include <filesystem>

namespace EmployeeDB::Config {
	static std::filesystem::path dbFilePath = "./data/Employee.db";
}

#endif
