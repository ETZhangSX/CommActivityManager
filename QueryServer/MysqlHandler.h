#ifndef _MYSQLHANDLER_H_
#define _MYSQLHANDLER_H_

#include "util/tc_thread.h"
#include "util/tc_mysql.h"
#include "util/tc_singleton.h"
#include "util/tc_shared_ptr.h"
#include "util/tc_thread_rwlock.h"
// #include "servant/TarsLogger.h"
#include "util/tc_lock.h"
#include "util/tc_monitor.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include "Query.h"

using namespace tars;

class MDbQueryRecord: public TC_Singleton<MDbQueryRecord>
{
public:
    tars::TC_Mysql * GetMysqlObject();

private:
    tars::TC_DBConf                     _tcDbConfig;
    tars::TC_SharedPtr<tars::TC_Mysql>  _pMysql;
    
    map<unsigned int, tars::TC_Mysql *> MysqlMap;
};

class MDbExcuteRecord: public tars::TC_Thread, public tars::TC_Singleton<MDbExcuteRecord>
{
public:
    bool Init();
    void AddExcuteSql(const string& strSql);
    void Excute();

protected:
    virtual void run();

private:
    tars::TC_DBConf                     _tcDbConfig;
    queue<string>                       _qeWaitExeSql;
    tars::TC_SharedPtr<tars::TC_Mysql>  _pMysql;
    tars::TC_ThreadLock                 _pLocker;
};

#endif