#ifndef _Engineer_h_
#define _Engineer_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class Engineer : public Employee {
    public:
        Engineer() : technology{ "" } {}
        Engineer(bool isUpdateObj) : Employee{ isUpdateObj }, technology{ "#" } {}

        const std::string& getTechnology() const {
            return technology;
        }

        void setTechnology(const std::string& tech) {
            technology = tech;
        }

        double computeSalary() override { return 10.2; };
    private:
        std::string technology;
    };
}

#endif
