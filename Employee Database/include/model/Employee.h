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

        Name() : firstName{ "" }, middleName{ std::nullopt }, lastName{ "" } {}
        Name(bool isUpdateName) : firstName{ "#" }, middleName{ std::nullopt }, lastName{ "#" } {}
    };

    class Employee {
    public:
        Employee() :
            name{},
            email{ "" },
            address{ "" },
            dateOfBirth{ std::nullopt },
            dateOfJoining{ "" },
            performanceMetric{ std::nullopt },
            mobileNo{ 0 },
            gender{ Gender::Male },
            employeeID{ 0 },
            departmentID{ 0 },
            mentorID{ std::nullopt },
            bonus{ std::nullopt } {
        }

        Employee(bool isUpdateEmployee) :
            name{ isUpdateEmployee },
            email{ "#" },
            address{ "#" },
            dateOfBirth{ std::nullopt },
            dateOfJoining{ "#" },
            performanceMetric{ std::nullopt },
            mobileNo{ -1 },
            gender{ Gender::Other },
            employeeID{ -1 },
            departmentID{ -1 },
            mentorID{ std::nullopt },
            bonus{ std::nullopt } {
        }

        int getEmployeeID() const {
            return employeeID;
        }

        void setEmployeeID(int id) {
            employeeID = id;
        }

        const std::string getFirstName() const {
            return name.firstName;
        }

        void setFirstName(const std::string& firstName) {
            name.firstName = firstName;
        }

        const std::optional<std::string> getMiddleName() const {
            return name.middleName;
        }

        void setMiddleName(const std::optional<std::string>& middleName) {
            name.middleName = middleName;
        }

        const std::string getLastName() const {
            return name.lastName;
        }

        void setLastName(const std::string& lastName) {
            name.lastName = lastName;
        }

        const std::optional<std::string> getDateOfBirth() const {
            return dateOfBirth;
        }

        void setDateOfBirth(const std::optional<std::string>& dob) {
            dateOfBirth = dob;
        }

        long long getMobileNo() const {
            return mobileNo;
        }

        void setMobileNo(long long number) {
            mobileNo = number;
        }

        const std::string getEmail() const {
            return email;
        }

        void setEmail(const std::string& emailAddress) {
            email = emailAddress;
        }

        const std::string getAddress() const {
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

        const std::string getDateOfJoining() const {
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

        std::optional<int> getMentorID() const {
            return mentorID;
        }

        void setMentorID(std::optional<int> id) {
            mentorID = id;
        }

        std::optional<double> getPerformanceMetric() const {
            return performanceMetric;
        }

        void setPerformanceMetric(std::optional<double> metric) {
            performanceMetric = metric;
        }

        std::optional<double> getBonus() const {
            return bonus;
        }

        void setBonus(std::optional<double> b) {
            bonus = b;
        }

    private:
        int	employeeID;
        Name name;
        std::optional<std::string> dateOfBirth;
        long long mobileNo;
        std::string email;
        std::string address;
        Gender gender;
        std::string dateOfJoining;
        int departmentID;
        std::optional<int> mentorID;
        std::optional<double> performanceMetric;
        std::optional<double> bonus;
    };

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
        auto gender{ Gender::Male };

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

