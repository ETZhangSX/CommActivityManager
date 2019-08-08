#ifndef _QueryImp_H_
#define _QueryImp_H_

#include "servant/Application.h"
#include "Query.h"

/**
 *
 *
 */
class QueryImp : public CommActivityManager::Query
{
public:
    /**
     *
     */
    virtual ~QueryImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;};
    
    /**
     * @brief 获取用户信息
     *
     * @param sUserId   用户wx_id
     * @param sRsp      服务响应结果, Tars协议自定义类型UserInfo
     * @return          服务调用状态码
     */
    virtual tars::Int32 getUserInfo(const std::string &sUserId, CommActivityManager::UserInfo &sRsp, tars::TarsCurrentPtr current);
    
    /**
     * @brief 获取活动列表
     *
     * @param sUserId   用户wx_id
     * @param sRsp      服务响应结果, Tars协议自定义类型ActivityItem的vector序列对象
     * @return          服务调用状态码
     */
    virtual tars::Int32 getActivityList(vector<CommActivityManager::ActivityItem> &sRsp, tars::TarsCurrentPtr current);

    /**
     * @brief 获取活动详情
     *
     * @param activityId   活动id
     * @param sRsp         服务响应结果, Tars协议自定义类型ActivityItem
     * @return             服务调用状态码
     */
    virtual tars::Int32 getActivityDetail(const std::string &activityId, CommActivityManager::ActivityItem &sRsp, tars::TarsCurrentPtr current);

    /**
     * @brief 获取社团列表
     *
     * @param sRsp      服务响应结果, Tars协议自定义类型CommunityItem的vector序列对象
     * @return          服务调用状态码
     */
    virtual tars::Int32 getCommunityList(vector<CommActivityManager::CommunityItem> &sRsp, tars::TarsCurrentPtr current);
    
    /**
     * @brief 获取社团详情
     *
     * @param sRsp      服务响应结果, Tars协议自定义类型CommunityItem的vector序列对象
     * @return          服务调用状态码
     */
    virtual tars::Int32 getCommunityDetail(const std::string &commId, CommActivityManager::CommunityInfo &sRsp,tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
