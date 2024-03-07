#ifndef _Engineer_h_
#define _Engineer_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class Engineer : public Employee {
    public:
        double computeSalary() override { return 10.2; };

        Engineer() noexcept = default;

        const std::string& getTechnology() const {
            return technology;
        }

        void setTechnology(const std::string& tech) {
            technology = tech;
        }
    private:
        std::string technology;
    };
}

#endif