CREATE TABLE "Employee" (
	"id"	INTEGER NOT NULL UNIQUE,
	"firstName"	TEXT NOT NULL,
	"middleName"	TEXT,
	"lastName"	TEXT NOT NULL,
	"dob"	INTEGER,
	"mobileNo"	NUMERIC NOT NULL UNIQUE,
	"email"	INTEGER NOT NULL UNIQUE,
	"address"	TEXT NOT NULL,
	"gender"	INTEGER NOT NULL,
	"doj"	INTEGER NOT NULL,
	"departmentID"	INTEGER,
	"managerID"	INTEGER,
	"performanceMetric"	REAL,
	"bonus"	NUMERIC,
	PRIMARY KEY("id" AUTOINCREMENT),
	UNIQUE("id")
);