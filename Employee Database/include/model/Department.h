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

        short getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(short id) {
            departmentID = id;
        }

        const std::string& getName() const {
            return name;
        }

        void setName(const std::string& employeeName) {
            name = employeeName;
        }

        double getBaseSalary() const {
            return baseSalary;
        }

        void setBaseSalary(double salary) {
            baseSalary = salary;
        }

        double getAllowance() const {
            return allowance;
        }

        void setAllowance(double allowanceAmount) {
            allowance = allowanceAmount;
        }

        double getDeduction() const {
            return deduction;
        }

        void setDeduction(double deductionAmount) {
            deduction = deductionAmount;
        }

	private:
		short departmentID;
		std::string name;
		double baseSalary;
		double allowance;
		double deduction;
	};
}


#endif // !_Department_h_
