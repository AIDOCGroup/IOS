#import <Foundation/Foundation.h>
/** NSQueue 提供上层使用调用时需要注意同步问题 */
@interface CRC:NSObject

+ (uint8_t)crc8:(uint8_t) crc :(void *)ptr :(uint32_t)len;
+ (uint32_t)crc32:(uint32_t) crc :(void *)ptr :(uint32_t)len;

@end
