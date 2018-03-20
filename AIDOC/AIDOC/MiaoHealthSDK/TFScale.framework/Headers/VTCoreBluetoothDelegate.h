/** @file VTCoreBluetoothDelegate.h
 * @brief coreBluetooth delegate wrapper
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.14
 * @version 0.91
 * @copyright Vtrump
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>

/**
 *	@brief	wrapper of coreBluetooth delegate. Client app could ignore it.
 */
@protocol VTPeripheralDelegate

@optional
-(void) didUpdateCharacteristicValue:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic;
-(void) didWriteCharacteristicValue:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
-(void) didUpdateTxPower:(CBPeripheral *)peripheral TxPwr:(char)TXPwr;
- (void)didUpdateRSSI:(CBPeripheral *)peripheral;
-(void) didPeripheralServiceReady:(CBPeripheral *)peripheral;

@required
-(void) didPeripheralDiscovered:(CBPeripheral *)peripheral pushedData:(NSDictionary *)pushedData RSSI:(NSNumber *)RSSI;
-(void) didPeripheralConnected:(CBPeripheral *)peripheral;
-(void) didPeripheralServiceDiscovered:(CBPeripheral *)peripheral;
-(void) didPeripheralDisconnected: (CBPeripheral *) peripheral error:(NSError *)error;
-(void) didPeripheralFailToConnect: (CBPeripheral *)peripheral error:(NSError *)error;
-(void) didPeripheralRetrieved:(CBPeripheral *)peripheral;
-(void) didConnectedPeripheralRetrieved:(CBPeripheral *)peripheral isConnected:(bool)isConnected;
-(void) didUpdateStatus: (CBCentralManagerState)status;
@end

