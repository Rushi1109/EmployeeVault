#ifndef __TableController_h__
#define __TableController_h__

#include "Table.h"

using EmployeeDB::Model::Table;

namespace EmployeeDB::Controller {
	class TableController {
	public:
		static bool createTable(Table& table);
		static bool deleteTable(const std::string& tableName);
	protected:
		static std::string getCreateTableQuery(Table& table);
	};
}

#endif // !__TableController_h__
