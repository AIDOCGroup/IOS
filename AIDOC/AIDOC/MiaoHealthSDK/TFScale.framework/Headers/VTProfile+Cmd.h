/** @file VTProfile+Cmd.h
 * @brief category of vtble command profile. What commands are supported depends on the capabilities of the device.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"

/**
 *	@brief	command extension of VTProfile. 
 */
@interface VTProfile (Cmd)


/**
 *	@brief	check if command profile is supported
 *
 *	@return	YES or NO
 */
- (BOOL) hasCmdProfile;


/**
 *	@brief	set device standby. 
 *
 *	@param 	device 	device to set command
 */
- (void) suspendDevice:(VTDeviceModel*)device;

/**
 *	@brief	change device to broadcast mode
 *
 *	@param 	device 	device to set command
 */
- (void) gotoBroadcast:(VTDeviceModel*)device;

/**
 *	@brief	change device to oad mode
 *
 *	@param 	device 	device to set command
 */
- (void) gotoOadMode:(VTDeviceModel*)device;

/**
 *	@brief	Save power with (intervalMin:500, intervalMax:1000, latency: 0, Timeout:6000)
 *
 *	@param 	device 	device to set command.
 */
- (void) savePower:(VTDeviceModel*)device;

/**
 *	@brief	Send fast with (intervalMin:30, intervalMax:60, latency: 1, timeout:1000)
 *
 *	@param 	device 	device to set command.
 */
- (void) sendFast:(VTDeviceModel*)device;


/**
 *	@brief	Set parameters according to connection interval params.
 *
 * The connection parameter request may be rejected if it does not comply with
 * all of these rules:
 * Interval Max * (Slave Latency + 1) ≤ 2 seconds Interval Min ≥ 20 ms
 * Interval Min + 20 ms ≤ Interval Max
 * Slave Latency ≤ 4
 * connSupervisionTimeout ≤ 6 seconds
 * Interval Max * (Slave Latency + 1) * 3 < connSupervisionTimeout
 *
 *	@param 	device 	device to set command
 *	@param 	intervalMin 	minimum interval of connection (ms)
 *	@param 	intervalMax 	maximum interval of connection (ms)
 *	@param 	latency 	latency
 *	@param 	timeout 	time out of connection (ms)
 */
- (void) setConnectionInterval:(VTDeviceModel*)device intervalMin:(UInt16)intervalMin intervalMax:(UInt16)intervalMax latency:(UInt16)latency timeout:(UInt16)timeout;


/**
 *	@brief	set txPower of  device
 *
 *	@param 	device 	device to set command
 *	@param 	txPower 	txpower in DB. 
 */
- (void) setTxPower:(VTDeviceModel*)device txPower:(SInt8)txPower;


/**
 *	@brief	General Set Test Command method. It's used for internal command test.
 *
 *	@param 	device 	device to set command.
 *	@param 	commandName 	command name
 *	@param 	commandParam 	command params different with command parameters
 */
- (void) sendTestCommand:(VTDeviceModel*)device commandName:(NSString *)commandName commandParam:(NSString *)commandParam;


/**
 *	@brief	Tag Command. Set to adjust the disconnection/connection alert sensitivity. Tag will enter lazy mode to smooth the alerting.
 *
 *	@param 	device 	Tag Device to set command
 *	@param 	repeatCount 	repeat count of disconnection/connection. 
 *	@param 	repeatTimer 	repeat timer of disconnection/connection.
 *	@param 	lazyTimer 	timer of lazy mode.
 */
- (void) setTagAlertSensitivity:(VTDeviceModel *)device repeatCount:(UInt8)repeatCount repeatTimer:(UInt16)repeatTimer lazyTimer:(UInt16)lazyTimer;


/**
 *	@brief	write duty ration to adjust the parameters of PWM.
 *
 *	@param 	device 	device to write
 *  @param  channel of pwm output
 *  @param  frequency frequency of PWM
 *	@param 	dutyRation 	duty ration of PWM.
 */
- (void) writePwmOutput:(VTDeviceModel *)device channel:(UInt8)channel frequency:(UInt8)frequency dutyRation:(UInt8)dutyRation;


/**
 *	@brief	adjust the led output level
 *
 *	@param 	device 	device to write
 *	@param 	ledId 	led id
 *	@param 	level 	led output level, from 0 to 100
 */
- (void) writeLedOutput:(VTDeviceModel *)device ledId:(UInt8)ledId level:(UInt8)level;

/**
 *	@brief	write RGB color of 3 color LED
 *
 *	@param 	device 	device to write
 *	@param 	red 	red led, 0x00 to 0xff.
 *	@param 	green 	green led, 0x00 to 0xff.
 *	@param 	blue 	blue led, 0x00 to 0xff.
 */
- (void) writeRGBLebOutput:(VTDeviceModel *)device red:(UInt8)red green:(UInt8)green blue:(UInt8)blue;


/**
 *	@brief	write a group of commands to device once
 *
 *	@param 	device 	device to write
 *	@param 	commands 	commands data, it's composited by a series of VT commands. less than 255 bytes
 */
- (void) writeGroupCommand:(VTDeviceModel *)device commands:(NSData *)commands;


/**
 *	@brief	add a command to an available commands data
 *
 *	@param 	commands 	commmands group, it's used before writeGroupCommand
 *	@param 	command     command to add.
 *	@param 	params 	command params.
 *
 *	@return	commands group.
 */
+ (NSMutableData *)addCommand:(NSMutableData*)commands command:(UInt8)command params:(NSData*)params;



/**
 *	@brief	write interval of broadcasting mode
 *
 *	@param 	device 	device to write
 *	@param 	interval 	interval of broadcast
 */
- (void) writeBroadcastInterval:(VTDeviceModel*)device interval:(UInt16)interval;

@end
