#ifndef __Table_h__
#define __Table_h__

#include <string>
#include <vector>
#include <array>

namespace EmployeeDB::Model {
    class Table {
    public:
        const std::string getTableName() const {
            return tableName;
        }
        void setTableName(const std::string& name) {
            tableName = name;
        }

        const std::vector<std::array<std::string, 3>> getAttributesVector() const {
            return attributesVector;
        }
        void setAttributesVector(const std::vector<std::array<std::string, 3>>& attributeVector) {
            attributesVector = attributeVector;
        }

        const std::vector<std::array<std::string, 4>> getForeignKeysVector() const {
            return foreignKeysVector;
        }
        void setForeignKeysVector(const std::vector<std::array<std::string, 4>>& foreignKeyVector) {
            foreignKeysVector = foreignKeyVector;
        }

    private:
        std::vector<std::array<std::string, 3>> attributesVector;
        std::vector<std::array<std::string, 4>> foreignKeysVector;
        std::string tableName;
    };
}


#endif