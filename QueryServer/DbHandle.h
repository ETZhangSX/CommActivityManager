#ifndef _COMMACTIVITYMANAGER_DBHANDLE_
#define _COMMACTIVITYMANAGER_DBHANDLE_

#include "util/tc_singleton.h"
#include "util/tc_thread_rwlock.h"
#include "util/tc_shared_ptr.h"
#include "util/tc_thread.h"
#include "util/tc_mysql.h"
#include <vector>
#include <string>
#include <map>
#include "Query.h"

using namespace std;

class CommunityHandle: public tars::TC_Singleton<CommunityHandle>
{
public:
    int LoadDataFromDb();

public:
    vector<CommActivityManager::CommunityItem> vCommItem;
};

class UserHandle: public tars::TC_Singleton<UserHandle>
{
public:
    int LoadDataFromDb();
public:
    map<string, CommActivityManager::UserInfo> mUserInfo;
};

#endif