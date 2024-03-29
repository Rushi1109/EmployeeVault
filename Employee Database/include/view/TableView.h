#ifndef __TableView_h__
#define __TableView_h__

#include <vector>

namespace EmployeeDB::View {
	class TableView {
	public:
		static bool createTableView();
		static bool deleteTableView();

	private:
		static void getColumnsInput(std::vector<std::array<std::string,3>>& columnsVector);
		static void getForeignKeysInput(std::vector<std::array<std::string, 4>>& foreignKeysVector);
	};
}


#endif // !__TableView_h__
