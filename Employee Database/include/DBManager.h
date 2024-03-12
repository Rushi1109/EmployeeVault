#ifndef _DBmanager_h_
#define _DBmanager_h_

#include "sqlite3.h"
#include <string>

namespace EmployeeDB {

	class DBManager {
	public:
		static DBManager& instance();

		int executeQuery(const char*);
		int executeSelectQuery(const char*, int (*)(void*, int, char**, char**) = DBManager::callback, void* = 0);

	private:
		DBManager();
		~DBManager();

		void openConnection();
		void closeConnection();

		static int callback(void*, int, char**, char**);

		sqlite3* db;
		int resultCode;
		char* errMsg;
	};
}


#endif // !_DBmanager_h_
