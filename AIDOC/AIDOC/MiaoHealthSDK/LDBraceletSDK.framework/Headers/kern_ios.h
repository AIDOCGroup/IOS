//
//  kern_ios.h
//  kern_ios
//
//  Created by yanwenhua on 16/12/1.
//  Copyright © 2016年 yanwh. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for kern_ios.
FOUNDATION_EXPORT double kern_iosVersionNumber;

//! Project version string for kern_ios.
FOUNDATION_EXPORT const unsigned char kern_iosVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <kern_ios/PublicHeader.h>

/*
FOUNDATION_EXPORT BYTE       EA_EMV_InitTmFixData(TmFixData *ptTmFixDt);
FOUNDATION_EXPORT BYTE       EA_EMV_InitiateEMV(AppInitData *pInitDt);  	

// 交易流程相关接口	2-获取卡片日志
FOUNDATION_EXPORT BYTE       EA_EMV_CardLogAppSlt(DCardSt  *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
FOUNDATION_EXPORT BYTE       EA_EMV_GetCardLogFormat(BYTE *tBuf, WORD *cLen);
FOUNDATION_EXPORT BYTE       EA_EMV_GetRecordDt_ZY(BYTE cRecNo, BYTE cSFI, BYTE *pRecDt, WORD *pRecDtLen);

// 交易流程相关接口 3-EMV 流程
FOUNDATION_EXPORT BYTE       EA_EMV_AppSelection(DCardSt *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
FOUNDATION_EXPORT BYTE       EA_EMV_SetAccountType(BYTE cType);
FOUNDATION_EXPORT BYTE       EA_EMV_StartApplication(BYTE cAidNo, StartAppDt  *pDt,BYTE *pList, WORD  *pwLenList);              

FOUNDATION_EXPORT BYTE       EA_EMV_ReadAppData( BYTE *pList, WORD  *pwLenList);
FOUNDATION_EXPORT BYTE       EA_EMV_OfflineDataAuth(void);

FOUNDATION_EXPORT BYTE       EA_EMV_TermRiskManage( BYTE cIsBlackCard, DWORD lPanAmnt , BYTE *cResult);
FOUNDATION_EXPORT BYTE       EA_EMV_ProcessRestrict( BYTE  *cResult );
FOUNDATION_EXPORT BYTE       EA_EMV_CardHolderValidate(DevHandle hPinpadHandle, BYTE cFlg, BYTE cCmd, BYTE *pDt, WORD *pwLenDt);

//20100304 Add
FOUNDATION_EXPORT BYTE       EA_EMV_NewCardHolderValidate(BYTE cFlg, BYTE cCmd, BYTE *pDt, WORD *pwLenDt);

FOUNDATION_EXPORT BYTE       EA_EMV_ActionAnalysis(BYTE cCmd, TransDt  *pTransDt);
FOUNDATION_EXPORT BYTE       EA_EMV_OnlineDataProcess(BYTE *pIssDt, WORD wLenIssDt,TransDt  *pTransDt);  	

// MCK 配置参数选择	
FOUNDATION_EXPORT BYTE       EA_EMV_ucSetMCKConfig(CfgStru *pCfgDt);

// 设置/获取数据元	
FOUNDATION_EXPORT BYTE       EA_EMV_SetData (BYTE *pDt, WORD wLenDt);
FOUNDATION_EXPORT BYTE       EA_EMV_GetData(BYTE *pDol, WORD wLenDol, BYTE *pVal, WORD *pwLenVal);
FOUNDATION_EXPORT BYTE       EA_EMV_GetAppData(BYTE *pTag, BYTE cTagLen, BYTE *pVal, WORD *pwLen);
FOUNDATION_EXPORT BYTE       EA_EMV_GetCDOL(BYTE cDolType, BYTE *pCDOL, WORD *pwLenCDOL,BYTE *pCDOLPad, WORD *pwLenPad);

// 设置随机选择参数
FOUNDATION_EXPORT BYTE       EA_EMV_SetRandSelectionData(long lLmt, long lPercent, long lMaxPercent);

// 设置回收证书
FOUNDATION_EXPORT BYTE       EA_EMV_SetCertSn(CertFile *pCertFile, BYTE cNum);//(BYTE *pDt, WORD wLenDt);	
FOUNDATION_EXPORT void       EA_EMV_DelAllCAPKeyCertSn(void);
FOUNDATION_EXPORT BYTE       EA_EMV_DelCAPKeyCertSn(BYTE *pCertSn, BYTE *pRid, BYTE cIndex);

// 设置/获取终端AID列表
FOUNDATION_EXPORT void       EA_EMV_DelallTermAIDList(void);
FOUNDATION_EXPORT BYTE       EA_EMV_DelAidListAid(BYTE *pAid, BYTE cLenAid);

FOUNDATION_EXPORT BYTE       EA_EMV_SetTermAIDList(DAidList *pAidList, BYTE cNum);//(BYTE *pDt, WORD wLenDt);
FOUNDATION_EXPORT BYTE       EA_EMV_SetAidListItem(BYTE *pAid, BYTE cLenAid, BYTE cFlag);

™ BYTE       EA_EMV_GetAidListAidNum(void);
FOUNDATION_EXPORT BYTE       EA_EMV_GetALLAidListStru(BYTE cNum, DAidList *pAidList);
FOUNDATION_EXPORT BYTE       EA_EMV_GetAidListStruByNo(BYTE cNo, DAidList *pAidList);

// 公钥设置/删除/获取
FOUNDATION_EXPORT void       EA_EMV_DelAllCAPKey(void);
FOUNDATION_EXPORT BYTE       EA_EMV_DelCAPKeyByRidIndex(BYTE *pRid, BYTE cIndex);

FOUNDATION_EXPORT BYTE       EA_EMV_ucSetCAPKey(PKFILESTRU  *pCAPKStru);

FOUNDATION_EXPORT BYTE       EA_EMV_ucChangeCAPKeyExpDate(BYTE *pRid, BYTE cIndex, BYTE *pExpDate);

FOUNDATION_EXPORT BYTE       EA_EMV_GetCAPKeyNum(void);
FOUNDATION_EXPORT BYTE       EA_EMV_GetCAPKeyByRidIndex(BYTE *pRid, BYTE cIndex, PKFILESTRU *cpkeystru);
FOUNDATION_EXPORT BYTE       EA_EMV_GetCAPKeyInfo(BYTE cNum, PKFILESTRU *pCAPKeyInfo); 
FOUNDATION_EXPORT BYTE       EA_EMV_GetCAPKeyInfoByNo(BYTE cNo, PKFILESTRU *pCAPKeyInfo);

// 键盘提示信息显示,L2内核版本号,设备序列号获取
FOUNDATION_EXPORT BYTE       EA_EMV_GetEMVDeviceSn(BYTE *pSn, WORD *pwLenSn);
FOUNDATION_EXPORT BYTE       EA_EMV_GetKernelVersion( BYTE  cType, BYTE *pSn, BYTE *pLen);

// 设置设备句柄
FOUNDATION_EXPORT void       EA_EMV_vInitPrinth(DevHandle hPrint); 

// 设置IC卡句柄, 以便kernel执行APDU命令
FOUNDATION_EXPORT void       EA_EMV_vSetICCHandle(DevHandle hICC); 

// 调试信息相关
FOUNDATION_EXPORT BYTE       EA_EMV_SetDebugShow(BYTE cDebugFlag);	

// 不对外提供的功能接口
FOUNDATION_EXPORT void       EA_pinSetFlagPinInput(BYTE val);
FOUNDATION_EXPORT void       EA_EMV_SetKernKind(BYTE cKernKind);
FOUNDATION_EXPORT BYTE		EA_EMV_SetDevHandle(BYTE *pHandleType, DevHandle hICC);
// 获取随机选择随机数函数
FOUNDATION_EXPORT BYTE  EA_EMV_GetRandNum(WORD *wRand);
*/
