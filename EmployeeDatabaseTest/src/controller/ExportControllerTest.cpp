#include "../../include/controller/ExportControllerTest.h"
#include "../../include/fixtures/ExportFixture.h"
#include "../../pch.h"
#include <filesystem>

namespace fs = std::filesystem;

TEST_F(ExportFixture, Test_exportToCSVSuccess) {
	ASSERT_TRUE(ExportController::exportToCSV("Manager", "Manager"));
	ASSERT_TRUE(ExportController::exportToCSV("Employee", "Employee"));
	ASSERT_TRUE(ExportController::exportToCSV("Department", "Department"));

	fs::path exportPath{ "./data/CSVs/Manager.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/Employee.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/Department.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, Test_exportToCSVFailure) {
	ASSERT_FALSE(ExportController::exportToCSV("Maaaaaanager", "Manager"));
}

TEST_F(ExportFixture, Test_exportAll) {
	ASSERT_TRUE(ExportController::exportAll());

	fs::path exportPath{ "./data/CSVs/ManagerBackup.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/EmployeeBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/DepartmentBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/EngineerBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/HRBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/QABackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/CSVs/FinanceBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, Test_removecommas) {
	std::string stringToTest{"34, Grove Street, Ganton, Los Santos"};

	ExportControllerTest::removecommas(stringToTest);

	ASSERT_STREQ("34 Grove Street Ganton Los Santos", stringToTest.c_str());
}