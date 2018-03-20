/** @file VTTypes.h
 * @brief vtble types definition
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#ifndef vtshare_vt_device_types_h
#define vtshare_vt_device_types_h

typedef enum
{
    VT_DEVICE_UNKNOWN, /**< unknown device */
	VT_DEVICE_CONNECTABLE, /**< the device could be connected by IOS central */
    VT_DEVICE_ADVERTISE, /**< non-connectable peripheral */


	
} VTDeviceConnectionType_t;


typedef enum
{
    VT_DEVICE_STATUS_INITED, /**< The device is detected by vtble and initialized */
    VT_DEVICE_STATUS_CONNECTED, /**< The device is connected */
    VT_DEVICE_STATUS_DATAREADY, /**< The device is configured and ready for use */
    VT_DEVICE_STATUS_PAIRING, /**< The device is pairing to IOS central, this status is only available for the devices with paired Key */
    VT_DEVICE_STATUS_PAIRED, /**< The device is paired to IOS central, this status is only available for the devices with paired Key */
    VT_DEVICE_STATUS_DISCONNECTING, /**< The device is disconnecting to IOS central */
    VT_DEVICE_STATUS_CLOSING, /**< The device is closing by IOS central */   
    VT_DEVICE_STATUS_DISCONNECTED, /**< The device is disconected to IOS central */ 
    VT_DEVICE_STATUS_ADVERTISE_STARTING, /**< The device is entering advertising from the command gotoBroadcast of VTProfile+Cmd.h */ 
    VT_DEVICE_STATUS_ADVERTISE, /**< The device is an advertising and can't be connected */ 


    
	
} VTDeviceStatusType_t;


typedef enum{
    VT_DEVICE_DISCONNECTED_UNKNOWN, /**< The device is disconnected for the unknonw reason */
    VT_DEVICE_DISCONNECTED_MANUAL, /**< The device is disconnected by IOS central */
    VT_DEVICE_DISCONNECTED_CLOSED, /**< The device is disconnected by IOS central command suspendDevice of VTProfile+Cmd.h */
    VT_DEVICE_DISCONNECTED_LINK_LOSS, /**< The device is disconnected for link loss */
    VT_DEVICE_DISCONNECTED_REJECTED, /**< The device is disconnected for the device rejection */
    VT_DEVICE_DISCONNECTED_CRASH, /**< The device is disconnected for the fatal error of core Bluetooth */
}VTDeviceDisconnnectedReason_t;


typedef enum
{
    VT_ADVERTISE_UNKOWN = 0x0,
    VT_ADVERTISE_SHORT_LINK = 0x20,
    VT_ADVERTISEMENT_DEVICE_MODEL = 0xfe,
    VT_ADVERTISEMENT_PAIRED_KEY = 0xff,
    
}VTAdvertise_t;




typedef enum
{
    /** No active connection. */
    VT_DEVICE_MODEL_UNKNOWN,    
	VT_DEVICE_MODEL_VTAG,
    VT_DEVICE_MODEL_VSCALE,
    VT_DEVICE_MODEL_VTOY,
    
	
} VTDeviceModelType_t;


typedef enum
{
    /** No active connection. */
	VT_DEVICE_OWNER_UNKOWN,
	VT_DEVICE_OWNER_MINE,    
	VT_DEVICE_OWNER_FRIEND,        
    
	
} VTDeviceOwnerType_t;

typedef enum
{
    VT_EVENT_CONNECTED,
    VT_EVENT_DATA_RECEIVED,
    VT_EVENT_DISCONNECTED,
    VT_EVENT_CONNECTED_WITH_LOCATION,
    VT_EVENT_DISCONNECTED_WITH_LOCATION,
    VT_EVENT_ADVERTISE,
    VT_EVENT_CHANGE_NAME,
    VT_EVENT_CLOSED,
    VT_EVENT_NO_AUTHORIZED,
    

    
}VTEventType_t;

typedef enum
{
    /** Proximity alert threshold. */
    VT_PROXIMITY_ALERT_THRESHOLD_0,
    VT_PROXIMITY_ALERT_THRESHOLD_1,
    VT_PROXIMITY_ALERT_THRESHOLD_2,
    VT_PROXIMITY_ALERT_THRESHOLD_3,
    VT_PROXIMITY_ALERT_THRESHOLD_4,
    VT_PROXIMITY_ALERT_THRESHOLD_5,
    VT_PROXIMITY_ALERT_THRESHOLD_6,
    VT_PROXIMITY_ALERT_THRESHOLD_7,
    VT_PROXIMITY_ALERT_THRESHOLD_8,
    VT_PROXIMITY_ALERT_THRESHOLD_9,
    VT_PROXIMITY_ALERT_THRESHOLD_10,
    VT_PROXIMITY_ALERT_THRESHOLD_11,
    VT_PROXIMITY_ALERT_THRESHOLD_12,
    VT_PROXIMITY_ALERT_THRESHOLD_13,
    VT_PROXIMITY_ALERT_THRESHOLD_14,
    VT_PROXIMITY_ALERT_THRESHOLD_MAX,
    
} VTProximityAlertThreshold_t;


typedef enum{
    VT_TAG_BUTTON_NONE,
    VT_TAG_BUTTON_CONNECTION,
    VT_TAG_BUTTON_FUN_1,
    
}VTTagButton_t;

typedef enum{
    VT_TAG_EVENT_UNKNOWN,
    VT_TAG_EVENT_KEY_DOWN,
    VT_TAG_EVENT_KEY_UP,
    VT_TAG_EVENT_MID_PRESS,
    VT_TAG_EVENT_LONG_PRESS,
    
}VTTagButtonEvent_t;


#endif  

