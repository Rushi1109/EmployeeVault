#include "../../include/controller/ExportControllerTest.h"
#include "../../pch.h"

TEST(TestExportController, Test_removecommas) {
	std::string stringToTest{"88, Vikramnagar Soc., L.H. Road, Surat"};

	ExportControllerTest::removecommas(stringToTest);

	ASSERT_STREQ("88 Vikramnagar Soc. L.H. Road Surat", stringToTest.c_str());
}