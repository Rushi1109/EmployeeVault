#ifndef __Employee_h__
#define __Employee_h__

#include <string>
#include <algorithm>
#include <optional>
#include "Salary.h"

namespace EmployeeDB::Model {
    enum class Gender
    {
        Male, Female, Other
    };

    struct Name {
        std::string firstName;
        std::optional<std::string> middleName;
        std::string lastName;

        Name() : firstName{ "" }, middleName{ "" }, lastName{ "" } {}
        Name(bool isUpdateName) : firstName{ "#" }, middleName{ "#" }, lastName{ "#" } {}
    };

    class Employee {
    public:
        Employee() :
            name{},
            email{ "" },
            address{ "" },
            dateOfBirth{ "" },
            dateOfJoining{ "" },
            performanceMetric{ 0.0 },
            mobileNo{ 0 },
            gender{ Gender::Male },
            employeeID{ 0 },
            departmentID{ 0 },
            mentorID{ 0 },
            bonus{ 0.0 } {
        }

        Employee(bool isUpdateEmployee) :
            name{ isUpdateEmployee },
            email{ "#" },
            address{ "#" },
            dateOfBirth{ "#" },
            dateOfJoining{ "#" },
            performanceMetric{ -1.0 },
            mobileNo{ -1 },
            gender{ Gender::Other },
            employeeID{ -1 },
            departmentID{ -1 },
            mentorID{ -1 },
            bonus{ -1.0 } {
        }

        int getEmployeeID() const {
            return employeeID;
        }

        void setEmployeeID(int id) {
            employeeID = id;
        }

        const std::string& getFirstName() const {
            return name.firstName;
        }

        void setFirstName(const std::string& firstName) {
            name.firstName = firstName;
        }

        const std::string& getMiddleName() const {
            return name.middleName.value();
        }

        void setMiddleName(const std::string& middleName) {
            name.middleName = middleName;
        }

        const std::string& getLastName() const {
            return name.lastName;
        }

        void setLastName(const std::string& lastName) {
            name.lastName = lastName;
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

        int getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(int id) {
            departmentID = id;
        }

        int getMentorID() const {
            return mentorID;
        }

        void setMentorID(int id) {
            mentorID = id;
        }

        double getPerformanceMetric() const {
            return performanceMetric;
        }

        void setPerformanceMetric(double metric) {
            performanceMetric = metric;
        }

        double getBonus() const {
            return bonus;
        }

        void setBonus(double b) {
            bonus = b;
        }

        static inline double computeSalary(Salary& obj);
    private:
        int	employeeID;
        Name name;
        std::string dateOfBirth;
        long long mobileNo;
        std::string email;
        std::string address;
        Gender gender;
        std::string dateOfJoining;
        int departmentID;
        int mentorID;
        double performanceMetric;
        double bonus;
    };

    inline double Employee::computeSalary(Salary& obj) {
        double totalSalary{ 0.0 };

        totalSalary += obj.getBaseSalary();
        totalSalary += obj.getAllowance();
        totalSalary -= obj.getDeduction();
        totalSalary += obj.getBonus();
        totalSalary += (obj.getBaseSalary() * (obj.getPerformanceMetric() / 100));

        return totalSalary;
    }

    inline std::string getGenderString(Gender g) {
        std::string tempStr{ "Male" };
        switch (g) {
        case EmployeeDB::Model::Gender::Male:
            break;
        case EmployeeDB::Model::Gender::Female:
            tempStr = "Female";
            break;
        case EmployeeDB::Model::Gender::Other:
            tempStr = "Other";
            break;
        }
        return tempStr;
    }

    inline Gender getGenderFromString(std::string& genderString) {
        Gender gender{ Gender::Male };

        std::transform(genderString.begin(), genderString.end(), genderString.begin(), ::tolower);
        if (genderString == "male") {
            gender = Gender::Male;
        }
        else if (genderString == "female") {
            gender = Gender::Female;
        }
        else if (genderString == "other") {
            gender = Gender::Other;
        }
        return gender;
    }
}

#endif // !

