#include <iostream>
#include <exception>
#include "DBManager.h"
#include "EngineerController.h"

using EmployeeDB::Controller::EngineerController;
using EmployeeDB::DBManager;

int main() {
	DBManager::executeCascadeQuery();

	Engineer e{ true };

	e.setEmployeeID(1);
	e.setFirstName("Rushi");
	e.setMiddleName("Mineshkumar");
	e.setLastName("Gandhi");
	e.setDateOfBirth("11-09-2002");
	e.setMobileNo(5252552256);
	e.setEmail("rushi.gandhi@google.com");
	e.setAddress("Gujarat, India");
	e.setDateOfJoining("01-01-2024");
	e.setPerformanceMetric(5.00);
	e.setBonus(10050000.5);
	e.setTechnology("CPP, Unreal");

	EngineerController::updateEngineer(e);

	EngineerController::selectEngineer("employeeID", "1");
}