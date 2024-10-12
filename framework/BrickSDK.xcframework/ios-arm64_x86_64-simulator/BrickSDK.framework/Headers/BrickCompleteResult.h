//
//  BrickCompleteResult.h
//  BrickSDK
//

#import <Foundation/Foundation.h>

@class BrickCompleteResult;

NS_ASSUME_NONNULL_BEGIN

/** 定义回调结果 */
typedef void(^BrickComplete)(BrickCompleteResult * completeResult);

@interface BrickCompleteResult : NSObject

/** 接口返回code */
@property (assign, nonatomic) NSInteger code;

/** 接口返回message */
@property (copy,nonatomic,nullable) NSString *message;

/** 接口返回data */
@property (copy, nonatomic, nullable) NSDictionary *data;

/** 错误处理 */
@property (strong, nonatomic, nullable) NSError *error;


/// 初始化方法
/// - Parameters:
///   - code: 接口返回code
///   - message: 接口返回message
///   - data: 接口返回data
///   - error: 错误处理
+ (instancetype)brick_CompleteWithCode:(NSInteger)code message:(NSString *)message data:(nullable NSDictionary *)data  error:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
