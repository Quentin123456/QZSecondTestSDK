//
//  BrickManager.h
//  BrickSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <BrickSDK/BrickCompleteResult.h>

NS_ASSUME_NONNULL_BEGIN

@interface BrickManager : NSObject


/// SDK初始化
/// - Parameters:
///   - appKey: 初始化Key
///   - appSecret: 初始化Secret
///   - bindId: 使用SDK需要传入不能为空
+ (void)initBrickWith:(NSString *)appKey appSecret:(NSString *)appSecret bindId:(NSString *)bindId;

#pragma mark - 微信登录

/// WXApi的成员函数，向微信终端程序注册第三方应用。
/// - Parameters:
///   - appid: appid 微信开发者ID
///   - universalLink: 微信开发者Universal Link
+ (BOOL)wechatRegisterAppWith:(NSString *)appid universalLink:(NSString *)universalLink;


/// 判断微信是否安装
+ (BOOL)isWXAppInstalled;

/// 微信登录
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
+ (void)wechatLoginSuccess:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

#pragma mark - 苹果登录

/// 苹果登录
/// - Parameters:
///   - controller: 苹果登录所在页面的控制器
///   - success: 成功回调
///   - failure: 失败回调
+ (void)appleLoginFrom:(UIViewController *)controller success:(nullable BrickComplete)success failure:(nullable BrickComplete)failure API_AVAILABLE(ios(13.0));

#pragma mark - QQ登录

/// 判断QQ是否安装
+ (BOOL)iphoneQQInstalled;

/// QQ登录
/// - Parameters:
///   - appId: 初始化TencentOAuth对象 appId 不可为nil，第三方应用在互联开放平台申请的唯一标识
///   - success: 成功回调
///   - failure: 失败回调
+ (void)qqLoginWithAppId:(NSString *)appId success:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

/// QQ登录
/// - Parameters:
///   - appId: 初始化TencentOAuth对象 appId 不可为nil，第三方应用在互联开放平台申请的唯一标识
///   - universalLink: universalLink 可以为nil，第三方应用在互联开放平台注册的UniversalLink，和bundleID一一对应（当为nil时，互联平台会按规则生成universallink，详见官网说明）
///   - success: 成功回调
///   - failure: 失败回调
+ (void)qqLoginWithAppId:(NSString *)appId
        andUniversalLink:(NSString *)universalLink success:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

#pragma mark - 支付宝支付

/// 支付宝支付
/// - Parameters:
///   - order: 支付订单信息字串
///   - productId: 产品号
///   - money: 金额
///   - userId: 用户ID
///   - extraData: 透传数据（需要SDK返回的数据）
///   - userAgent: User-Agent
///   - scheme: 调用支付的app注册在info.plist中的scheme
///   - success: 成功回调
///   - failure: 失败回调
+ (void)alipayFromOrder:(NSString *)order productId:(NSString *)productId money:(NSString *)money userId:(NSString *)userId extraData:(NSString *)extraData userAgent:(NSString *)userAgent withScheme:(NSString *)scheme andCallBackSuccess:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

/// 支付宝支付
/// - Parameters:
///   - order:  支付订单信息字串
///   - productId: 产品号
///   - money: 金额
///   - userId: 用户ID
///   - extraData: 透传数据（需要SDK返回的数据）
///   - userAgent: User-Agent
///   - dynamicLaunch: 是否使用动态配置策略跳转支付宝支付
///   - scheme: 调用支付的app注册在info.plist中的scheme
///   - success: 成功回调
///   - failure: 失败回调
+ (void)alipayFromOrder:(NSString *)order productId:(NSString *)productId money:(NSString *)money userId:(NSString *)userId extraData:(NSString *)extraData userAgent:(NSString *)userAgent dynamicLaunch:(BOOL)dynamicLaunch withScheme:(NSString *)scheme andCallBackSuccess:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

/// 商户接入UniversalLink支付接口使用该接口
/// - Parameters:
///   - order: 支付订单信息字串
///   - productId: 产品号
///   - money: 金额
///   - userId: 用户ID
///   - extraData: 透传数据（需要SDK返回的数据）
///   - userAgent: User-Agent
///   - scheme: 调用支付的app注册在info.plist中的scheme
///   - universalLink: 调用支付的app关联的universalLink,如'https://render.alipay.com/'
///   - success: 成功回调
///   - failure: 失败回调
+ (void)alipayFromOrder:(NSString *)order productId:(NSString *)productId money:(NSString *)money userId:(NSString *)userId extraData:(NSString *)extraData userAgent:(NSString *)userAgent withScheme:(NSString *)scheme universalLink:(NSString *)universalLink andCallBackSuccess:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

#pragma mark - 微信支付

/// 微信支付
/// - Parameters:
///   - orderInfo: 订单信息
///   - productId: 产品号
///   - money: 金额
///   - userId: 用户ID
///   - extraData: 透传数据（需要SDK返回的数据）
///   - userAgent: User-Agent
///   - success: 成功回调
///   - failure: 失败回调
+ (void)wechatPayFromOrderInfo:(NSString *)orderInfo productId:(NSString *)productId money:(NSString *)money userId:(NSString *)userId extraData:(NSString *)extraData userAgent:(NSString *)userAgent success:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;


#pragma mark - 处理系统调用

/// 处理登录通过URL启动App时传递的数据
/// - Parameter url: 第三方应用时传递过来的URL
+ (BOOL)brickLoginHandleOpenURL:(NSURL *)url;


/// 处理登录通过Universal Link启动App时传递的数据
/// - Parameter userActivity: 系统API传递过来的userActivity
+ (BOOL)brickLoginHandleOpenUniversalLink:(NSUserActivity *)userActivity;


/// 处理支付通过URL启动App时传递的数据
/// - Parameter url: 第三方应用时传递过来的URL
+ (BOOL)brickPayHandleOpenURL:(NSURL *)url;

/// 处理支付通过Universal Link启动App时传递的数据
/// - Parameter userActivity: 系统API传递过来的userActivity
+ (BOOL)brickPayHandleOpenUniversalLink:(NSUserActivity *)userActivity;

#pragma mark - 苹果内购支付

/// 校验该设备是否可以支付
+ (BOOL)canMakePayments;


/// 内购
/// - Parameter productsId: 产品id
///   - money: 金额
///   - orderId: 订单号
///   - userId: 用户ID
///   - extraData: 透传数据（需要SDK返回的数据）
///   - userAgent: User-Agent
///   - success: 成功回调
///   - failure: 失败回调
+ (void)appleInPurchaseFromProductsId:(NSString *)productsId orderId:(NSString *)orderId money:(NSString *)money userId:(NSString *)userId extraData:(NSString *)extraData userAgent:(NSString *)userAgent success:(nullable BrickComplete)success failure:(nullable BrickComplete)failure;

@end

NS_ASSUME_NONNULL_END
