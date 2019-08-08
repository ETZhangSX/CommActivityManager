#include <sstream>
#include "util.h"

using namespace std;

string buildSelectSQL(const string &sTableName,const vector<string> &mpColumns, const string &sWhereFilter)
{
    ostringstream sColumnNameSet;

    vector<string>::const_iterator itEnd = mpColumns.end();

    for(vector<string>::const_iterator it = mpColumns.begin(); it != itEnd; ++it)
    {
        if (it == mpColumns.begin())
        {
            sColumnNameSet << *it;
        }
        else
        {
            sColumnNameSet << ", " << *it;
        }
    }

    ostringstream os;
    os << "select " << sColumnNameSet.str()
       << " from " << sTableName;
    if (sWhereFilter != "")
       os << " where " << sWhereFilter;

    return os.str();
}

string buildSelectSQL(const string &sTableName,const string &mpColumn, const string &sWhereFilter)
{
    ostringstream os;
    os << "select " << mpColumn
       << " from " << sTableName;
    if (sWhereFilter != "")
       os << " where " << sWhereFilter;

    return os.str();
}