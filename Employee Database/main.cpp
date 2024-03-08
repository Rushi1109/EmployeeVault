#include <iostream>
#include "DBManager.h"
#include "Model.h"
#include "QAController.h"
#include "DepartmentController.h"
#include "EmployeeController.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::QA, EmployeeDB::Controller::QAController;
using EmployeeDB::Model::Department, EmployeeDB::Controller::DepartmentController;
using EmployeeDB::Controller::EmployeeController;

int main() {
    DBManager& db = DBManager::instance();
    db.executeQuery("PRAGMA foreign_keys = ON");

    //QA dummyEmployee;

    //// Set dummy values for all attributes
    //dummyEmployee.setFirstName("Rushi");
    //dummyEmployee.setMiddleName("Mineshkumar");
    //dummyEmployee.setLastName("Gandhi");
    //dummyEmployee.setEmail("joDo@example.com");
    //dummyEmployee.setAddress("123 Main St, Cityville");
    //dummyEmployee.setDateOfBirth("1990-01-01");
    //dummyEmployee.setDateOfJoining("2020-05-15");
    //dummyEmployee.setPerformanceMetric(4.5);
    //dummyEmployee.setMobileNo(7283902430);
    //dummyEmployee.setGender(EmployeeDB::Model::Gender::Male);
    //dummyEmployee.setManagerID(201);
    //dummyEmployee.setBonus(50000);
    //dummyEmployee.setTestingTool("Chai-Mocha");

    //QAController::insertQA(dummyEmployee);

    //db.executeSelectQuery("SELECT Employee.*, QA.testingTool FROM Employee INNER JOIN QA ON Employee.employeeID = QA.employeeID;");

    //std::cout << db.getResultString() << '\n';

    std::cout << DepartmentController::selectDepartmentIDbyName("QA") << '\n';

    std::cout << EmployeeController::deleteEmployee(12) << '\n';

    return 0;
}