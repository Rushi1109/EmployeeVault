#ifndef __Utility_H__
#define __Utility_H__

#include <string>

namespace EmployeeDB::View {
	class Utility {
	public:
		static bool proceedFurther(const std::string& operation);
		static bool repeatOperation(const std::string& operation, const std::string& Entity);
		static std::string removeWhiteSpaces(std::string& str, const std::string& chars = "\t\n\v\f\r ");
	};
}

#endif