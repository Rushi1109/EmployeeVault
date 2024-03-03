#ifndef _Employee_h_
#define _Employee_h_

#include<string>

enum class gender
{
	male, female, other
};

class Employee {
public:
	virtual void computeSalary() = 0;

	void insertEmployee() const;
	void deleteEmployee() const;
	void viewEmployee() const;
	void updateEmployee() const;

	Employee() noexcept = default;

	Employee(int ID,
		std::string fName,
		std::string mName,
		std::string lName,
		std::string dob,
		long long moNo,
		std::string mail,
		std::string add,
		gender gen,
		std::string doj,
		short dID,
		int mID,
		float Metric,
		int Bonus) noexcept : employeeID{ ID }, firstName{ fName }, middleName{ mName }
		, lastName{ lName }, dateOfBirth{ dob }, mobileNo{ moNo }, email{ mail },
		address{ add }, gender{ gen }, dateOfJoining{ doj }, departmentID{ dID },
		managerID{ mID }, performanceMetric{ Metric }, bonus{ Bonus }
	{}

private:
	int	employeeID;
	std::string firstName;
	std::string middleName;
	std::string lastName;
	std::string dateOfBirth;
	long long mobileNo;
	std::string email;
	std::string address;
	gender gender;
	std::string dateOfJoining;
	short departmentID;
	int managerID;
	float performanceMetric;
	int bonus;
};

class Manager : public Employee {
public:
	void computeSalary() override;

	void insertManager() const;
	void deleteManager() const;
	void updateManager() const;
	void viewManager() const;

	Manager() noexcept = default;

private:
	//int manager_id;
	int departmentID;
	short int teamSize;
	int yearsOfExperience;
	std::string projectTitle;
};

class HR : public Employee {
public:
	void computeSalary() override;

	HR() noexcept = default;
private:
	std::string hrSpecialization;
};

class QA : public Employee {
public:
	void computeSalary() override;

	QA() noexcept = default;
private:
	std::string testingTool;
};

class Engineer : public Employee {
public:
	void computeSalary() override;

	Engineer() noexcept = default;
private:
	std::string programmingLanguage;
};

class Finance : public Employee {
public:
	void computeSalary() override;

	Finance() noexcept = default;
private:
	std::string accountingSoftware;
};


#endif // !

