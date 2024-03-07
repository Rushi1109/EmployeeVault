#ifndef _HR_h_
#define _HR_h_

#include "Employee.h"

namespace EmployeeDB::Model {

    class HR : public Employee {
    public:
        double computeSalary() override { return 10.2; };

        HR() noexcept = default;

        const std::string& getHRSpecialization() const {
            return hrSpecialization;
        }

        void setHRSpecialization(const std::string& specialization) {
            hrSpecialization = specialization;
        }
    private:
        std::string hrSpecialization;
    };
}

#endif
