#ifndef _Department_h_
#define _Department_h_

#include <string>

namespace EmployeeDB::Model {

	class Department {
	public:
		void insertDepartment() const;
		void deleteDepartment() const;
		void updateDepartment() const;
		void viewDepartment() const;
		Department() = default;

	private:
		short departmentID;
		std::string name;
		long long base_salary;
		int allowance;
		int deduction;
	};
}


#endif // !_Department_h_
