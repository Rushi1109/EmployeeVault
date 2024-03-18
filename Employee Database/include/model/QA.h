#ifndef _QA_h_
#define _QA_h_
#include "Employee.h"

namespace EmployeeDB::Model {

    class QA : public Employee {
    public:
        QA() : testingTool{ "" } {}
        QA(bool isUpdateObj) : Employee{ isUpdateObj }, testingTool{ "#" } {}

        const std::string& getTestingTool() const {
            return testingTool;
        }

        void setTestingTool(const std::string& tool) {
            testingTool = tool;
        }

        double computeSalary() override { return 10.2; };
    private:
        std::string testingTool;
    };
}

#endif