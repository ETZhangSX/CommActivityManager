#ifndef _DBOPERATION_CONFIG_
#define _DBOPERATION_CONFIG_

#include "util/tc_singleton.h"
#include "util/tc_config.h"
#include <string>

class SConfig: public tars::TC_Singleton<SConfig>
{
    public:
    int usPort;
    string strDbHost;
    string strUserName;
    string strPassWord;
    string strDbName;
    int maxMatch;

    public:
    void LoadConfig(const std::string &strConfFileName)
    {
        tars::TC_Config tcConfig;
        tcConfig.parseFile(strConfFileName);
        string s1 = "/DbOperation/";

        usPort = atoi(tcConfig.get(s1+"<usPortConfig>", "").c_str());
        strDbHost = tcConfig.get(s1+"<strDbHostConfig>", "").c_str();
        strUserName = tcConfig.get(s1+"<strUserNameConfig>", "").c_str();
        strPassWord = tcConfig.get(s1+"<strPassWordConfig>", "").c_str();
        strDbName = tcConfig.get(s1+"<strDbNameConfig>", "").c_str();

        maxMatch = atoi(tcConfig.get(s1+"<maxMatch>", "100").c_str());
    }
};

#endif