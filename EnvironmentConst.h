//
//  EnvironmentConst.h
//  laoyuegou
//
//  Created by smalljun on 17/7/17.
//  Copyright © 2017年 HaiNanLexin. All rights reserved.
//

#ifndef EnvironmentConst_h
#define EnvironmentConst_h

/*
 *
 *  这个文件主要用于配置app环境相关的参数，并对相关参数和步骤进行说明解释（对打包ipa时不同参数意义进行说明）
 *
 *  项目中目前有LYGInternational、laoyuegou两个主项目的Target，它们分别配置各自的环境参数，包括BundleId、DisplayName、证书、URL Scheme、icons和闪屏等
 *  而LYGInternationalNotifServiceExtension和NotificationServiceExtension分别是上面两个Target的APNS扩展
 *  LYGInternational是主目录下的一个文件夹，专门用于放置海外版的配置文件、类文件和资源文件
 */


/**
 *   LYGID 是项目setting配置中的一个预编译宏变量,通过不同的值来区分不同项目，从而实现代码层面的差异化
 *   LYGID == 1001，代表国内版项目
 *   LYGID == 2001，代表海外版项目
 *   主要和LYAppProjectType对应的值进行比较
 */


#define LYAppProjectTypeChina           1001                     //代表国内版项目
#define LYAppProjectTypeInternational   2001                     //代表海外版项目

/**
 *  配置在DEBUG模式下，输入log信息，否则屏蔽掉
 */
#ifdef DEBUG
//#define NSLog(...) NSLog(__VA_ARGS__)
#define LYString [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define NSLog(...) printf("%s File:%s Line:%d %s\n\n",[[NSString currentDateStringWithLog] UTF8String],[LYString UTF8String],__LINE__,[[NSString stringWithFormat:__VA_ARGS__] UTF8String]);
#else
#define NSLog(...)
#endif

//1 为开发环境 2为store产品环境  3为测试环境 4为企业产品环境 5为预发布环境
#ifndef BUILD_EVO

#define BUILD_EVO 3
 
#endif

//是否开启 支持HTTPS   0：关闭https ，   1：开启https
#define HTTPS_ENABLE    1

//是否开启上报日志(环境切换),1上报，0不上报
#ifndef LY_REPORT_LOG
    #define LY_REPORT_LOG 1
//头文件内容
#endif

#if LYGID == LYAppProjectTypeInternational
    #define AppChanel @"g999"
    #define LYG_APP_KEY @"2001"
    #define LYG_APP_SECRET @"glyg#2001#app"
    #define APP_ID @"1168869134"             //苹果开发者appid
#else
    #define AppChanel @"999"
    #define LYG_APP_KEY @"1001"
    #define LYG_APP_SECRET @"lyg#1001#app"
    #define APP_ID @"998249583"             //苹果开发者appid
#endif

//手机平台参数，1代表ios
#define AppPlatform @"1"

#endif /* EnvironmentConst_h */
