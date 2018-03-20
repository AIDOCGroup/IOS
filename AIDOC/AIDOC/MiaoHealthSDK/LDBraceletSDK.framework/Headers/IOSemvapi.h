/*********************************************************************
* ��Ȩ���� (C)2003 - 2014, �������������豸���޹�˾��
* �ļ�����:
*   EMVAPI.H
* ��ǰ�汾: 
*           0.9
* ����ժҪ: 
*   EMV L2 ģ��ĺ������ڱ���
* ��ʷ��¼:
*   �޸���      ����            �汾��              �޸�����
*   Luyl       2014-12-9       0.9                ����
**********************************************************************/
#ifndef IOS_EMV_API_H
#define IOS_EMV_API_H

#ifdef __cplusplus
	extern "C"{
#endif

#include "MacroDef.h"
/******************************************************************

                        ���Ͷ���

******************************************************************/
#define  uchar       unsigned char    		// ���ֽ�(Byte)
#define  uint        unsigned int
#define  BYTE        unsigned char    		// ���ֽ�(Byte)
#define  WORD        unsigned short   		// ��(Word)
#define  DWORD       unsigned long long		// ˫��(Double Word)
#define  UINT        unsigned int      
#define  DevHandle   unsigned int 

#ifdef PLATFORM_WIN
#define RTVOID void _stdcall
#define RTBYTE BYTE _stdcall
#else
#define RTVOID void 
#define RTBYTE BYTE 
#endif


//  �����������-����ֵ
#define EMV_FAILED                 (BYTE)0x8F    // ��������
#define EMV_ERR_PARAM              (BYTE)0x8B    // �������ݴ���


// �ֿ�����֤
#define EMV_CVM_ONLINE_PIN         (BYTE)0x01    // ����PIN����
#define EMV_CVM_OFFLINE_PIN        (BYTE)0X02    // �ѻ�PIN����
#define EMV_CVM_PBOC_CERT          (BYTE)0x05    // PBOC �ֿ���֤����֤

// ��Ϊ�������
#define EMV_TC                     (BYTE)0x00    // ��Ϊ���������TC
#define EMV_AAC                    (BYTE)0x01    // ��Ϊ���������AAC
#define EMV_ARQC                   (BYTE)0x02    // ��Ϊ���������ARQC
#define EMV_AAR                    (BYTE)0x03    // ��Ϊ���������AAR
#define EMV_ARQC_TO_AAC            (BYTE)0x04    // ��Ϊ���������ARQC -> AAC

                             
// Ӧ��ѡ���                      
#define EMV_ERR_FCI_FMT            (BYTE)0x30    // FCI��ʽ����
#define EMV_ERR_TAG                (BYTE)0x32    // EMV��֧�ֵı�ǩ
#define EMV_ERR_NUM_EXCEED         (BYTE)0x33    // ����������
#define EMV_ERR_NOVALUE            (BYTE)0x34    // ����δ��ֵ
#define EMV_ERR_NOSUCHDATA         (BYTE)0x35    // �޶�Ӧ������Ԫ
#define EMV_ERR_TAGLEN	           (BYTE)0x36    // ��ǩ���ȴ���
#define EMV_ERR_NOLIST             (BYTE)0x40    // �����ڸ��б�/�б�Ϊ��
#define EMV_ERR_PART_SLT_FLG       (BYTE)0x42    // ��ȡ����ѡ���־����
#define EMV_ERR_CARD_BLOCKED       (BYTE)0x43    // ��Ƭ������֧��ѡ������
#define EMV_ERR_APP_BLOCKED        (BYTE)0x44    // Ӧ������
#define EMV_ERR_READ_AD            (BYTE)0x45    // ��ȡ��ƬӦ������ʱ������Ƭ����λ��SW����TLV��ʽ��������Ԫȱʧ�ȣ�
#define EMV_ERR_SWDIFF             (BYTE)0xE7    // EM_ic_SWDIFF
#define EMV_ERR_SW6985             (BYTE)0x46    // sw = 6985,��Ӧ�ó��������δ���
#define EMV_ERR_PADDING            (BYTE)0x47    // ����������
#define EMV_ERR_TLV_FMT            (BYTE)0X48    // TLV�������
#define EMV_ERR_GPO_SW             (BYTE)0X49    // ȡ����ѡ���У�SW != 9000, ����ֹ����

#define EMV_ERR_READ_LAST          (BYTE)0x71    //QPBOC�����ж�ȡ���һ����¼ʧ��
                                   
// �ѻ�������֤                    
#define EMV_ERR_DATA_MISSING       (BYTE)0x4A    // �ر�����ȱʧ
#define EMV_ERR_GET_CAPK           (BYTE)0x4B    // ��ȡca��Կʧ��
#define EMV_ERR_ISSPK_REC          (BYTE)0X4C    // �����й�Կ�ָ�ʧ��
#define EMV_ERR_ICCPK_SSD_REC      (BYTE)0X4D    // IC����Կ�ָ�/ǩ���ľ�̬������֤ ʧ��
#define EMV_ERR_INTERAUTH          (BYTE)0X4E    // �ڲ���֤����ʧ��(��Ƭ����λ,SW�����)
#define EMV_ERR_GET_SDD            (BYTE)0X4F    // ��ȡǩ����̬��֤����ʧ��
#define EMV_ERR_SDD_REC            (BYTE)0X50    // ǩ����̬������֤ʧ��
#define EMV_ERR_CID_INCONSISTENT   (BYTE)0x51    // CID���ݲ�һ��


// �ѻ�PIN��֤����
#define EMV_PIN_TRYAGAIN           (BYTE)0x53    // ����������PIN
#define EMV_PIN_CHALLENGEERR       (BYTE)0X54    // EM_pin_CHALLENGEERR 
#define EMV_PIN_VERIFYERR          (BYTE)0X55    // EM_pin_VERIFYERR 

#define EMV_MUST_USE_AIDLST        (BYTE)0x74    // ����ת��AID�б�ʽ������ѡ�б�
#define EMV_ERR_INTERNATION_CARD   (BYTE)0xD1	 	 //���ʿ�
#define EMV_ERR_DDAVER		   (BYTE)0xD2	 	 //DDA�汾��֧��
#define EMV_ERR_DELAY		   (BYTE)0xD3	 	 //��Ҫ�ӳٲ���Ѱ��
#define EMV_ERR_CARDTIMEOUT	   (BYTE)0xD4	   //��Ҫ�жϲ���Ѱ��
#define EMV_ERR_USCARD		   (BYTE)0xD5	   //US CARD
#define EMV_ERR_DATA_DUP	   (BYTE)0xE7    // �����ظ�


// EMV L2 �ں��п���ʱ�洢�����ݵ�������
#define  MAX_MODULUS_LEN         248       // ���Կģ���ȣ��ֽ�����
#define  ISS_SCRPT_RSLT_MAX      12*5      // �����нű��������ֽ���(��12���ű�,ÿ��ռ��5�ֽ�)
#define  CAND_LIST_MAX_NUM       16        // ӦͬCANDLIST.H����һ��
#define  MAX_PKFILE_NUM          18        // �洢�����Կ��
#define  MAX_CERT_FILE           100        // ����Cert�б�������Ŀ
#define  AID_LIST_MAX_NUM        128        // AID�б��������
#define  CAND_LIST_MAX_NUM       16        // ��ѡ�б��������


#define EMV_QPBOC_TC               (BYTE)0x61    // QPBOC,�ѻ���׼
#define EMV_QPBOC_AAC              (BYTE)0x60    // QPBOC,�ѻ��ܾ�
#define EMV_QPBOC_ARQC             (BYTE)0x62    // QPBOC,����
#define EMV_QPBOC_CONT             (BYTE)0x63    // QPBOC,��Ҫת�Ӵ���
#define EMV_MSD_READ         			 (BYTE)0x65    // MSD,���ȡ����  
#define EMV_MSD_NOREAD             (BYTE)0x66    // MSD,�����ȡ����
#define EMV_WAVE2_OFFLINE          (BYTE)0x67    // WAVE2�ѻ���׼  
#define EMV_WAVE2_ONLINE           (BYTE)0x68    // WAVE2����

#define EMV_ERR_DATE_OUT      		 (BYTE)0xEE		 // ���ڿ�
#define EMV_AAC_FILL               (BYTE)0x21    // ��Ϊ���������AAC,����Ҫ���ֵ
#define EMV_ARQC_FILL              (BYTE)0x22    // ��Ϊ���������ARQC,����Ҫ���ֵ

#define         KERNOPT_PIN_BYPASS    (BYTE)2		//��ѡ��Ϊ1ʱ������PINʱ��������������֤����
#define         KERNOPT_CHK_KEYIDX    (BYTE)4		//��ѡ��Ϊ1ʱ�������Ӧ��Կ����������ֹ����¼
/*******************************************************

  �ն�����Ԫ�ṹ

*******************************************************/
typedef struct TM_FIX_DATA
{ 
	BYTE   tTmCntrCode [2];  // �ն˹��Ҵ���
	BYTE   tAquirerID[6];    // �յ��б�ʶ'9F01' (6�ֽ�)
	BYTE   tMerchCatCode[2]; // �̻�������'9F15'(2�ֽ�) 
	BYTE   tTmTransCur[2];   // �ն˽��׻��Ҵ���'5F2A'(2�ֽ�) 
	BYTE   cTmTransCurExp;  // �ն˽��׻���ָ��'5F36'(1�ֽ�)

	BYTE   tTmRefCurCode[2]; // �ն˽��ײο����Ҵ���'9F3C'(2�ֽ�)
	BYTE   tTmRefCurExp;	  // �ն˽��ײο�����ָ��'9F3D'(1�ֽ�)
	BYTE   tTmRefCurConv[4]; // �ն˽��ײο����Ҷһ�(4�ֽ�) 
}TmFixData; 


//  �ն�Ӧ���������Ԫ
typedef struct INIT_EMV_DATA_STRUCT
{
	BYTE   tTmID[8];            // �ն˱�ʶ(�ն˺�)
	BYTE   tMerchantID[15];     // �̻���ʶ(15�ֽ�) 
	WORD   wMCHLOCLen;          // �̻����Ƽ�λ��������ĳ���
	BYTE   tMCHNAMELOC[256];    // �̻����Ƽ�λ��(1-256 �ֽ�)
	BYTE   tTmTransCateCode;    // �ն˽���������
	
	BYTE   tAppVerNo[2];        // Ӧ�ð汾��(2�ֽ�) 
	BYTE   cTmRmCheckFlg;       // ���յ���ȷ���Ƿ�����ն˷��չ�����
									// = 0: �����з��չ���
									// = 1: ������з��չ���
	                                // = 2: ��AIP����

	
	BYTE   tTAC_Denial[5];      // �ն���Ϊ����TAC���ܾ�(5�ֽ�) 
	BYTE   tTAC_Online[5];      // �ն���Ϊ����TAC������(5�ֽ�) 
	BYTE   tTAC_Default[5];     // �ն���Ϊ����TAC��Ĭ��(5�ֽ�)  
	BYTE   cLenTDOL;            // TDOL�ĳ���
	BYTE   tTDOL[252];          // TDOL
	BYTE   cLenDDOL;            // DDOL�ĳ���
	BYTE   tDDOL[252];          // DDOL 
	BYTE   tFloorLmt[11];       // ����޶�(11�ֽ�)
	BYTE   tLmt[11];		    // ���ѡ����ֵ
	BYTE   tPercent[3];         // ���ѡ��Ŀ��ٷ���
	BYTE   tMaxPercent[3];      // ���ѡ�����Ŀ��ٷ���

}AppInitData; 

// ���׿�ʼ����Ҫ������
typedef struct  START_APP_DATA_STRUCT
{
    DWORD  lAmntAuth;      // ��Ȩ���(unsigned long)
    DWORD  lAmntOther;     // �������(unsigned long)
	BYTE   cTransType;    // ��������'9C'	
    BYTE   tDate[3];       // ��������ָ��(3 BYTE)
    BYTE   tTime[3];       // ����ʱ��ָ��(3 BYTE)
    BYTE   tTrace[4];      // �������м�����(4 BYTE)    
 	BYTE   cRFU;
}StartAppDt;


/* ����AID�б�Ľṹ */
typedef struct TERM_CAND_LIST_STRUCT
{
	BYTE   tAID[16];       // AID
	BYTE   cLenAID;  
	BYTE   tAppLabel[16];  // Ӧ�ñ�ǩ
	BYTE   cLenLabel;
	BYTE   tAPN[16];  	   // Ӧ����ѡ��
	BYTE   cLenAPN;   
	BYTE   cAPID;          // Ӧ������Ȩ��ʶ��
	BYTE   cFlgAPID;       // Ӧ������Ȩ��ʶ����־
	BYTE   sLangPref[8];   // ��ѡ����
	BYTE   cLenLangPref;  
	BYTE   cIssCTIndex;    // �����д��������
	BYTE   cFlgIssCTIndex; 
}DCandList;

// ������ɷ�������
typedef struct  TRANS_DATA_STRUCT
{
    BYTE   tExpDate[4];         // ʧЧ����  
    BYTE   cFlgCID;
    BYTE   cCID;                // ������Ϣ����
    BYTE   cFlgAC;
    BYTE   tAC[8];              // Ӧ������
    BYTE   cFlgTVR;
    BYTE   tTVR[5];             // �ն���֤���
    BYTE   cFlgTSI;
    BYTE   tTSI[2];             // ����״̬��Ϣ
    BYTE   cFlgTrack2;
    BYTE   tTrack2[19];         // ���ŵ��ȼ�����
    BYTE   cFlgATC;
    BYTE   tATC[2];             // Ӧ�ý��׼�����
    BYTE   cFlgAIP;
    BYTE   tAIP[2];             // Ӧ�ý�������
    BYTE   cFlgAUC;
    BYTE   tAUC[2];             // Ӧ����;����
    BYTE   cFlgCVMR;
    BYTE   tCVMR[3];            // �ն���֤���
    BYTE   cFlgIAC_Denial;
    BYTE   tIAC_Denial[5];      // ��������Ϊ���룭�ܾ�
    BYTE   cFlgIAC_Online;
    BYTE   tIAC_Online[5];      // ��������Ϊ���룭����
    BYTE   cFlgIAC_Default;
    BYTE   tIAC_Default[5];     // ��������Ϊ���룭Ĭ��
	BYTE   tIssSrptRslt[ISS_SCRPT_RSLT_MAX];    // �����нű����
	BYTE   cNumIssSrptRslt;                     // �����нű��������
	BYTE   tUnpreNumber[4];      // ����Ԥ֪��
	BYTE   tARC[2];              // ARC
	BYTE   cFlgSign;             // ǩ����־
	BYTE   cLenIssAppDt;         // ������Ӧ�����ݳ��� 
	BYTE   tIssAppDt[32];        // ������Ӧ������
}TransDt;

/******************************************************************************
* CA��Կ���ݽṹ
******************************************************************************/
typedef  struct PUBLIC_KEY_FILE
{ 
	BYTE   cRid[5];  		       // RID
	BYTE   cIndex;   		       // ��Կ����	
	BYTE   cModLen;       	       // ��Կģ�ĳ���
	BYTE   cMod[MAX_MODULUS_LEN]; // ��Կģ	
	BYTE   cExpLen;               	// ��Կָ���ĳ���
	BYTE   cExp[3];           	    // ��Կָ��
	BYTE   cExpDate[4];             // ��ԿʧЧ��, YYYYMMDD�����ֽ�����������
	BYTE   cHashFlg;                // ��ԿУ����Ƿ����
	BYTE   cHash[20];               // ��ԿУ��� - ���ڶ��ڼ��, �ɲ���ֵ
}PKFILESTRU;

typedef  struct CERTIFICATE_FILE
{
	BYTE   cIndex;   		        // ��Կ����
	BYTE   cRid[5];  		        // RID
	BYTE   cCertSn[3];              // ֤�����к�
	BYTE   tRFU[3];                 // RFU,���ṹ�ֽ������Ϊ4��������
}CertFile;

/* ����AID�б�Ľṹ */
typedef struct TERM_AID_LIST_STRUCT
{
	BYTE  cLen;     // AID���Ƶĳ���
	BYTE  tAID[16];	// AID����
	BYTE  cFlg;	    // ����ѡ���ʶ
	BYTE  tRFU[2];  // RFU,���ṹ�ֽ������Ϊ4��������
}DAidList;

// �ֿ���֤����֤����Ҫ������
typedef struct  CARD_HOLDER_CERT_DATA_STRUCT
{
    BYTE   cCertType;       //  ֤������
    BYTE   cTypeLen;        //  �������ݳ���
    BYTE   cCertData[41];   //  ֤�����(40 BYTE)
    BYTE   cCertLen;        //  ֤�����ݳ���      
}HolderCertDt;   
   
/* MCK ���ýṹ */
typedef struct CONFIGURATION_STRUCT
{ // ���� ISS�г��ֵ��Ⱥ�˳������
	BYTE   cTmType;          // �ն�����
	BYTE   tTmCap [3];       // �ն�����
	BYTE   tTmCapAd [5];     // �����ն����� 	
	BYTE   cSupPSESelect;        // PSEѡ��ʽ    
	
	BYTE   cSupAppConfirm;   // ֧�ֳֿ���ȷ��, �ɳֿ���ѡ��Ӧ��
	BYTE   cSupAppDispOrder; // ֧�ְ�ָ��˳����ʾ��ѡӦ��
	BYTE   cSupMulLang;      // ֧�ֶ�����
    BYTE   cSupIssCertCheck ; // IssCert ��� 
	BYTE   cSupDDOLFlg ;      // ֧��Ĭ��DDOL       
	
	BYTE   cSupBypassPIN;     // Bypass PIN, ����������     
	BYTE   cSupFlrLmtCheck ;  // ����޶���    
	BYTE   cSupRndOnlineSlt;  // �������ѡ�� 
	BYTE   cSupVeloCheck;     // Ƶ�ȼ��     
	BYTE   cSupTransLog;      // ������־ - KERN ������޶�����ʹ��
	
	BYTE   cSupExcptCheck ;   // �쳣�ļ���� 
	BYTE   cTmRmCheckFlg ;    // TRM���: �Ƿ�֧����Ӧ�ó�������Ƿ����TRM���                  
	BYTE   cSupTmActionCode;  // ֧���ն���Ϊ���� - kern ��TERMAA.c���ն���Ϊ������ʹ��
	BYTE   cSupForceOnline;      // ����ǿ����������
	BYTE   cSupForceAccept;      // ����ǿ�ƽ�������
	
	BYTE   cSupAdvice;           // �ն��Ƿ�֧��֪ͨ
	BYTE   cSupIssVoiceRef;      // ֧�ַ����з���Ĳο�
	BYTE   cSupCardVoiceRef;      // ֧�ֿ�Ƭ����Ĳο�
	BYTE   cSupBatchCollect;     // ֧�������ݲɼ�  
	BYTE   cSupOnlineCollect ;   // ֧���������ݲɼ�             
	
	BYTE   cSupTDOLFlg ;      // ֧��Ĭ��TDOL                    
	BYTE   cPOSEntryMode[3] ; // POS��Entry Code  "025"	
	BYTE   tHashVal[20];      // ������ö�Ӧ��hashֵ
	BYTE   tRFU[2];
}CfgStru; // 1-> ֧��


/* ������ڿ�Ƭ��־��Ӧ�ýṹ */
typedef struct TERM_CL_LIST_STRUCT
{

	BYTE   tAid[16];  // Ӧ�ñ�ǩ
	BYTE   cLenAID;		// Ӧ�ñ�ǩ����
	BYTE   cLogFSI;		// ��Ƭ��־SFI
	BYTE   cLogNum;		// ��Ƭ��־����
	BYTE   cAppIsLock;	// ��Ӧ���Ƿ�����

}DClList;


//201412 UM
typedef struct
{   
	uchar ucTmType;        // �ն�����     Ĭ��: \x15 ���ڻ������Ƶ��������������ѻ��ն�
	uchar auTmCap[3];      // �ն�����     Ĭ��: \x60\x48\xC8 �ֿ�����֤��ʽ��֧����������PIN��NO CVM
    uchar auTmCapAd[5];    // �����ն����� Ĭ��: \x6F\x00\xF0\xF0\x01
	uchar auCntCode[2];    // ���Ҵ���     Ĭ��: \x01\x56 �й�
	uchar auCurCode[2];    // ���Ҵ���     Ĭ��: \x01\x56 �����
	uchar auTAC_Denial[5]; // �ն���Ϊ���� TAC���ܾ�  ȱʡ:\x00\x00\x00\x00\x00
	uchar auTAC_Online[5]; // �ն���Ϊ���� TAC������  ȱʡ:\xFF\xFF\xFF\xFF\xFF
	uchar auTAC_Default[5];// �ն���Ϊ���� TAC��Ĭ��  ȱʡ:\xFF\xFF\xFF\xFF\xFF
	uchar cLenTDOL;			//ȱʡTDOL���ȣ�Ĭ��:3
	uchar auTDOL[252];		//ȱʡTDOL��Ĭ�ϣ�"\x9F\x08\x02"
	uchar cLenDDOL;			//ȱʡDDOL����,Ĭ��11
	uchar auDDOL[252];		//ȱʡDDOL��Ĭ�ϣ�"\x9F\x37\x04\x9F\x47\x01\x8F\x01\x9F\x32\x01"

	uint  uiRandPer;       // ���ѡ��Ŀ��ٷ���
    uint  uiRandPerMax;    // ���ѡ�����Ŀ��ٷ���
//��������ݿ����Ȳ�����
	uchar auTTQ[4];        // [�ǽ�]�ն˽�������9F66  ȱʡ:\x44\x80\x00\x80(֧������PIN����֧�ַǽ�С��֧������֧�ַǽӱ�׼�����)
	uchar auECashLmt[6];   //  �����ֽ����޶�9F7B   BCD���룬���磺123.45�������Ϊ:\x00\x00\x00\x01\x23\x45            
	uchar auTransLmt[6];   // [�ǽ�]�ǽ��޶� BCD���룬���磺123.45�������Ϊ:\x00\x00\x00\x01\x23\x45
	uchar auCVMLmt[6];     // [�ǽ�]CVM�޶�  BCD���룬���磺123.45�������Ϊ:\x00\x00\x00\x01\x23\x45
    uchar auFloorLmt[6];   // [�Ӵ���ǽ�]����޶  BCD���룬���磺123.45�������Ϊ:\x00\x00\x00\x01\x23\x45
	uchar auRandLmt[6];    // ���ѡ����ֵ   BCD���룬���磺123.45�������Ϊ:\x00\x00\x00\x01\x23\x45
	uint  RFULen;          // ���������ݳ���
	uchar RFU[600];        // ������, �����ն�TLV����Ԫ:�ն˱�ʶ(9F1C)���̻���ʶ(9F16)���̻�����(9F4E)��Ӧ�ð汾��(9F09)������������(9F53)��	                     
}EMV_tTmParam;


typedef struct
{
	uchar auAmount[6];     //���׽�    BCD����, ���磺123.45��      �����Ϊ:\x00\x00\x00\x01\x23\x45
	uchar auAmountOth[6];  //������    BCD����, ���磺123.45��      �����Ϊ:\x00\x00\x00\x01\x23\x45,	ȱʡ��\x00\x00\x00\x00\x00\x00
	uchar auDate[3];       //�������ڣ�    BCD����, ����: 2012��6��1�գ������Ϊ:\x12\x06\x01
	uchar auTime[3];       //����ʱ�䣺    BCD����, ����: 18ʱ32��20�룬�����Ϊ:\x18\x32\x20
	uchar auTrace[4];      //���׼�������  BCD����, ���磺��63421�Σ�   �����Ϊ:\x00\x06\x34\x21,ȱʡ��\x00\x00\x00\x00
	uchar ucForceOnline;   //ǿ��������ʶ��0-��ǿ��������      1-ǿ������
	uchar ucECashSup;      //�����ֽ��ʶ: 0-��֧�֣�          1-֧��(��Ϊ������ʽΪ�Ӵ�������ǿ��������־Ϊ0ʱ��Ч)
}EMV_tTransStart;


typedef struct
{
	uchar ucState;             // ����״̬: 0-�������� 1-����ʧ��
	uchar auARC[2];            // ��Ȩ��Ӧ�룬��39������
	uint  uiDataLen;           // ������ӦоƬ���ݳ���
	uchar auData[512];         // ������ӦоƬ���ݣ�55�����ݣ�
}EMV_tHostData;

// IC�����Խṹ
typedef struct ICCARD_STATUS
{
	char cTP;	         	// ����Э���ʶ(�ַ�or��֡)
	char cCardType;	        // IC����������
	DevHandle hCardHandle;  // IC��������� 
}DCardSt;

typedef void (*PrintMessage)(BYTE *p);    

RTBYTE       EA_EMV_InitTmFixData(TmFixData *ptTmFixDt);
RTBYTE       EA_EMV_InitiateEMV(AppInitData *pInitDt);  	

// ����������ؽӿ�	2-��ȡ��Ƭ��־
RTBYTE       EA_EMV_CardLogAppSlt(DCardSt  *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
RTBYTE       EA_EMV_GetCardLogFormat(BYTE *tBuf, WORD *cLen);
RTBYTE       EA_EMV_GetRecordDt_ZY(BYTE cRecNo, BYTE cSFI, BYTE *pRecDt, WORD *pRecDtLen);

// ����������ؽӿ� 3-EMV ����
RTBYTE       EA_EMV_AppSelection(DCardSt *ptCardSt, BYTE cSelType, BYTE *pList, WORD *pwLenList);
RTBYTE       EA_EMV_SetAccountType(BYTE cType);
RTBYTE       EA_EMV_StartApplication(BYTE cAidNo, StartAppDt  *pDt,BYTE *pList, WORD  *pwLenList);              

RTBYTE       EA_EMV_ReadAppData( BYTE *pList, WORD  *pwLenList);
RTBYTE       EA_EMV_OfflineDataAuth(void);

RTBYTE       EA_EMV_TermRiskManage( BYTE cIsBlackCard, DWORD lPanAmnt , BYTE *cResult);
RTBYTE       EA_EMV_ProcessRestrict( BYTE  *cResult );

RTBYTE       EA_EMV_ActionAnalysis(BYTE cCmd, TransDt  *pTransDt);
RTBYTE       EA_EMV_OnlineDataProcess(BYTE *pIssDt, WORD wLenIssDt,TransDt  *pTransDt);  	

	
// MCK ���ò���ѡ��	
RTBYTE       EA_EMV_ucSetMCKConfig(CfgStru *pCfgDt);

// ����/��ȡ����Ԫ	
RTBYTE       EA_EMV_SetData (BYTE *pDt, WORD wLenDt);
RTBYTE       EA_EMV_GetData(BYTE *pDol, WORD wLenDol, BYTE *pVal, WORD *pwLenVal);
RTBYTE       EA_EMV_GetAppData(BYTE *pTag, BYTE cTagLen, BYTE *pVal, WORD *pwLen);
RTBYTE       EA_EMV_GetCDOL(BYTE cDolType, BYTE *pCDOL, WORD *pwLenCDOL,BYTE *pCDOLPad, WORD *pwLenPad);

// �������ѡ�����
RTBYTE       EA_EMV_SetRandSelectionData(long lLmt, long lPercent, long lMaxPercent);

// ���û���֤��
RTBYTE       EA_EMV_SetCertSn(CertFile *pCertFile, BYTE cNum);
RTVOID       EA_EMV_DelAllCAPKeyCertSn(void);
RTBYTE       EA_EMV_DelCAPKeyCertSn(BYTE *pCertSn, BYTE *pRid, BYTE cIndex);

// ����/��ȡ�ն�AID�б�
RTVOID       EA_EMV_DelallTermAIDList(void);
RTBYTE       EA_EMV_DelAidListAid(BYTE *pAid, BYTE cLenAid);

RTBYTE       EA_EMV_SetTermAIDList(DAidList *pAidList, BYTE cNum);
RTBYTE       EA_EMV_SetAidListItem(BYTE *pAid, BYTE cLenAid, BYTE flag);

RTBYTE       EA_EMV_GetAidListAidNum(void);
RTBYTE       EA_EMV_GetALLAidListStru(BYTE cNum, DAidList *pAidList);
RTBYTE       EA_EMV_GetAidListStruByNo(BYTE cNo, DAidList *pAidList);

// ��Կ����/ɾ��/��ȡ
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
//��ȡQVSDC/QPBOC ��Ƭ��֤���
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


//��������
RTBYTE EA_EMV_ucSetAPDUInterface(BYTE *ptICDll, BYTE *ptICFunc,
		 BYTE *ptRFDll, BYTE *ptRFFunc);
RTBYTE EA_EMV_ucTmParamInit(EMV_tTmParam *ptTmParam);

RTBYTE EA_EMV_AppSelect	(BYTE ucInterFace, WORD *pwLenList,BYTE *pList );

RTBYTE EA_EMV_ucGeneAC(WORD wLenDOL, BYTE *pDol,
						WORD *pwLenOLDt,BYTE *pOLDt, 
						BYTE *pcInputPIN);

//ʵ��EMV���׵�ǰ��Σ�������ȡ����ѡ��Ͷ�ȡӦ������
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

