#ifndef _DBmanager_h_
#define _DBmanager_h_

#include "sqlite3.h"

class Database {
	static Database& instance();


private:
	Database();
	~Database();

	void openConnection();
	void closeConnection();

	sqlite3* db;
	int status;
	char* errMsg;
};


#endif // !_DBmanager_h_
