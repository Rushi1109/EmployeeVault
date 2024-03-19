#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"

using EmployeeDB::View::EmployeeView;
using EmployeeDB::Controller::EmployeeController;

void EmployeeView::printEmployeeFields() {
	system("cls");
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining*:" << '\n';
	std::cout << "10. managerID*:" << '\n';
	std::cout << "11. performanceMetric*:" << '\n';
	std::cout << "12. bonus*:" << '\n';
}

void EmployeeView::getEmployeeInput(Employee& obj) {
	std::string userInput;
	std::cin.ignore();

	while (true) {
		std::cout << "firstName*: ";
		char a = std::cin.get();
		if (a == '\n') {
			std::cout << "First Name is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::string ans{ "" };
			std::getline(std::cin, ans);
			userInput = a + ans;

			obj.setFirstName(userInput);
			std::cout << obj.getFirstName() << '\n';
			break;
		}
	}
};

bool EmployeeView::deleteEmployee() {
	std::cout << "Please enter ID of employee to delete : \n";

	bool isInvalidInput{ false };

	while (true) {
		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter the ID again : \n";
			isInvalidInput = false;
		}

		int employeeID;
		std::cin >> employeeID;
		if (!std::cin.fail()) {
			if (employeeID > 0) {
				EmployeeController::deleteEmployee(employeeID);
				return true;
			}
			else {
				isInvalidInput = true;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			isInvalidInput = true;
		}
	}
}