#ifndef __MainView_h__
#define __MainView_h__

namespace EmployeeDB::View {
	class MainView {
	public: 
		static void mainMenuView();
	private:
		static void printMainMenu();
		static void mainMenuSelection(int userInput);

		static void printTableMenu();

		static void tableMenuView();
		static void tableMenuSelection(int userInput);

		static void insertMenuView();
		static void insertMenuSelection(int userInput);

		static void updateMenuView();
		static void updateMenuSelection(int userInput);

		static void deleteMenuView();
		static void deleteMenuSelection(int userInput);

		static void viewMenuView();
		static void viewMenuSelection(int userInput);

		static void printExportTableMenu();

		static void exportMenuView();
		static bool exportMenuSelection(int userInput);
	};
}

#endif // !__MainView_h__
