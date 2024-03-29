#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include "ExportController.h"
#include "DBManager.h"
#include "Config.h"

using EmployeeDB::Controller::ExportController;
using EmployeeDB::DBManager;

void ExportController::removeCommas(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return c == ','; }), str.end());
}

int ExportController::exportCallback(void* arg, int argc, char** argv, char** azColName) {
    auto& [columnNamesWritten, outStream] = *(static_cast<std::tuple<bool, std::ofstream>*>(arg));

    if (!columnNamesWritten) {
        for (int i = 0; i < argc; i++) {
            outStream << azColName[i];
            if (i < argc - 1) {
                outStream << ",";
            }
        }
        outStream << std::endl;
        columnNamesWritten = true;
    }

    for (int i = 0; i < argc; i++) {
        std::string value = (argv[i] ? argv[i] : "NULL");
        removeCommas(value);
        outStream << value;
        if (i < argc - 1) {
            outStream << ",";
        }
    }
    outStream << std::endl;
    return 0;
}

bool ExportController::exportToCSV(const std::string& entity, std::filesystem::path filename) {
    std::string queryString = "SELECT * FROM " + entity + ";";

    filename += ".csv";
    std::filesystem::path filepath = EmployeeDB::Config::CSVFilePath / filename;

    std::ofstream outStream{ filepath };
    if (!outStream) {
        std::cerr << "\033[31m" << entity << " Could not be exported to " << filename << "\033[0m\n";
        return false;
    }

    std::tuple<bool, std::ofstream> tuple(false, std::move(outStream));

    try {
        DBManager::instance().executeCustomQuery(queryString.c_str(), exportCallback, &tuple);
        std::cout << "\033[32m" << "Successfully exported " << entity << " to " << "\033[0m";
        std::cout << "\033[36m" << filepath << "\033[0m\n";
    }
    catch (const std::exception& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m\n";
        std::cerr << "\033[31m" << entity << " Could not be exported to " << filename << "\033[0m\n";
        return false;
    }
    return true;
}

bool ExportController::exportAll() {
    auto result{ true };
    auto count{ 0 };

    result = exportToCSV("Department", "DepartmentBackup");
    if (result) {
        count++;
    }

    result = exportToCSV("Employee", "EmployeeBackup");
    if (result) {
        count++;
    }

    result = exportToCSV("Engineer", "EngineerBackup");
    if (result) {
        count++;
    }

    result = exportToCSV("Finance", "FinanceBackup");
    if (result) {
        count++;
    }

    result = exportToCSV("HR", "HRBackup");
    if (result) {
        count++;
    }

    result = exportToCSV("QA", "QABackup");
    if (result) {
        count++;
    }

    result = exportToCSV("Manager", "ManagerBackup");
    if (result) {
        count++;
    }

    std::cout << (count == 7 ? "\033[32m" : "\033[31m") << count << "\033[0m";
    std::cout << "\033[32m" << "/" << "\033[0m";
    std::cout << "\033[32m" << "7 " << "\033[0m";
    std::cout << "\033[32m" << "Files Exported." << "\033[0m\n";
    std::cout << "\033[33m" << "You can find all the exported csv files at : " << "\033[0m";
    std::cout << "\033[36m" << EmployeeDB::Config::CSVFilePath << "\033[0m\n";

    return count;
}