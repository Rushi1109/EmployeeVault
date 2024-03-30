#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validator.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Validator;

void EmployeeView::printEmployeeFields() {
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining* :" << '\n';
	std::cout << "10. mentorID :" << '\n';
	std::cout << "11. performanceMetric :" << '\n';
	std::cout << "12. bonus :" << '\n';
}

void EmployeeView::printViewEmployeeFields() {
	std::cout << "1. employeeID* : " << '\n';
	std::cout << "2. firstName* : " << '\n';
	std::cout << "3. middleName* : " << '\n';
	std::cout << "4. lastName* : " << '\n';
	std::cout << "5. dateOfBirth* : " << '\n';
	std::cout << "6. mobileNo* : " << '\n';
	std::cout << "7. email* :" << '\n';
	std::cout << "8. address* :" << '\n';
	std::cout << "9. gender* :" << '\n';
	std::cout << "10. dateOfJoining* :" << '\n';
	std::cout << "11. mentorID* :" << '\n';
	std::cout << "12. performanceMetric* :" << '\n';
	std::cout << "13. bonus* :" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& employee) {
	{
		auto firstName = Utility::getUserInputString("firstName");
		employee.setFirstName(firstName.value());
	}

	{
		auto middleName = Utility::getUserInputString("middleName", 0, false);
		employee.setMiddleName(middleName);
	}

	{
		auto lastName = Utility::getUserInputString("lastName");
		employee.setLastName(lastName.value());
	}

	{
		auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validator::validateDate, false);
		employee.setDateOfBirth(dateOfBirth);
	}

	{
		auto mobileNo = Utility::getUserInputLL("mobileNo");
		employee.setMobileNo(mobileNo.value());
	}

	{
		auto email = Utility::getUserInputString("email", Validator::validateEmail);
		employee.setEmail(email.value());
	}

	{
		auto address = Utility::getUserInputString("address");
		employee.setAddress(address.value());
	}

	{
		auto gender = Utility::getUserInputString("gender", Validator::validateGender);
		employee.setGender(Model::getGenderFromString(gender.value()));
	}

	{
		auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validator::validateDate);
		employee.setDateOfJoining(dateOfJoining.value());
	}

	{
		auto mentorID = Utility::getUserInputInt("mentorID", 0, false);
		employee.setMentorID(mentorID);
	}

	{
		auto performanceMetric = Utility::getUserInputDouble("performanceMetric", false);
		employee.setPerformanceMetric(performanceMetric);
	}

	{
		auto bonus = Utility::getUserInputDouble("bonus", false);
		employee.setBonus(bonus);
	}
}

void EmployeeView::getUpdateEmployeeInput(Employee& employee, int fieldNumber) {
	switch (fieldNumber) {
		case 1:
		{
			auto firstName = Utility::getUserInputString("firstName");
			employee.setFirstName(firstName.value());
		}
		break;

		case 2:
		{
			auto middleName = Utility::getUserInputString("middleName", 0, false);
			employee.setMiddleName(middleName);
		}
		break;

		case 3:
		{
			auto lastName = Utility::getUserInputString("lastName");
			employee.setLastName(lastName.value());
		}
		break;

		case 4:
		{
			auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validator::validateDate, false);
			employee.setDateOfBirth(dateOfBirth);
		}
		break;

		case 5:
		{
			auto mobileNo = Utility::getUserInputLL("mobileNo");
			employee.setMobileNo(mobileNo.value());
		}
		break;

		case 6:
		{
			auto email = Utility::getUserInputString("email", Validator::validateEmail);
			employee.setEmail(email.value());
		}
		break;

		case 7:
		{
			auto address = Utility::getUserInputString("address");
			employee.setAddress(address.value());
		}
		break;

	case 8:
		{
			auto gender = Utility::getUserInputString("gender", Validator::validateGender);
			employee.setGender(Model::getGenderFromString(gender.value()));
		}
		break;

		case 9:
		{
			auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validator::validateDate);
			employee.setDateOfJoining(dateOfJoining.value());
		}
		break;

		case 10:
		{
			auto mentorID = Utility::getUserInputInt("mentorID");
			employee.setMentorID(mentorID);
		}
		break;

		case 11:
		{
			auto performanceMetric = Utility::getUserInputDouble("performanceMetric", false);
			employee.setPerformanceMetric(performanceMetric);
		}
		break;

		case 12:
		{
			auto bonus = Utility::getUserInputDouble("bonus", false);
			employee.setBonus(bonus);
		}
		break;
	}
}

void EmployeeView::getViewEmployeeInput(Employee& employee, int fieldNumber) {
	switch (fieldNumber) {
		case 1:
		{
			auto employeeID = Utility::getUserInputInt("employeeID");
			employee.setEmployeeID(employeeID.value());
		}
		break;

		case 2:
		{
			auto firstName = Utility::getUserInputString("firstName");
			employee.setFirstName(firstName.value());
		}
		break;

		case 3:
		{
			auto middleName = Utility::getUserInputString("middleName");
			employee.setMiddleName(middleName);
		}
		break;

		case 4:
		{
			auto lastName = Utility::getUserInputString("lastName");
			employee.setLastName(lastName.value());
		}
		break;

		case 5:
		{
			auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validator::validateDate, true);
			employee.setDateOfBirth(dateOfBirth);
		}
		break;

		case 6:
		{
			auto mobileNo = Utility::getUserInputLL("mobileNo");
			employee.setMobileNo(mobileNo.value());
		}
		break;

		case 7:
		{
			auto email = Utility::getUserInputString("email", Validator::validateEmail);
			employee.setEmail(email.value());
		}
		break;

		case 8:
		{
			auto address = Utility::getUserInputString("address");
			employee.setAddress(address.value());
		}
		break;

		case 9:
		{
			auto gender = Utility::getUserInputString("gender", Validator::validateGender);
			employee.setGender(Model::getGenderFromString(gender.value()));
		}
		break;

		case 10:
		{
			auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validator::validateDate);
			employee.setDateOfJoining(dateOfJoining.value());
		}
		break;

		case 11:
		{
			auto mentorID = Utility::getUserInputInt("mentorID");
			employee.setMentorID(mentorID);
		}
		break;

		case 12:
		{
			auto performanceMetric = Utility::getUserInputDouble("performanceMetric", true);
			employee.setPerformanceMetric(performanceMetric);
		}
		break;

		case 13:
		{
			auto bonus = Utility::getUserInputDouble("bonus", true);
			employee.setBonus(bonus);
		}
		break;
	}
}

void EmployeeView::getEmployeeIDInput(Employee& employee, const std::string& operation, const std::string& entity) {
	system("cls");
	std::cout << "------------------------------------------" << "\033[0;36m" << operation + " " + entity << "\033[0m" << "------------------------------------------------- \n";
	std::cout << "Please enter employeeID.\n";

	auto employeeID = Utility::getUserInputInt("employeeID", Validator::validateEmployeeID, entity);
	employee.setEmployeeID(employeeID.value());
}