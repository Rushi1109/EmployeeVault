#ifndef _Manager_h_
#define _Manager_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class Manager : public Employee {
    public:
        double computeSalary() override { return 10.2; };

        Manager() noexcept = default;

        int getDepartmentID() const {
            return departmentID;
        }

        void setDepartmentID(int id) {
            departmentID = id;
        }

        short int getTeamSize() const {
            return teamSize;
        }

        void setTeamSize(short int size) {
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
            return projectTitle;
        }

        void setRole(const std::string& rl) {
            role = rl;
        }

    private:
        //int manager_id;
        int departmentID;
        short int teamSize;
        int yearsOfExperience;
        std::string projectTitle;
        std::string role;
    };
}

#endif