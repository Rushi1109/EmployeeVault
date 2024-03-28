#ifndef __Config_h__
#define __Config_h__

#include <filesystem>

namespace EmployeeDB::Config {
	static std::filesystem::path dbFilePath = "./data/Employee.db";
	static std::filesystem::path dbLogPath = "./logs/dblogs.log";
	static std::filesystem::path CSVFilePath = "./data/CSVs/";
}

#endif
