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

        const std::string& getTechnology() const {
            return technology;
        }

        void setTechnology(const std::string& tech) {
            technology = tech;
        }

    private:
        int managerID;
        int departmentID;
        short int teamSize;
        int yearsOfExperience;
        std::string projectTitle;
        std::string technology;
    };
}

#endif