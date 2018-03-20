/*********************************************************************
* ��Ȩ���� (C)2003-2008, �������������豸���޹�˾��
* �ļ����ƣ� 
*   DEF.H
* ��ǰ�汾�� 
*   
* ����ժҪ�� 
*     �������Ͷ���
* ��ʷ��¼��
*     �޸���		����			�汾��          
*     ����        2008-06-21        UNIMARSII 1.0
******************************************************************/
#ifndef _MACRODEF_H_
#define _MACRODEF_H_


/******************************************************************

                        ���Ͷ���

******************************************************************/
#define dim(x)          (sizeof(x) / sizeof(x[0]))

#ifndef uchar
typedef unsigned char                   uchar;
#endif

#ifndef ushort
typedef unsigned short                  ushort;
#endif

#ifndef uint
typedef unsigned int                    uint;
#endif

#ifndef ulong
typedef unsigned long long              ulong;
#endif

#ifndef DevHandle
typedef int                   DevHandle;
#endif

#ifndef DevHandle
typedef int                   OSHandle;
#endif

#ifndef int_64 
#ifdef PLATFORM_IN_PC
typedef __int64                         ET_timeout_VALUE;
typedef __int64                         int_64;
typedef unsigned __int64                uint_64;
#else
typedef unsigned long long              ET_timeout_VALUE;
typedef long long                       int_64;
typedef unsigned long long              uint_64;
#endif
#endif

/******************************************************************

                        ����ֵ

******************************************************************/
// ��ģ�鹲�����
#define     EM_SUCCESS                  (uchar)0x00
#define     EM_ERROR                    (uchar)0x01
#define     EM_ABOLISH                  (uchar)0x1B
#define     EM_NOTPERMIT				(uchar)0x86  
#define     EM_NOTEXIST					(uchar)0x87  
#define     EM_ALREADY_EXIST			(uchar)0x88  
#define     EM_DEVICE_USED              (uchar)0x89  
#define     EM_TIMEOUT                  (uchar)0x8A
#define     EM_ERRPARAM                 (uchar)0x8B
#define     EM_ERRHANDLE                (uchar)0x8C
#define     EM_DEVICE_DISABLE           (uchar)0x8D
#define     EM_ALLOCERR                 (uchar)0x8E
#define     EM_FAILED                   (uchar)0x8F

/******************************************************************

                        �����ַ�����

******************************************************************/
#define     CR                          (uchar)0x0D             /* Carrige Return  */
#define     LF                          (uchar)0x0A             /* Line Feed       */
#define     SP                          (uchar)0x20             /* SPace           */
#define     BS                          (uchar)0x08             /* Back Space      */
#define     TAB                         (uchar)0x09             /* TAB             */
#define     HOME                        (uchar)0x0C             /* HOME            */
#define     ESC                         (uchar)0x1B
#define     BELL                        (uchar)0x07             /* BELL            */
#define     ENT                         (uchar)0x0FE            /* ENTer           */ 


/******************************************************************

                        ��������

******************************************************************/
#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef EM_INVALID_HANDLE               // ��Ч���
#ifdef  __cplusplus
#define EM_INVALID_HANDLE    (DevHandle)-1
#else
#define EM_INVALID_HANDLE    (DevHandle)-1
#endif
#endif

#ifndef EM_NULL                // ��Чָ��
#ifdef  __cplusplus
#define EM_NULL    0
#else
#define EM_NULL     0
#endif
#endif

#endif
