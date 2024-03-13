#include <iostream>
#include <exception>
#include "DBManager.h"
#include "ManagerController.h"
#include "Model.h"

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::DBManager;

int main() {
    DBManager& db = DBManager::instance();
    db.executeCascadeQuery();

    ManagerController::selectAllManager();

    return 0;
}