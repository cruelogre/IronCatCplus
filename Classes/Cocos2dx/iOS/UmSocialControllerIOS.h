//
//  UmSocialControllerIOS.h
//  UmengGame
//
//  Created by 张梓琦 on 14-3-16.
//
//

#ifndef __UmengGame__UmSocialControllerIOS__
#define __UmengGame__UmSocialControllerIOS__

#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "CCUMTypeDef.h"
#include <string>
#include <vector>

#define CC_ShareToWechat       1
#define CC_ShareToQQOrQzone    0
#define CC_ShareToLaiWang      0
#define CC_ShareToYiXin        0
#define CC_ShareToFacebook     0
#define CC_ShareToTwitter      0
#define CC_ShareToInstagram    0

using namespace std;
using namespace umeng::social;

class UmSocialControllerIOS {
public:
    
    //设置SDK的appkey
    static void setAppKey(const char* appKey);
    
    //初始化sdk
    static void initCocos2dxSDK(const char *sdkType, const char *version);

    //设置分享的url
    static void setTargetUrl(const char * targetUrl);
    
    //授权某社交平台
    static void authorize(int platform, std::function<void(int,int,const map<string, string>&)> callback);
    
    //解除某平台授权
    static void deleteAuthorization(int platform,std::function<void(int,int,const map<string, string>&)> callback);
    
    //是否已经授权某平台
    static bool isAuthorized(int platform);
    
    //打开分享面板
    static void openShareWithImagePath(vector<int>* platform, const char* text, const char* imagePath,std::function<void(int,int,const string&)> callback);
    
//    //设置分享的平台
    static void setSharePlatforms(vector<int>* platform);
    
    //直接分享到各个社交平台
    static void directShare(const char* text, const char* imagePath, int platform, std::function<void(int,int,const string&)> callback);
    
    //打开SDK的log输出
    static void openLog(bool flag);
    
    //设置QQ互联appid，appkey
    static void setQQAppIdAndAppKey(const char *appId,const char *appKey);

    //设置微信appid,appSecret
    static void setWechatAppId(const char *appId, const char *appSecret);

    //打开各个平台SSO开关,redirectURL
    static void openSSOAuthorization(int platform, const char *redirectURL);
    
    //分别设置各个分享平台内容
    static void setPlatformShareContent(int platform, const char* text,
                                 const char* imagePath, const char* title,
                                 const char* targetUrl);
    
    //设置来往appid，appkey
    static void setLaiwangAppInfo(const char *appId, const char *appKey, const char * appName);

    //设置易信appid
    static void setYiXinAppKey(const char *appKey);
    
    //设置Facebook的appid
    static void setFacebookAppId(const char *appId);

    //打开Twitter的开关
    static void openTwitter();

    //打开Instagram的开关
    static void openInstagram();
    
private:
    static string m_appKey;
};
#endif
#endif /* defined(__UmengGame__UmSocialControllerIOS__) */
