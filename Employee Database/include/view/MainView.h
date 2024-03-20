#ifndef __MainView_h__
#define __MainView_h__

namespace EmployeeDB::View {
	class MainView {
	public: 
		static void mainMenuView();
	private:
		static void printMainMenu();
		static void mainMenuSelection(short int userInput);

		static void printTableMenu();

		static void insertMenuView();
		static void insertMenuSelection(short int userInput);

		static void updateMenuView();
		static void updateMenuSelection(short int userInput);

		static void deleteMenuView();
		static void deleteMenuSelection(short int userInput);

		static void viewMenuView();
		static void viewMenuSelection(short int userInput);
	};
}

#endif // !__MainView_h__
