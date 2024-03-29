#ifndef __Manager_h__
#define __Manager_h__

#include <optional>
#include "Employee.h"

namespace EmployeeDB::Model {

    class Manager : public Employee {
    public:
        Manager() : 
            managerID{ 0 },
            departmentID{ 0 },
            teamSize{ 0 },
            yearsOfExperience{0}, 
            projectTitle{ std::nullopt }, 
            role{ std::nullopt } {
        }

        Manager(bool isUpdateObj) : Employee(isUpdateObj),
            managerID{ 0 },
            departmentID{ 0 },
            teamSize{ 0 },
            yearsOfExperience{ 0 },
            projectTitle{ std::nullopt },
            role{ std::nullopt } {
        }

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

        double getYearsOfExperience() const {
            return yearsOfExperience;
        }

        void setYearsOfExperience(double years) {
            yearsOfExperience = years;
        }

        const std::optional<std::string> getProjectTitle() const {
            return projectTitle;
        }

        void setProjectTitle(const std::string& title) {
            projectTitle = title;
        }

        const std::optional<std::string> getRole() const {
            return role;
        }

        void setRole(const std::string& rl) {
            role = rl;
        }

    private:
        int managerID;
        int departmentID;
        int teamSize;
        double yearsOfExperience;
        std::optional<std::string> projectTitle;
        std::optional<std::string> role;
    };
}

#endif