#ifndef __TableControllerTest_h__
#define __TableControllerTest_h__

#include "./include/controller/TableController.h"

using EmployeeDB::Controller::TableController;

class TableControllerTest : public TableController {
public:
	static std::string getCreateTableQuery(Table& table) {
		return TableController::getCreateTableQuery(table);
	}
};

#endif // !__TableControllerTest_h__
