#ifndef __Validator_h__
#define __Validator_h__

#include <regex>
#include <string>

namespace EmployeeDB {

	class Validator {
	public:
		static bool validateEmail(const std::string& email);
		static bool validateMobile(const std::string& number);
		static bool validateDate(const std::string& date);
		static bool validateNumber(const std::string& number);
	};
}

#endif // !_Validator_h_
