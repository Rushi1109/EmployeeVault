#ifndef _Finance_h_
#define _Finance_h_
#include "Employee.h"

namespace EmployeeDB::Model {

    class Finance : public Employee {
    public:
        double computeSalary() override { return 10.2; };

        Finance() noexcept = default;

        const std::string& getAccountingSoftware() const {
            return accountingSoftware;
        }

        void setAccountingSoftware(const std::string& software) {
            accountingSoftware = software;
        }

    private:
        std::string accountingSoftware;
    };
}

#endif