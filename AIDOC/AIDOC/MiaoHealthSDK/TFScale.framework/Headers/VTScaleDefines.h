/** @file VTScaleDefines.h
 * @brief profile, service and chararacteristic definition
 * @author Ben.lee
 * [@author <Ben.lee email:Ben.lee@vtrump.com>]
 * @date 2013.10.07
 * @version 1.0
 * @copyright Vtrump
 */

#ifndef VTScaleDefines_h
#define VTScaleDefines_h

#import "VTBLEDefines.h"

#define BLE_PROFILE_SCALE                                   @"VScale Private"

// Scale
#define BLE_SCALE_SERVICE_UUID                              @"f433bd80-75b8-11e2-97d9-0002a5d5c51b"
#define BLE_SCALE_TEST_RESULT_CHARACTERISTIC_UUID           @"1a2ea400-75b9-11e2-be05-0002a5d5c51b"
#define BLE_SCALE_USER_INFO_CHARACTERISTIC_UUID             @"23b4fec0-75b9-11e2-972a-0002a5d5c51b"
#define BLE_SCALE_SET_USER_CHARACTERISTIC_UUID              @"29f11080-75b9-11e2-8bf6-0002a5d5c51b"


#define cGetServiceUUID [NSMutableArray arrayWithObjects:\
[CBUUID UUIDWithString:@"0x1800"],\
[CBUUID UUIDWithString:@"0x1801"],\
[CBUUID UUIDWithString:@"0x180a"],\
[CBUUID UUIDWithString:BLE_SCALE_SERVICE_UUID],\
nil];\

#define Format_ModelNumber_Version_Type(modelNumber)    ((modelNumber & 0xFFFF0000)>>16)
#define SCALE_VERSION_TYPE_VALID_VALUE  0x0103

/*vscale type*/
#define VT_DEVICE_VSCALE               (0x03)
#define VT_VSCALE_DEFAULT              (0x00)
#define VT_VSCALE_FAT                  (0x01)
#define VT_VSCALE_KIDS                 (0x02)
#define VT_VSCALE_WEIGHT               (0x03)

#endif
