#ifndef _Validator_h_
#define _Validator_h

#include <regex>
#include <string>

namespace EmployeeDB {

	class Validator {
	public:
		static bool validateEmail(const std::string& email);
		static bool validateMobile(const std::string& number);
	};
}

#endif // !_Validator_h_
