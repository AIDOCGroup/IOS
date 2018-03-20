#ifndef __SDCCP_ENUMS_H__
#define __SDCCP_ENUMS_H__

#define SDCCP_BUFFER_SIZE (2048)

#define SDCCP_PACK_PRECODE_LEN (2)
#define SDCCP_VER (0x00)

#define SDCCP_OK	(0)
#define SDCCP_ERR	(-1)
#define SDCCP_TIMEOUT	(-2)
#define SDCCP_RETRY	(-3)

#define PRECODE_0 (0x12)
#define PRECODE_1 (0xEF)

typedef enum {
	FA_ACK		= 0x00,
	FA_POST		= 0x01,
	FA_REQUEST 	= 0x02,
	FA_RESPONSE 	= 0x03,
} S_PACKAGE_FRAME_TYPE_E;

typedef enum {
	MSG_LOGIN = 0x00,		//登录
	MSG_LOGOUT,			//注销
	MSG_TIME_SYNC ,			//时间同步
	MSG_SERVER_VERSION,		//服务器版本获取
	MSG_DEVICE_HEATBEAT,		//心跳包数据
	MSG_DEVICE_STATUS,		//状态数据
	MSG_NOTICE,			//通知数据
	MSG_REALTIME_DATA_UP,		//发送实时数据
	MSG_REALTIME_DATA_DOWN,		//获取实时数据
	MSG_HISTORY_DATA_QUERY,		//历史数据查询
	MSG_HISTORY_DATA_UP,		//上传历史数据
	MSG_HISTORY_DATA_DOWN,		//下载历史数据
	MSG_STATISTICS_DATA_UP,		//上传统计数据
	MSG_STATISTICS_DATA_DOWN,	//下载统计数据
	MSG_USER_CONFIG_UP,		//上传用户配置数据
	MSG_USER_CONFIG_DOWN,		//下载用户配置数据
	MSG_DEVICE_CONFIG_UP,		//发送控制盒配置数据
	MSG_DEVICE_CONFIG_DOWN,		//获取控制盒配置数据
	MSG_DEVICE_LOG_UP,		//发送Log数据
	MSG_DEVICE_LOG_DOWN,		//下载Log数据
	MSG_DEVICE_VERSION,		//控制盒版本获取
	MSG_UPDATE_UP,			//发送升级数据
	MSG_UPDATE_DOWN,		//获取升级数据
	MSG_ADVICE_UP,			//推送建议数据
	MSG_ADVICE_DOWN,		//拉取建议数据

	MSG_DEVICE_SET_SAMPLING,	//设置采样状态
	MSG_DEVICE_GET_SAMPLING,	//获取采样状态
    
    MSG_DEVICE_GET_PRODUCT_INFO,	//获取产品信息
    MSG_DEVICE_GET_POWER_STATUS,	//获取电池信息

    
    MSG_REAL_RAW_DATA_UP,		//发送原始数据

    MSG_SET_AUTO_GATHER_TIME,     //设置自动采集时间点
    MSG_GET_AUTO_GATHER_TIME,      //获取自动采集时间点
    
    MSG_SET_ALARM_INFO,//设置闹铃信息
    MSG_GET_ALARM_INFO,//获取闹铃信息

    MSG_GET_WIFI_RESTON_INFO = 0x1B,//获取不带wifi reston的设备信息，包括暗文
    
} S_PACKAGE_MSG_TYPE_E;

typedef enum {
	SAMPLING_NONE	= 0x00,	//未采集
	SAMPLING_ING	= 0x01,	//正在采集
} S_SAMPLING_STATUS_E;

typedef enum {
	DEVICE_CONFIG_THRESHOLD_GAIN = 0x00,    // 增益值
	DEVICE_CONFIG_THRESHOLD_BODYMOVE_T,     // 体动判断时间阈值
	DEVICE_CONFIG_THRESHOLD_TURNOVER_T,     // 翻身判断时间阈值

	DEVICE_CONFIG_INVALID = 0xFF
} S_DEVICE_CONFIG_TYPE_E;

