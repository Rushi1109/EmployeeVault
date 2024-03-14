#ifndef _HR_h_
#define _HR_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class HR : public Employee {
    public:
        HR() : hrSpecialization{ "" } {}
        HR(bool isUpdateObj) : Employee{ isUpdateObj }, hrSpecialization{ "#" } {}

        const std::string& getHRSpecialization() const {
            return hrSpecialization;
        }

        void setHRSpecialization(const std::string& specialization) {
            hrSpecialization = specialization;
        }

        double computeSalary() override { return 10.2; };
    private:
        std::string hrSpecialization;
    };
}

#endif
