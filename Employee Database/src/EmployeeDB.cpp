#include "EmployeeDB.h"
#include "DBManager.h"
#include "MainView.h"

void EmployeeDB::run() {
	EmployeeDB::DBManager::executeConfigQuery();
	EmployeeDB::View::MainView::mainMenuView();
}