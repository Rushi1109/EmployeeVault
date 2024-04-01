#ifndef __TableFixture_h__
#define __TableFixture_h__

#include "../../pch.h"
#include "Table.h"

using EmployeeDB::Model::Table;

class TableFixture : public ::testing::Test {
protected:
	void SetUp() override {
		table = std::make_unique<Table>();

		table->setTableName("Manager");
		
		std::vector<std::array<std::string, 3>> columns;
		columns.reserve(3);
		std::vector<std::array<std::string, 4>> foreignKeys;

		columns.emplace_back(std::move(std::array<std::string, 3>{"ID", "INT", "NOT NULL UNIQUE PRIMARY KEY"}));
		columns.emplace_back(std::move(std::array<std::string, 3>{"DepartmentName", "TEXT", "NOT NULL"}));
		columns.emplace_back(std::move(std::array<std::string, 3>{"teamSize", "INT"}));

		table->setAttributesVector(columns);

		foreignKeys.emplace_back(std::move(std::array<std::string, 4>{"DepartmentName", "Department", "departmentName", "ON DELETE CASCADE"}));

		table->setForeignKeysVector(foreignKeys);

		emptyTable = std::make_unique<Table>();
		emptyTable->setTableName("Roles");
	}

	std::unique_ptr<Table> table;
	std::unique_ptr<Table> emptyTable;
};

#endif // !__TableFixture_h__
