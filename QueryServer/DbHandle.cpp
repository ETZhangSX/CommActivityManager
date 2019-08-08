#include "DbHandle.h"
#include "Config.h"
#include "servant/TarsLogger.h"

using namespace std;
using namespace tars;

int CommunityHandle::LoadDataFromDb()
{
    TC_Mysql mysql(SConfig::getInstance()->strDbHost, \
			       SConfig::getInstance()->strUserName,\
				   SConfig::getInstance()->strPassWord, \
				   SConfig::getInstance()->strDbName, \
				   "utf8", \
				   SConfig::getInstance()->usPort);

    {
        TC_Mysql::MysqlData oResults;
        try
        {
            /*
            * TODO: 选取字段: 
            *       communities:    community_id, name, chairman, introduction
             */
            oResults = mysql.queryRecord("");
        }
        catch (exception &e)
        {
            LOG->error() << "Community error query: " << e.what() << endl;
            return -1;
        }
        const size_t oResultsCount = oResults.size();

        vCommItem.clear();
        for (size_t i = 0; i < oResultsCount; i++) 
        {
            CommActivityManager::CommunityItem commItem;
            commItem.community_id = TC_Common::strto<tars::Int32>(oResults[i]["community_id"]);
            commItem.name           = oResults[i]["name"];
            commItem.chairman       = oResults[i]["chairman"];
            commItem.introduction   = oResults[i]["introduction"];

            LOG->debug() << "Community Info: " 
                         << oResults[i]["community_id"] << "\t" 
                         << oResults[i]["name"] << "\t"
                         << oResults[i]["chairman"] << "\t"
                         << oResults[i]["introduction"] << endl;
        }
    }
    return 0;
}


int UserHandle::LoadDataFromDb()
{
    TC_Mysql mysql(SConfig::getInstance()->strDbHost, \
			       SConfig::getInstance()->strUserName,\
				   SConfig::getInstance()->strPassWord, \
				   SConfig::getInstance()->strDbName, \
				   "utf8", \
				   SConfig::getInstance()->usPort);

    {
        TC_Mysql::MysqlData oResults;
        try
        {
            /*
            * TODO: 选取字段: 
            *       users:       wx_id, name, phone, gender, registration_time
            *       user_groups: user_type
            * 关联外键: group_id
             */
            oResults = mysql.queryRecord("");
        }
        catch (exception &e)
        {
            LOG->error() << "User Info error query: " << e.what() << endl;
            return -1;
        }
        size_t oResultsCount = oResults.size();

        for (size_t i = 0; i < oResultsCount; i++)
        {
            CommActivityManager::UserInfo userInfo;
            userInfo.name               = oResults[i]["name"];
            userInfo.phone              = oResults[i]["phone"];
            userInfo.gender             = oResults[i]["gender"];
            userInfo.registration_time  = oResults[i]["registration_time"];
            userInfo.group              = oResults[i]["user_type"];

            mUserInfo.insert(make_pair(oResults[i]["wx_id"], userInfo));
            LOG->debug() << oResults[i]["wx_id"] << "\t"
                         << oResults[i]["name"] << "\t"
                         << oResults[i]["user_type"] << endl;
        }
    }
    return 0;
}