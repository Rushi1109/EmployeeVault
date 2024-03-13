#ifndef _Manager_h_
#define _Manager_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class Manager : public Employee {
    public:
        double computeSalary() override { return 10.2; };

        Manager() noexcept = default;

        int getManagerID() const {
            return managerID;
        }

        void setManagerID(int id) {
            managerID = id;
        }

        int getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(int id) {
            departmentID = id;
        }

        int getTeamSize() const {
            return teamSize;
        }

        void setTeamSize(int size) {
            teamSize = size;
        }

        int getYearsOfExperience() const {
            return yearsOfExperience;
        }

        void setYearsOfExperience(int years) {
            yearsOfExperience = years;
        }

        const std::string& getProjectTitle() const {
            return projectTitle;
        }

        void setProjectTitle(const std::string& title) {
            projectTitle = title;
        }

        const std::string& getRole() const {
            return role;
        }

        void setRole(const std::string& rl) {
            role = rl;
        }

    private:
        int managerID;
        int departmentID;
        int teamSize;
        int yearsOfExperience;
        std::string projectTitle;
        std::string role;
    };
}

#endif