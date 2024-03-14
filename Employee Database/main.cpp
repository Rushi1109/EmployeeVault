#include <iostream>
#include <exception>
#include "DBManager.h"
#include "ManagerController.h"

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::DBManager;

int main() {
    DBManager::executeCascadeQuery();

	Manager m;
	m.setManagerID(2);
	m.setDepartmentID(1);
	m.setTeamSize(5);
	m.setYearsOfExperience(5.5);
	m.setProjectTitle("CPP Project");
	m.setRole("CPP");

	ManagerController::insertManager(m);

    ManagerController::selectManager();

    return 0;
}