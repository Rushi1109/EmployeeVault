#ifndef _Employee_h_
#define _Employee_h_

#include<string>

namespace EmployeeDB::Model {
    enum class Gender
    {
        male, female, other
    };

    class Employee {
    public:
        virtual void computeSalary() = 0;

        void insertEmployee() const;
        void deleteEmployee() const;
        void viewEmployee() const;
        void updateEmployee() const;

        Employee() noexcept = default;

        int getEmployeeID() const {
            return employeeID;
        }

        void setEmployeeID(int id) {
            employeeID = id;
        }

        const std::string& getFirstName() const {
            return firstName;
        }

        void setFirstName(const std::string& name) {
            firstName = name;
        }

        const std::string& getMiddleName() const {
            return middleName;
        }

        void setMiddleName(const std::string& name) {
            middleName = name;
        }

        const std::string& getLastName() const {
            return lastName;
        }

        void setLastName(const std::string& name) {
            lastName = name;
        }

        const std::string& getDateOfBirth() const {
            return dateOfBirth;
        }

        void setDateOfBirth(const std::string& dob) {
            dateOfBirth = dob;
        }

        long long getMobileNo() const {
            return mobileNo;
        }

        void setMobileNo(long long number) {
            mobileNo = number;
        }

        const std::string& getEmail() const {
            return email;
        }

        void setEmail(const std::string& emailAddress) {
            email = emailAddress;
        }

        const std::string& getAddress() const {
            return address;
        }

        void setAddress(const std::string& addr) {
            address = addr;
        }

        Gender getGender() const {
            return gender;
        }

        void setGender(Gender g) {
            gender = g;
        }

        const std::string& getDateOfJoining() const {
            return dateOfJoining;
        }

        void setDateOfJoining(const std::string& doj) {
            dateOfJoining = doj;
        }

        short getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(short id) {
            departmentID = id;
        }

        int getManagerID() const {
            return managerID;
        }

        void setManagerID(int id) {
            managerID = id;
        }

        float getPerformanceMetric() const {
            return performanceMetric;
        }

        void setPerformanceMetric(float metric) {
            performanceMetric = metric;
        }

        int getBonus() const {
            return bonus;
        }

        void setBonus(int b) {
            bonus = b;
        }

    private:
        int	employeeID;
        std::string firstName;
        std::string middleName;
        std::string lastName;
        std::string dateOfBirth;
        long long mobileNo;
        std::string email;
        std::string address;
        Gender gender;
        std::string dateOfJoining;
        short departmentID;
        int managerID;
        float performanceMetric;
        int bonus;
    };
}

#endif // !

