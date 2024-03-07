#ifndef _Department_h_
#define _Department_h_

#include <string>

namespace EmployeeDB::Model {

	class Department {
	public:
		Department() = default;

        short getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(short id) {
            departmentID = id;
        }

        const std::string& getDepartmentName() const {
            return departmentName;
        }

        void setName(const std::string& deptName) {
            departmentName = deptName;
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
		std::string departmentName;
		double baseSalary;
		double allowance;
		double deduction;
	};
}


#endif // !_Department_h_
