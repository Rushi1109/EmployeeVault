#include <iostream>
#include "DBManager.h"
#include "Model.h"
#include "EngineerController.h"
#include "DepartmentController.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::Engineer, EmployeeDB::Controller::EngineerController;
using EmployeeDB::Model::Department, EmployeeDB::Controller::DepartmentController;

int main() {
    DBManager& db = DBManager::instance();
    db.executeQuery("PRAGMA foreign_keys = ON");

    //Engineer dummyEmployee;

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
    //dummyEmployee.setDepartmentID(101);
    //dummyEmployee.setManagerID(201);
    //dummyEmployee.setBonus(50000);
    //dummyEmployee.setTechnology("Cpp");

    //EngineerController::insertEngineer(dummyEmployee);

    //db.executeSelectQuery("SELECT Employee.*, Engineer.technology FROM Employee INNER JOIN Engineer ON Employee.employeeID = Engineer.employeeID;");
    ////db.executeQuery("DELETE FROM Employee Where employeeID = 11");

    //std::cout << DBManager::getResultString() << '\n';

    Department dept;

    dept.setName("Engineer");
    dept.setBaseSalary(500000.00);
    dept.setAllowance(10000.00);
    dept.setDeduction(1000);

    DepartmentController::insertDepartment(dept);

    std::cout << DepartmentController::selectDepartmentIDbyName("Engineer") << '\n';

    return 0;
}