// 监控类数据
typedef enum {	//描述类型表

	// 心率呼吸相关
	MONITOR_DESC_BR	= 0x00,		//呼吸频率 1B 次/分
	MONITOR_DESC_HR,		//心跳频率 1B 次/分
	MONITOR_DESC_BR_HR_STATUS,	//状态 1B
    MONITOR_DESC_STATUS_VALUE, 	//与状态相关的计数值, 实时数据 2B, 历史数据 1B
    MONITOR_DESC_QUALITY,		//睡眠质量
    MONITOR_DESC_SLEEPFLAG,		//睡着标识
    MONITOR_DESC_AWAKEFLAG,		//清醒标识

	// 环境相关
	MONITOR_DESC_ENV_TEMPERATURE = 0x10,	//环境温度 1B
	MONITOR_DESC_ENV_HUMIDITY,		//环境温度 1B
	MONITOR_DESC_ENV_LIGHT,			//环境光强 2B
	MONITOR_DESC_ENV_CO2,			//环境CO2浓度 2B

	// 床垫相关
    MONITOR_DESC_PAD_TEMPERATURE = 0x20,	//床垫温度
    MONITOR_DESC_PAD_HUMIDITY,		//床垫湿度

} S_MONITOR_DESC_TYPE_E;

// SLEEP_INIT 只用于实时数据
typedef enum {
	SLEEP_OK = 0x00,	//一切正常
	SLEEP_INIT,		//初始化状态，约10秒时间
	SLEEP_B_STOP,		//呼吸暂停
	SLEEP_H_STOP,		//心跳暂停
	SLEEP_BODYMOVE,		//体动
	SLEEP_LEAVE,		//离床
	SLEEP_TURN_OVER,	//翻身
} S_SLEEP_STATUS_E;

typedef enum {
	DEV_NORMAL = 0x00,	//一切正常
	DEV_LOW_POWER,		//电量过低
} S_DEVICE_STATUS_TYPE_E;

typedef enum {
	NOTICE_GEBIN_REAL = 0x00,	//开始查看实时数据
	NOTICE_END_REAL,		//结束查看实时数据
    
    NOTICE_GEBIN_REAL_RAW,  //开始查看原始数据
    NOTICE_END_REAL_RAW,    //结束查看原始数据

	NOTICE_CLEAR_STATUS = 0x10,	//清除状态通知, Value存储状态类型 如:清除低电量状态
} S_NOTICE_TYPE_E;

typedef enum {
	LOGIN_PASSWORD = 0x00,
    LOGIN_EMAIL,
    LOGIN_MEMBER_ID,	//成员ID
    LOGIN_TIMEZONE,     //时区偏移(S)
} S_LONIN_TYPE_E;

typedef enum {
	H_QUERY_SUMMARY = 0x00,	//查询概要信息
	H_QUERY_RANGE,		//查询数据边界
} S_HISTORY_QUERY_TYPE_E;

typedef enum {
	H_END_NORMAL = 0x00,	//正常结束(用户手动点结束)
	H_END_AUTO,		//自动结束(用户忘记点击结束)
	H_END_ABORT,		//强制终止(关机)
	H_END_ERROR,		//错误的结束(没电了? 系统异常?)
} S_HISTORY_STOP_MODE_TYPE_E;

typedef enum {
	U_UP_SUMMARY = 0x00,	//上传升级包概要
	U_UP_DETAIL,		//上传升级包内容
} S_UPDATE_UP_TYPE_E;

typedef enum {
	PACKAGE_ACK_OK = 0x00,		//成功
	PACKAGE_ACK_INVALID_TYPE,	//帧类型错误
	PACKAGE_ACK_INVALID_LENGTH,	//帧长度异常
	PACKAGE_ACK_INVALID_CHECK_SUM,	//帧校验失败

	PACKAGE_ACK_UNKOWN = 0xFF,	//未知错误
} S_ACK_TYPE_E;

typedef enum {
	MSG_ERROR_OK = 0x00,		//OK
	MSG_ERROR_INVALID_TYPE,		//错误的消息类型
	MSG_ERROR_PARAMETER,		//参数错误(如:参数不匹配，字串异常, 结构描述中的描述类型不存在，都用该错误表示)
	MSG_ERROR_DATABASE,		//数据库错误
	MSG_ERROR_USERNAME,		//用户名错误
	MSG_ERROR_PASSWORD,		//密码错误
	MSG_ERROR_PRIVILEGE,		//无权限
	MSG_ERROR_INACTIVE,		//未激活
	MSG_ERROR_DEVICEID,		//设备ID错误
	MSG_ERROR_UNBOUND,		//未绑定
	MSG_ERROR_NOT_LOGIN,		//未登录
	MSG_ERROR_INVALID_DATA,		//历史数据错误
	MSG_ERROR_UPDATE_HW_VER,	//升级包硬件不匹配
	MSG_ERROR_UPDATE_CHECK,		//升级包校验错误
	MSG_ERROR_INVALID_SUMMARY,	//没有对应的概要信息
	MSG_ERROR_INVALID_PRODUCT_INFO,	//没有正确的出厂信息

	MSG_ERROR_UNKOWN = 0x7F,	//未知错误
} S_MSG_ERR_TYPE_E;

#endif

