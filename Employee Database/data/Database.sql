CREATE TABLE "Department" (
	"departmentID"	INTEGER NOT NULL UNIQUE,
	"departmentName"	TEXT NOT NULL UNIQUE,
	"baseSalary"	REAL NOT NULL,
	"allowance"	REAL NOT NULL,
	"deduction"	REAL NOT NULL,
	PRIMARY KEY("departmentID" AUTOINCREMENT)
);

CREATE TABLE "Employee" (
	"employeeID"	INTEGER NOT NULL UNIQUE,
	"firstName"	TEXT NOT NULL,
	"middleName"	TEXT,
	"lastName"	TEXT NOT NULL,
	"dateOfBirth"	TEXT,
	"mobileNo"	NUMERIC NOT NULL UNIQUE,
	"email"	TEXT NOT NULL UNIQUE,
	"address"	TEXT NOT NULL,
	"gender"	TEXT NOT NULL,
	"dateOfJoining"	TEXT NOT NULL,
	"departmentID"	INTEGER,
	"mentorID"	INTEGER,
	"performanceMetric"	REAL,
	"bonus"	REAL,
	PRIMARY KEY("employeeID" AUTOINCREMENT),
	UNIQUE("employeeID")
);

CREATE TABLE "Manager" (
	"managerID"	INTEGER NOT NULL,
	"departmentID"	INTEGER NOT NULL,
	"teamSize"	INTEGER NOT NULL,
	"yearsOfExp"	REAL NOT NULL,
	"projectTitle"	TEXT,
	"technology"	TEXT,
	PRIMARY KEY("managerID","departmentID"),
	FOREIGN KEY("managerID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE,
	FOREIGN KEY("departmentID") REFERENCES "Department"("departmentID") ON DELETE CASCADE
);

CREATE TABLE "Engineer" (
	"employeeID"	INTEGER NOT NULL,
	"technology"	TEXT,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);

CREATE TABLE "QA" (
	"employeeID"	INTEGER NOT NULL,
	"testingTool"	TEXT,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);

CREATE TABLE "Finance" (
	"employeeID"	INTEGER NOT NULL,
	"accountingSoftware"	TEXT,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);

CREATE TABLE "HR" (
	"employeeID"	INTEGER NOT NULL,
	"hrSpecialization"	TEXT,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);