/** @file VTBLEDefines.h
 * @brief profile, service and chararacteristic definition
 * @author Ben.lee
 * [@author <Ben.lee email:Ben.lee@vtrump.com>]
 * @date 2013.10.07
 * @version 1.0
 * @copyright Vtrump
 */

#ifndef VTBLE_DEFINES_H
#define VTBLE_DEFINES_H

#import <CoreBluetooth/CoreBluetooth.h>

#define BLE_PROFILE_SCALE               @"VScale Private"
#define BLE_SERVICE_DEVICE_INFO         @"device info"

#pragma mark -
#pragma mark bluetooth SIG profiles

#pragma mark -
#pragma mark bluetooth SIG profiles

#define BLE_GENERIC_ACCESS_SERVICE_UUID                     0x1800
#define BLE_GENERIC_ATTRIBUTE_SERVICE_UUID                  0x1801


// Control service

#define BLE_CONTROL_SERVICE_UUID                            @"ffffffff-7B48-43DB-B8C5-7928A6B0A335"

//Immediate Alert
#define BLE_IMMEDIATE_ALERT_SERVICE_UUID                    0x1802
#define BLE_IMMEDIATE_ALERT_PROPERTY_UUID                   0x2a06
#define BLE_IMMEDIATE_ALERT_HIGH_VAL                        0x02
#define BLE_IMMEDIATE_ALERT_MILD_VAL                        0x01
#define BLE_IMMEDIATE_ALERT_OFF_VAL                         0x00
#define BLE_IMMEDIATE_ALERT_WRITE_LEN                       1


//Tx Power
#define BLE_TX_PWR_SERVICE_UUID                             0x1804
#define BLE_TX_PWR_NOTIFICATION_UUID                        0x2a07
#define BLE_TX_PWR_NOTIFICATION_READ_LEN                    1


//Device Info
#define BLE_DEVICE_INFO_SERVICE_UUID                        0x180a
#define BLE_DEVICE_INFO_MANUFACTURE_NAME_UUID               0x2a29
#define BLE_DEVICE_INFO_MODEL_NUMBER_UUDI                   0x2a24
#define BLE_DEVICE_INFO_SERIAL_NUMBER_UUID                  0x2a25
#define BLE_DEVICE_INFO_HARDWARE_VERSION_UUID               0x2a27
#define BLE_DEVICE_INFO_FIRMWARE_VERSION_UUID               0x2a26
#define BLE_DEVICE_INFO_SOFTWARE_VERSION_UUID               0x2a28
#define BLE_DEVICE_INFO_SYSTEM_ID_UUID                      0x2a23
#define BLE_DEVICE_INFO_IEEE_UUID                           0x2a2a
#define BLE_DEVICE_INFO_PNP_ID_UUID                         0x2a50

//Battery
#define BLE_BATTERY_SERVICE_UUID                            0x180f
#define BLE_BATTERY_CHARACTERISTIC_UUID                     0x2a19
#define BLE_BATTERY_CHARACTERISTIC_LEN                      1

//Link loss
#define BLE_LINK_LOSS_SERVICE_UUID                          0x1803
#define BLE_LINK_LOSS_PROPERTY_UUID                         0x2a06
#define BLE_LINK_LOSS_ALERT_HIGH_VAL                        0x02
#define BLE_LINK_LOSS_ALERT_MILD_VAL                        0x01
#define BLE_LINK_LOSS_ALERT_OFF_VAL                         0x00
#define BLE_LINK_LOSS_PROPERTY_LEN                             1

#endif
