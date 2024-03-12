#include <iostream>
#include <exception>
#include "DBManager.h"
#include "DepartmentController.h"
#include "Model.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

int main() {
    DBManager& db = DBManager::instance();
    db.executeQuery("PRAGMA foreign_keys = ON");

    DepartmentController::selectAllDepartmentIDAndName();

    return 0;
}