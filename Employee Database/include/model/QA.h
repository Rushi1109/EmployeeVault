#ifndef _QA_h_
#define _QA_h_
#include "Employee.h"

namespace EmployeeDB::Model {

    class QA : public Employee {
    public:
        void computeSalary() override;

        QA() noexcept = default;

        const std::string& getTestingTool() const {
            return testingTool;
        }

        void setTestingTool(const std::string& tool) {
            testingTool = tool;
        }
    private:
        std::string testingTool;
    };
}

#endif
