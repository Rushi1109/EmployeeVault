#ifndef __DBmanager_h__
#define __DBmanager_h__

#include "sqlite3.h"
#include <string>

namespace EmployeeDB {

	class DBManager {
	public:
		static DBManager& instance();

		int executeQuery(const char* query);
		int executeSelectQuery(const char* query);
		int executeCustomQuery(const char* query, int (*callback)(void*, int, char**, char**), void* arg);
		int executeRowCountQuery(const char* queryString);
		static void executeCascadeQuery();

	private:
		DBManager();
		~DBManager();

		void openConnection();
		void closeConnection();

		static int selectCallback(void* arg, int argc, char** argv, char** azColName);
		static int rowCountCallback(void* arg, int argc, char** argv, char** azColName);

		sqlite3* db;
		int resultCode;
		char* errMsg;
	};
}


#endif // !_DBmanager_h_
