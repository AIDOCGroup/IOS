/*********************************************************************
* 版权所有 (C)2003 - 2014, 福建联迪商用设备有限公司。
* 文件名称:
*   EMVAPI.H
* 当前版本: 
*           0.9
* 内容摘要: 
*   EMV L2 模块的函数出口表定义
* 历史纪录:
*   修改人      日期            版本号              修改内容
*   Luyl       2014-12-9       0.9                创建
**********************************************************************/
#ifndef IOS_EMV_API_H
#define IOS_EMV_API_H

#ifdef __cplusplus
	extern "C"{
#endif

#include "MacroDef.h"
/******************************************************************

                        类型定义

******************************************************************/
#define  uchar       unsigned char    		// 单字节(Byte)
#define  uint        unsigned int
#define  BYTE        unsigned char    		// 单字节(Byte)
#define  WORD        unsigned short   		// 字(Word)
#define  DWORD       unsigned long long		// 双字(Double Word)
#define  UINT        unsigned int      
#define  DevHandle   unsigned int 

#ifdef PLATFORM_WIN
#define RTVOID void _stdcall
#define RTBYTE BYTE _stdcall
#else
#define RTVOID void 
#define RTBYTE BYTE 
#endif


//  定义错误类型-返回值
#define EMV_FAILED                 (BYTE)0x8F    // 其它错误
#define EMV_ERR_PARAM              (BYTE)0x8B    // 输入数据错误


// 持卡人验证
#define EMV_CVM_ONLINE_PIN         (BYTE)0x01    // 联机PIN输入
#define EMV_CVM_OFFLINE_PIN        (BYTE)0X02    // 脱机PIN输入
#define EMV_CVM_PBOC_CERT          (BYTE)0x05    // PBOC 持卡人证件验证

// 行为分析结果
#define EMV_TC                     (BYTE)0x00    // 行为分析结果：TC
#define EMV_AAC                    (BYTE)0x01    // 行为分析结果：AAC
#define EMV_ARQC                   (BYTE)0x02    // 行为分析结果：ARQC
#define EMV_AAR                    (BYTE)0x03    // 行为分析结果：AAR
#define EMV_ARQC_TO_AAC            (BYTE)0x04    // 行为分析结果：ARQC -> AAC

                             
// 应用选择等                      
#define EMV_ERR_FCI_FMT            (BYTE)0x30    // FCI格式错误
#define EMV_ERR_TAG                (BYTE)0x32    // EMV不支持的标签
#define EMV_ERR_NUM_EXCEED         (BYTE)0x33    // 超出最大个数
#define EMV_ERR_NOVALUE            (BYTE)0x34    // 数据未赋值
#define EMV_ERR_NOSUCHDATA         (BYTE)0x35    // 无对应的数据元
#define EMV_ERR_TAGLEN	           (BYTE)0x36    // 标签长度错误
#define EMV_ERR_NOLIST             (BYTE)0x40    // 不存在该列表/列表为空
#define EMV_ERR_PART_SLT_FLG       (BYTE)0x42    // 获取部分选择标志出错
#define EMV_ERR_CARD_BLOCKED       (BYTE)0x43    // 卡片锁定或不支持选择命令
#define EMV_ERR_APP_BLOCKED        (BYTE)0x44    // 应用锁定
#define EMV_ERR_READ_AD            (BYTE)0x45    // 读取卡片应用数据时出错（卡片不在位，SW错误，TLV格式错误，数据元缺失等）
#define EMV_ERR_SWDIFF             (BYTE)0xE7    // EM_ic_SWDIFF
#define EMV_ERR_SW6985             (BYTE)0x46    // sw = 6985,由应用程序决定如何处理
#define EMV_ERR_PADDING            (BYTE)0x47    // 数据填充错误
#define EMV_ERR_TLV_FMT            (BYTE)0X48    // TLV编码错误
#define EMV_ERR_GPO_SW             (BYTE)0X49    // 取处理选项中，SW != 9000, 须终止交易

#define EMV_ERR_READ_LAST          (BYTE)0x71    //QPBOC交易中读取最后一条记录失败
                                   
// 脱机数据认证                    
#define EMV_ERR_DATA_MISSING       (BYTE)0x4A    // 必备数据缺失
#define EMV_ERR_GET_CAPK           (BYTE)0x4B    // 获取ca公钥失败
#define EMV_ERR_ISSPK_REC          (BYTE)0X4C    // 发卡行公钥恢复失败
#define EMV_ERR_ICCPK_SSD_REC      (BYTE)0X4D    // IC卡公钥恢复/签名的静态数据验证 失败
#define EMV_ERR_INTERAUTH          (BYTE)0X4E    // 内部认证命令失败(卡片不在位,SW错误等)
#define EMV_ERR_GET_SDD            (BYTE)0X4F    // 获取签名动态认证数据失败
#define EMV_ERR_SDD_REC            (BYTE)0X50    // 签名动态数据验证失败
#define EMV_ERR_CID_INCONSISTENT   (BYTE)0x51    // CID数据不一致


// 脱机PIN验证部分
#define EMV_PIN_TRYAGAIN           (BYTE)0x53    // 需重新输入PIN
#define EMV_PIN_CHALLENGEERR       (BYTE)0X54    // EM_pin_CHALLENGEERR 
#define EMV_PIN_VERIFYERR          (BYTE)0X55    // EM_pin_VERIFYERR 

#define EMV_MUST_USE_AIDLST        (BYTE)0x74    // 必须转向AID列表方式建立候选列表
#define EMV_ERR_INTERNATION_CARD   (BYTE)0xD1	 	 //国际卡
#define EMV_ERR_DDAVER		   (BYTE)0xD2	 	 //DDA版本不支持
#define EMV_ERR_DELAY		   (BYTE)0xD3	 	 //需要延迟并再寻卡
#define EMV_ERR_CARDTIMEOUT	   (BYTE)0xD4	   //需要中断并再寻卡
#define EMV_ERR_USCARD		   (BYTE)0xD5	   //US CARD
#define EMV_ERR_DATA_DUP	   (BYTE)0xE7    // 数据重复


// EMV L2 内核中可临时存储的数据的最大个数
#define  MAX_MODULUS_LEN         248       // 最大公钥模长度（字节数）
#define  ISS_SCRPT_RSLT_MAX      12*5      // 发卡行脚本结果最大字节数(即12个脚本,每个占用5字节)
#define  CAND_LIST_MAX_NUM       16        // 应同CANDLIST.H保持一致
#define  MAX_PKFILE_NUM          18        // 存储的最大公钥数
#define  MAX_CERT_FILE           100        // 回收Cert列表的最大数目
#define  AID_LIST_MAX_NUM        128        // AID列表的最大个数
#define  CAND_LIST_MAX_NUM       16        // 候选列表的最大个数


#define EMV_QPBOC_TC               (BYTE)0x61    // QPBOC,脱机批准
#define EMV_QPBOC_AAC              (BYTE)0x60    // QPBOC,脱机拒绝
#define EMV_QPBOC_ARQC             (BYTE)0x62    // QPBOC,联机
#define EMV_QPBOC_CONT             (BYTE)0x63    // QPBOC,需要转接触卡
#define EMV_MSD_READ         			 (BYTE)0x65    // MSD,需读取数据  
#define EMV_MSD_NOREAD             (BYTE)0x66    // MSD,无需读取数据
#define EMV_WAVE2_OFFLINE          (BYTE)0x67    // WAVE2脱机批准  
#define EMV_WAVE2_ONLINE           (BYTE)0x68    // WAVE2联机

#define EMV_ERR_DATE_OUT      		 (BYTE)0xEE		 // 过期卡
#define EMV_AAC_FILL               (BYTE)0x21    // 行为分析结果：AAC,并且要求充值
#define EMV_ARQC_FILL              (BYTE)0x22    // 行为分析结果：ARQC,并且要求充值

#define         KERNOPT_PIN_BYPASS    (BYTE)2		//该选项为1时，跳过PIN时不会跳过其他验证方法
#define         KERNOPT_CHK_KEYIDX    (BYTE)4		//该选项为1时，如果对应公钥不存在则终止读记录
/*******************************************************

  终端数据元结构

*******************************************************/
typedef struct TM_FIX_DATA
{ 
	BYTE   tTmCntrCode [2];  // 终端国家代码
	BYTE   tAquirerID[6];    // 收单行标识'9F01' (6字节)
	BYTE   tMerchCatCode[2]; // 商户分类码'9F15'(2字节) 
	BYTE   tTmTransCur[2];   // 终端交易货币代码'5F2A'(2字节) 
	BYTE   cTmTransCurExp;  // 终端交易货币指数'5F36'(1字节)

	BYTE   tTmRefCurCode[2]; // 终端交易参考货币代码'9F3C'(2字节)
	BYTE   tTmRefCurExp;	  // 终端交易参考货币指数'9F3D'(1字节)
	BYTE   tTmRefCurConv[4]; // 终端交易参考货币兑换(4字节) 
}TmFixData; 


//  终端应用相关数据元
typedef struct INIT_EMV_DATA_STRUCT
{
	BYTE   tTmID[8];            // 终端标识(终端号)
	BYTE   tMerchantID[15];     // 商户标识(15字节) 
	WORD   wMCHLOCLen;          // 商户名称及位置数据域的长度
	BYTE   tMCHNAMELOC[256];    // 商户名称及位置(1-256 字节)
	BYTE   tTmTransCateCode;    // 终端交易类别代码
	
	BYTE   tAppVerNo[2];        // 应用版本号(2字节) 
	BYTE   cTmRmCheckFlg;       // 由收单行确定是否进行终端风险管理检查
									// = 0: 不进行风险管理
									// = 1: 必须进行风险管理
	                                // = 2: 由AIP决定

	
	BYTE   tTAC_Denial[5];      // 终端行为代码TAC－拒绝(5字节) 
	BYTE   tTAC_Online[5];      // 终端行为代码TAC－联机(5字节) 
	BYTE   tTAC_Default[5];     // 终端行为代码TAC－默认(5字节)  
	BYTE   cLenTDOL;            // TDOL的长度
	BYTE   tTDOL[252];          // TDOL
	BYTE   cLenDDOL;            // DDOL的长度
	BYTE   tDDOL[252];          // DDOL 
	BYTE   tFloorLmt[11];       // 最低限额(11字节)
	BYTE   tLmt[11];		    // 随机选择阈值
	BYTE   tPercent[3];         // 随机选择目标百分数
	BYTE   tMaxPercent[3];      // 随机选择最大目标百分数

}AppInitData; 

// 交易开始所需要的数据
typedef struct  START_APP_DATA_STRUCT
{
    DWORD  lAmntAuth;      // 授权金额(unsigned long)
    DWORD  lAmntOther;     // 其他金额(unsigned long)
	BYTE   cTransType;    // 交易类型'9C'	
    BYTE   tDate[3];       // 交易日期指针(3 BYTE)
    BYTE   tTime[3];       // 交易时间指针(3 BYTE)
    BYTE   tTrace[4];      // 交易序列计数器(4 BYTE)    
 	BYTE   cRFU;
}StartAppDt;


/* 定义AID列表的结构 */
typedef struct TERM_CAND_LIST_STRUCT
{
	BYTE   tAID[16];       // AID
	BYTE   cLenAID;  
	BYTE   tAppLabel[16];  // 应用标签
	BYTE   cLenLabel;
	BYTE   tAPN[16];  	   // 应用首选名
	BYTE   cLenAPN;   
	BYTE   cAPID;          // 应用优先权标识符
	BYTE   cFlgAPID;       // 应用优先权标识符标志
	BYTE   sLangPref[8];   // 首选语言
	BYTE   cLenLangPref;  
	BYTE   cIssCTIndex;    // 发卡行代码表索引
	BYTE   cFlgIssCTIndex; 
}DCandList;

// 交易完成返回数据
typedef struct  TRANS_DATA_STRUCT
{
    BYTE   tExpDate[4];         // 失效日期  
    BYTE   cFlgCID;
    BYTE   cCID;                // 密文信息数据
    BYTE   cFlgAC;
    BYTE   tAC[8];              // 应用密文
    BYTE   cFlgTVR;
    BYTE   tTVR[5];             // 终端验证结果
    BYTE   cFlgTSI;
    BYTE   tTSI[2];             // 交易状态信息
    BYTE   cFlgTrack2;
    BYTE   tTrack2[19];         // 二磁道等价数据
    BYTE   cFlgATC;
    BYTE   tATC[2];             // 应用交易计数器
    BYTE   cFlgAIP;
    BYTE   tAIP[2];             // 应用交互特征
    BYTE   cFlgAUC;
    BYTE   tAUC[2];             // 应用用途控制
    BYTE   cFlgCVMR;
    BYTE   tCVMR[3];            // 终端验证结果
    BYTE   cFlgIAC_Denial;
    BYTE   tIAC_Denial[5];      // 发卡行行为代码－拒绝
    BYTE   cFlgIAC_Online;
    BYTE   tIAC_Online[5];      // 发卡行行为代码－联机
    BYTE   cFlgIAC_Default;
    BYTE   tIAC_Default[5];     // 发卡行行为代码－默认
	BYTE   tIssSrptRslt[ISS_SCRPT_RSLT_MAX];    // 发卡行脚本结果
	BYTE   cNumIssSrptRslt;                     // 发卡行脚本结果长度
	BYTE   tUnpreNumber[4];      // 不可预知数
	BYTE   tARC[2];              // ARC
	BYTE   cFlgSign;             // 签名标志
	BYTE   cLenIssAppDt;         // 发卡行应用数据长度 
	BYTE   tIssAppDt[32];        // 发卡行应用数据
}TransDt;

/******************************************************************************
* CA公钥数据结构
******************************************************************************/
typedef  struct PUBLIC_KEY_FILE
{ 
	BYTE   cRid[5];  		       // RID
	BYTE   cIndex;   		       // 公钥索引	
	BYTE   cModLen;       	       // 公钥模的长度
	BYTE   cMod[MAX_MODULUS_LEN]; // 公钥模	
	BYTE   cExpLen;               	// 公钥指数的长度
	BYTE   cExp[3];           	    // 公钥指数
	BYTE   cExpDate[4];             // 公钥失效期, YYYYMMDD，首字节暂无需设置
	BYTE   cHashFlg;                // 公钥校验和是否存在
	BYTE   cHash[20];               // 公钥校验和 - 用于定期检查, 可不赋值
}PKFILESTRU;

typedef  struct CERTIFICATE_FILE
{
	BYTE   cIndex;   		        // 公钥索引
	BYTE   cRid[5];  		        // RID
	BYTE   cCertSn[3];              // 证书序列号
	BYTE   tRFU[3];                 // RFU,将结构字节数填充为4的整数倍
}CertFile;

/* 定义AID列表的结构 */
typedef struct TERM_AID_LIST_STRUCT
{
	BYTE  cLen;     // AID名称的长度
	BYTE  tAID[16];	// AID名称
	BYTE  cFlg;	    // 部分选择标识
	BYTE  tRFU[2];  // RFU,将结构字节数填充为4的整数倍
}DAidList;

// 持卡人证件验证所需要的数据
typedef struct  CARD_HOLDER_CERT_DATA_STRUCT
{
    BYTE   cCertType;       //  证书类型
    BYTE   cTypeLen;        //  类型数据长度
    BYTE   cCertData[41];   //  证书号码(40 BYTE)
    BYTE   cCertLen;        //  证书数据长度      
}HolderCertDt;   
   
/* MCK 配置结构 */
typedef struct CONFIGURATION_STRUCT
{ // 按在 ISS中出现的先后顺序排列
	BYTE   cTmType;          // 终端类型
	BYTE   tTmCap [3];       // 终端性能
	BYTE   tTmCapAd [5];     // 附加终端性能 	
	BYTE   cSupPSESelect;        // PSE选择方式    
	
	BYTE   cSupAppConfirm;   // 支持持卡人确认, 由持卡人选择应用
	BYTE   cSupAppDispOrder; // 支持按指定顺序显示候选应用
	BYTE   cSupMulLang;      // 支持多语言
    BYTE   cSupIssCertCheck ; // IssCert 检查 
	BYTE   cSupDDOLFlg ;      // 支持默认DDOL       
	
	BYTE   cSupBypassPIN;     // Bypass PIN, 可跳过密码     
	BYTE   cSupFlrLmtCheck ;  // 最低限额检查    
	BYTE   cSupRndOnlineSlt;  // 随机联机选择 
	BYTE   cSupVeloCheck;     // 频度检查     
	BYTE   cSupTransLog;      // 交易日志 - KERN 在最低限额检查中使用
	
	BYTE   cSupExcptCheck ;   // 异常文件检查 
	BYTE   cTmRmCheckFlg ;    // TRM检查: 是否支持由应用程序决定是否进行TRM检查                  
	BYTE   cSupTmActionCode;  // 支持终端行为代码 - kern 在TERMAA.c的终端行为分析中使用
	BYTE   cSupForceOnline;      // 交易强制联机能力
	BYTE   cSupForceAccept;      // 交易强制接受能力
	
	BYTE   cSupAdvice;           // 终端是否支持通知
	BYTE   cSupIssVoiceRef;      // 支持发卡行发起的参考
	BYTE   cSupCardVoiceRef;      // 支持卡片发起的参考
	BYTE   cSupBatchCollect;     // 支持批数据采集  
	BYTE   cSupOnlineCollect ;   // 支持联机数据采集             
	
	BYTE   cSupTDOLFlg ;      // 支持默认TDOL                    
	BYTE   cPOSEntryMode[3] ; // POS　Entry Code  "025"	
	BYTE   tHashVal[20];      // 与各配置对应的hash值
	BYTE   tRFU[2];
}CfgStru; // 1-> 支持


/* 定义存在卡片日志的应用结构 */
typedef struct TERM_CL_LIST_STRUCT
{

	BYTE   tAid[16];  // 应用标签
	BYTE   cLenAID;		// 应用标签长度
	BYTE   cLogFSI;		// 卡片日志SFI
	BYTE   cLogNum;		// 卡片日志数量
	BYTE   cAppIsLock;	// 该应用是否被锁定

}DClList;


//201412 UM
typedef struct
{   
	uchar ucTmType;        // 终端类型     默认: \x15 金融机构控制的有联机能力的脱机终端
	uchar auTmCap[3];      // 终端性能     默认: \x60\x48\xC8 持卡人验证方式仅支持联机加密PIN和NO CVM
    uchar auTmCapAd[5];    // 附加终端性能 默认: \x6F\x00\xF0\xF0\x01
	uchar auCntCode[2];    // 国家代码     默认: \x01\x56 中国
	uchar auCurCode[2];    // 货币代码     默认: \x01\x56 人民币
	uchar auTAC_Denial[5]; // 终端行为代码 TAC－拒绝  缺省:\x00\x00\x00\x00\x00
	uchar auTAC_Online[5]; // 终端行为代码 TAC－联机  缺省:\xFF\xFF\xFF\xFF\xFF
	uchar auTAC_Default[5];// 终端行为代码 TAC－默认  缺省:\xFF\xFF\xFF\xFF\xFF
	uchar cLenTDOL;			//缺省TDOL长度，默认:3
	uchar auTDOL[252];		//缺省TDOL，默认："\x9F\x08\x02"
	uchar cLenDDOL;			//缺省DDOL长度,默认11
	uchar auDDOL[252];		//缺省DDOL，默认："\x9F\x37\x04\x9F\x47\x01\x8F\x01\x9F\x32\x01"

	uint  uiRandPer;       // 随机选择目标百分数
    uint  uiRandPerMax;    // 随机选择最大目标百分数
//后面的数据可以先不考虑
	uchar auTTQ[4];        // [非接]终端交易属性9F66  缺省:\x44\x80\x00\x80(支持联机PIN，不支持非接小额支付，不支持非接标准借贷记)
	uchar auECashLmt[6];   //  电子现金交易限额9F7B   BCD编码，例如：123.45，则编码为:\x00\x00\x00\x01\x23\x45            
	uchar auTransLmt[6];   // [非接]非接限额 BCD编码，例如：123.45，则编码为:\x00\x00\x00\x01\x23\x45
	uchar auCVMLmt[6];     // [非接]CVM限额  BCD编码，例如：123.45，则编码为:\x00\x00\x00\x01\x23\x45
    uchar auFloorLmt[6];   // [接触与非接]最低限额，  BCD编码，例如：123.45，则编码为:\x00\x00\x00\x01\x23\x45
	uchar auRandLmt[6];    // 随机选择阈值   BCD编码，例如：123.45，则编码为:\x00\x00\x00\x01\x23\x45
	uint  RFULen;          // 保留域数据长度
	uchar RFU[600];        // 保留域, 其它终端TLV数据元:终端标识(9F1C)、商户标识(9F16)、商户名称(9F4E)、应用版本号(9F09)、交易类别代码(9F53)等	                     
}EMV_tTmParam;


typedef struct
{
	uchar auAmount[6];     //交易金额：    BCD编码, 例如：123.45，      则编码为:\x00\x00\x00\x01\x23\x45
	uchar auAmountOth[6];  //其它金额：    BCD编码, 例如：123.45，      则编码为:\x00\x00\x00\x01\x23\x45,	缺省填\x00\x00\x00\x00\x00\x00
	uchar auDate[3];       //交易日期：    BCD编码, 例如: 2012年6月1日，则编码为:\x12\x06\x01
	uchar auTime[3];       //交易时间：    BCD编码, 例如: 18时32分20秒，则编码为:\x18\x32\x20
	uchar auTrace[4];      //交易计数器：  BCD编码, 例如：第63421次，   则编码为:\x00\x06\x34\x21,缺省填\x00\x00\x00\x00
	uchar ucForceOnline;   //强制联机标识：0-不强制联机；      1-强制联机
	uchar ucECashSup;      //电子现金标识: 0-不支持；          1-支持(仅为交互方式为接触，并且强制联机标志为0时有效)
}EMV_tTransStart;


typedef struct
{
	uchar ucState;             // 联机状态: 0-正常联机 1-联机失败
	uchar auARC[2];            // 授权响应码，即39域数据
	uint  uiDataLen;           // 联机响应芯片数据长度
	uchar auData[512];         // 联机响应芯片数据（55域数据）
}EMV_tHostData;

// IC卡属性结构
typedef struct ICCARD_STATUS
{
	char cTP;	         	// 传输协议标识(字符or块帧)
	char cCardType;	        // IC卡卡座类型
	DevHandle hCardHandle;  // IC卡卡座句柄 
}DCardSt;

typedef void (*PrintMessage)(BYTE *p);    

RTBYTE       EA_EMV_InitTmFixData(TmFixData *ptTmFixDt);
RTBYTE       EA_EMV_InitiateEMV(AppInitData *pInitDt);  	

// 交易流程相关接口	2-获取卡片日志
RTBYTE       EA_EMV_CardLogAppSlt(DCardSt  *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
RTBYTE       EA_EMV_GetCardLogFormat(BYTE *tBuf, WORD *cLen);
RTBYTE       EA_EMV_GetRecordDt_ZY(BYTE cRecNo, BYTE cSFI, BYTE *pRecDt, WORD *pRecDtLen);

// 交易流程相关接口 3-EMV 流程
RTBYTE       EA_EMV_AppSelection(DCardSt *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
RTBYTE       EA_EMV_SetAccountType(BYTE cType);
RTBYTE       EA_EMV_StartApplication(BYTE cAidNo, StartAppDt  *pDt,BYTE *pList, WORD  *pwLenList);              

RTBYTE       EA_EMV_ReadAppData( BYTE *pList, WORD  *pwLenList);
RTBYTE       EA_EMV_OfflineDataAuth(void);

RTBYTE       EA_EMV_TermRiskManage( BYTE cIsBlackCard, DWORD lPanAmnt , BYTE *cResult);
RTBYTE       EA_EMV_ProcessRestrict( BYTE  *cResult );

RTBYTE       EA_EMV_ActionAnalysis(BYTE cCmd, TransDt  *pTransDt);
RTBYTE       EA_EMV_OnlineDataProcess(BYTE *pIssDt, WORD wLenIssDt,TransDt  *pTransDt);  	

	
// MCK 配置参数选择	
RTBYTE       EA_EMV_ucSetMCKConfig(CfgStru *pCfgDt);

// 设置/获取数据元	
RTBYTE       EA_EMV_SetData (BYTE *pDt, WORD wLenDt);
RTBYTE       EA_EMV_GetData(BYTE *pDol, WORD wLenDol, BYTE *pVal, WORD *pwLenVal);
RTBYTE       EA_EMV_GetAppData(BYTE *pTag, BYTE cTagLen, BYTE *pVal, WORD *pwLen);
RTBYTE       EA_EMV_GetCDOL(BYTE cDolType, BYTE *pCDOL, WORD *pwLenCDOL,BYTE *pCDOLPad, WORD *pwLenPad);

// 设置随机选择参数
RTBYTE       EA_EMV_SetRandSelectionData(long lLmt, long lPercent, long lMaxPercent);

// 设置回收证书
RTBYTE       EA_EMV_SetCertSn(CertFile *pCertFile, BYTE cNum);
RTVOID       EA_EMV_DelAllCAPKeyCertSn(void);
RTBYTE       EA_EMV_DelCAPKeyCertSn(BYTE *pCertSn, BYTE *pRid, BYTE cIndex);

// 设置/获取终端AID列表
RTVOID       EA_EMV_DelallTermAIDList(void);
RTBYTE       EA_EMV_DelAidListAid(BYTE *pAid, BYTE cLenAid);

RTBYTE       EA_EMV_SetTermAIDList(DAidList *pAidList, BYTE cNum);
RTBYTE       EA_EMV_SetAidListItem(BYTE *pAid, BYTE cLenAid, BYTE flag);

RTBYTE       EA_EMV_GetAidListAidNum(void);
RTBYTE       EA_EMV_GetALLAidListStru(BYTE cNum, DAidList *pAidList);
RTBYTE       EA_EMV_GetAidListStruByNo(BYTE cNo, DAidList *pAidList);

// 公钥设置/删除/获取
RTVOID       EA_EMV_DelAllCAPKey(void);
RTBYTE       EA_EMV_DelCAPKeyByRidIndex(BYTE *pRid, BYTE cIndex);

RTBYTE       EA_EMV_ucSetCAPKey(PKFILESTRU  *pCAPKStru);

RTBYTE       EA_EMV_ucChangeCAPKeyExpDate(BYTE *pRid, BYTE cIndex, BYTE *pExpDate);

RTBYTE       EA_EMV_GetCAPKeyNum(void);
RTBYTE       EA_EMV_GetCAPKeyByRidIndex(BYTE *pRid, BYTE cIndex, PKFILESTRU *cpkeystru);
RTBYTE       EA_EMV_GetCAPKeyInfo(BYTE cNum, PKFILESTRU *pCAPKeyInfo); 
RTBYTE       EA_EMV_GetCAPKeyInfoByNo(BYTE cNo, PKFILESTRU *pCAPKeyInfo);

RTBYTE       EA_EMV_SetDebugShow(BYTE cDebugFlag);	

RTVOID       EA_EMV_SetKernKind(BYTE cKernKind);

RTBYTE  EA_EMV_GetRandNum(WORD *wRand);

RTBYTE	EA_EMV_GetTransDt(TransDt  *pTransDt);
RTBYTE	EA_EMV_GetECBalance (BYTE *pDt, WORD *wLenDt);

RTBYTE EA_EMV_SetDevHandle(BYTE *pHandleType, DevHandle hICC);
RTBYTE EA_EMV_vInit(void);

RTBYTE EA_EMV_NewCardHolderValidate(BYTE cFlg, BYTE cCmd, BYTE *pDt, WORD *pwLenDt);

RTBYTE EA_EMV_FinalSelect(BYTE cAidNo,BYTE *pList, WORD  *pwLenList,
							BYTE *pPDOL, WORD *pwLenPDOL);
RTBYTE EA_EMV_GetProcOption( BYTE cAidNo,StartAppDt  *pDt, BYTE *pList, WORD  *pwLenList);

RTBYTE  EA_EMV_GetDataCmd(BYTE cTagHigh,BYTE cTagLow,BYTE *tBuf, WORD *pwLen);

RTBYTE  EA_EMV_ucTranKernLog( DevHandle  comHandle);

RTBYTE  EA_EMV_GetVISAEMVTag(WORD wLen, BYTE *pcTagList, WORD *pwOutLen, BYTE *pcOutData,BYTE ucFormat);
//获取QVSDC/QPBOC 卡片验证结果
RTBYTE EA_EMV_ucGetTranCVR(BYTE *pcOutData, BYTE *pcOutLen);

RTBYTE  EA_EMV_ucGetDataInTLV(BYTE  *pStr, WORD wLenStr, 
							BYTE  *pTag, BYTE cLenTag, 
							BYTE  *pVal, WORD *pwLenVal);
RTBYTE  EA_EMV_ucSetKernOpt(BYTE cOptItem, BYTE cFlg);
RTBYTE EA_EMV_ucDefaultTDOL(BYTE ucFlag, BYTE *paData, BYTE *pucLen);
RTBYTE EA_EMV_ucDefaultDDOL(BYTE ucFlag, BYTE *paData, BYTE *pucLen);

RTBYTE  EA_EMV_GetKernelVersion( BYTE  cType, BYTE *pSn, BYTE *pLen);
RTBYTE  EA_EMV_ucGetLoadFlag(void);
RTBYTE EA_EMV_tlvGetTLV(BYTE *pStr, WORD wStrLen, BYTE *pwTagLen, 
					BYTE *pwLengthLen, WORD *pwValueLen);
				
RTBYTE EA_EMV_GetqVSDCCVM(BYTE ucReqType);
RTBYTE EA_EMV_ucGetIdxRID(BYTE *pcIndex, BYTE *pcRID);


//银商增加
RTBYTE EA_EMV_ucSetAPDUInterface(BYTE *ptICDll, BYTE *ptICFunc,
		 BYTE *ptRFDll, BYTE *ptRFFunc);
RTBYTE EA_EMV_ucTmParamInit(EMV_tTmParam *ptTmParam);

RTBYTE EA_EMV_AppSelect	(BYTE ucInterFace, WORD *pwLenList,BYTE *pList );

RTBYTE EA_EMV_ucGeneAC(WORD wLenDOL, BYTE *pDol,
						WORD *pwLenOLDt,BYTE *pOLDt, 
						BYTE *pcInputPIN);

//实现EMV交易的前半段，包括获取处理选项和读取应用数据
RTBYTE EA_EMV_ucTransaction(EMV_tTransStart *ptTransData);

RTBYTE EA_EMV_ucAfOnlineProc(const EMV_tHostData *ptDt, TransDt  *pTransDt);

BYTE EA_ucAPDUExchange_FunInit(BYTE (* fun)(void *pvSendData,UINT uiSendLen,void *pvRecData,UINT *puiRecLen));

BYTE EA_ucAPDU_IC_FunInit(BYTE (* fun)(void *pvSendData,UINT uiSendLen,void *pvRecData,UINT *puiRecLen, void *pvMesg));

BYTE EA_ucAPDU_RF_FunInit(BYTE (* fun)(void *pvSendData,UINT uiSendLen,void *pvRecData,UINT *puiRecLen, void *pvMesg));

BYTE EA_EMV_SetPMCallBackFun(PrintMessage cbfPM);

#ifdef __cplusplus
  }
#endif

#endif

//////////////////////////////////////////////////////////////////////////////////////////
/*****************************************************************************************
*  End of file UMemvapi.h
******************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////

