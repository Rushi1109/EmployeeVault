#ifndef _DBmanager_h_
#define _DBmanager_h_

#include "sqlite3.h"

namespace EmployeeDB {

	class Database {
	public:
		static Database& instance();

		int execute(const char* sql);
		int executeQuery(const char* sql, int (*callback)(void*, int, char**, char**), void*);

	private:
		Database();
		~Database();

		void openConnection();
		void closeConnection();

		sqlite3* db;
		int status;
		char* errMsg;
	};
}


#endif // !_DBmanager_h_
