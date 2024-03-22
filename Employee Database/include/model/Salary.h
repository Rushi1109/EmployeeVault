#ifndef __Salary_h__
#define __Salary_h__

namespace EmployeeDB::Model {

    class Salary {
    public:
        Salary() :
            m_EmployeeID{ 0 },
            m_DepartmentID{ 0 },
            m_PerformanceMetric{ 0.0 },
            m_Bonus{ 0.0 },
            m_BaseSalary{ 0.0 },
            m_Allowance{ 0.0 },
            m_Deduction{ 0.0 } {}

        int getEmployeeID() const {
            return m_EmployeeID;
        }
        void setEmployeeID(int employeeID) {
            m_EmployeeID = employeeID;
        }

        int getDepartmentID() const {
            return m_DepartmentID;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
        }

        double getPerformanceMetric() const {
            return m_PerformanceMetric;
        }
        void setPerformanceMetric(double performanceMetric) {
            m_PerformanceMetric = performanceMetric;
        }

        double getBonus() const {
            return m_Bonus;
        }
        void setBonus(double bonus) {
            m_Bonus = bonus;
        }

        double getBaseSalary() const {
            return m_BaseSalary;
        }
        void setBaseSalary(double baseSalary) {
            m_BaseSalary = baseSalary;
        }

        double getAllowance() const {
            return m_Allowance;
        }
        void setAllowance(double allowance) {
            m_Allowance = allowance;
        }

        double getDeduction() const {
            return m_Deduction;
        }
        void setDeduction(double deduction) {
            m_Deduction = deduction;
        }

    private:
        int m_EmployeeID;
        int m_DepartmentID;
        double m_PerformanceMetric;
        double m_Bonus;
        double m_BaseSalary;
        double m_Allowance;
        double m_Deduction;
    };
}

#endif