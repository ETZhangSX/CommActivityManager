#include <iostream>
#include <vector>

std::string buildSelectSQL(const std::string &sTableName, const std::vector<std::string> &mpColumns, const std::string &sWhereFilter);
std::string buildSelectSQL(const std::string &sTableName, const std::string &mpColumn, const std::string &sWhereFilter);