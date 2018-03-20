//
//  KFLoger.h
//  navi
//
//  Created by zhujuzhang on 11/1/12.
//
//

/****************************************************************************
              统一KF框架日志类
 支持控制台打印和保存日志文件，使用队列和多线程的方式保存日志，避免了频繁的IO堵塞主线程
   1. 针对不同类型的日志,定义了不同的宏接口（最下方）, 使用者根据需求直接调用四个宏接口,
      支持可变参数输入
      eg:  KFLog_Normal(YES, @"测试日志哈哈哈 %d", 8)
 
   2. 日志格式: 年-月-日 时:分:秒 文件名 接口名 Line:行数  日志类型: 日志内容
      eg: 2012-11-1 13:20:28 File:TestApp.mm Line:29  NORMAL: 测试日志哈哈哈
 
   3. 日志文件保存在应用程序的沙盒Library/Caches目录下，以日期进行命名.
      eg: Log_2012-11-06.dat 
 
   4. 在app退出或者其他情况下，需要强制写文件，使用 KFLog_Flush()宏
 
   5. 增加了开发级别的log接口，三个级别，可以使用三个宏来控制是否开启
 
   6. 建议在工程的pch文件中引用此头文件,这样可以避免多处引用
        #import "KFLoger.h"
******************************************************************************/


#import <Foundation/Foundation.h>
#include <sys/time.h>

#define  kMAX_CACHE_LOG_COUNT     1      //日志队列里，最大缓存日志数，达到就写文件


//  #define  KFLOG_OPEN                       // 总的日志开关，确认发布时根据需要是否关闭

//#define  KFLOG_PRINT_CONSOLE              // 总的控制台打印日志开关

//#define  KFLOG_ALL_WRITE_FILE             // 控制所有的日志都写文件,注意只是测试时使用打开 默认关闭

//用于控制开发级别log的开关,级别从0到2逐渐增加
#define  kOPEN_DEV_0
#define  kOPEN_DEV_1
#define  kOPEN_DEV_2


//日志的信息类型
enum KFLoger_Type
{
    LogType_None = -1,
    
    LogType_Normal,       //普通log
    LogType_Debug,        //调试log
    LogType_Warning,      //警告信息log
    LogType_Error,        //错误信息的log
    
    //增加开发使用的log，分为三个级别,0-2, 级别逐渐增加，可以用宏控制是否打印
    LogType_Dev_Level0,
    LogType_Dev_Level1,
    LogType_Dev_Level2,
    
};



//KF日志信息，由调用者创建，传递给KFLoger使用
@interface KFLogInfo : NSObject
{

    char*           _curSourceFileName;         //日志当前的打印代码文件名
    char*           _curFuncName;               //日志当前的模块名
    NSString*       _logTextContent;            //日志的文本内容
    int       _curSourceLineNum;          //当前的行号
    
    struct tm*      _logTime;                   //日志时间
    int       _logType;                   //日志类型
    BOOL            _isNeedSaveFile;            //是否保存文件
}


@property(nonatomic, assign)char* curSourceFileName;
@property(nonatomic, assign)char* curFuncName;
@property(nonatomic, retain)NSString* logTextContent;
@property(nonatomic, assign)int    curSourceLineNum;
@property(nonatomic, assign)struct tm* logTime;
@property(nonatomic, assign)int    logType;
@property(nonatomic, assign)BOOL   isNeedSaveFile;


@end




// KF日志类
@interface KFLoger : NSObject
{

    NSMutableArray*     _logArray;     //按照加入顺序保存日志的队列
    NSFileHandle*       _fileHandle;   //日志的文件句柄
    NSString*           _filePath;     //日志文件路径
    dispatch_queue_t    _logWriteQueue; //日志写对列
}



+(KFLoger*)GetInstance;


- (void)addLog:(NSString*)txtContent sourceName:(const char*)sourceName funcName:(const char*)funcName  lineNum:(int)lineNum logType:(NSInteger)logType isNeedSave:(BOOL)isNeedSave;

- (void)flushLogs;
@end




#ifdef SLP_DEBUG_KFLOG_OPEN    //打开所有的日志开关

//封装一个宏,  外部不要直接调用这个宏
#define KFLog(type, needSave,logContent,...)                                                    \
            {                                                                                   \
                if( (logContent != nil))                                                        \
                {                                                                               \
                    NSString* logFormat = [NSString stringWithFormat:logContent,##__VA_ARGS__]; \
                    [[KFLoger GetInstance]addLog:logFormat                                      \
                                       sourceName:__FILE__                                      \
                                         funcName:__FUNCTION__                                  \
                                          lineNum:__LINE__                                      \
                                          logType:type                                          \
                                       isNeedSave:needSave];                                    \
                }                                                                               \
            }                                                                                   \


#else

#define  KFLog(type, needSave, logContent,...)

#endif




#pragma mark -------------------------------------------------------对外接口宏定义
#pragma mark --- 不同类型的日志宏，外部直接使用
// needSave: 是否需要写文件保存    logContent: 日志文本内容(NSString)

//普通日志
#define KFLog_Normal(needSave, logContent,...)         KFLog(LogType_Normal, needSave,logContent,##__VA_ARGS__)

//debug日志
#define KFLog_Debug(needSave, logContent,...)          KFLog(LogType_Debug, needSave, logContent,##__VA_ARGS__)

//警告信息日志
#define KFLog_Warning(needSave, logContent,...)        KFLog(LogType_Warning, needSave, logContent,##__VA_ARGS__)

//错误信息日志
#define KFLog_Error(needSave, logContent,...)          KFLog(LogType_Error, needSave, logContent,##__VA_ARGS__)


//开发使用的log, 不同的级别
#define KFLog_Dev0(needSave, logContent,...)           KFLog(LogType_Dev_Level0, needSave, logContent,##__VA_ARGS__)

#define KFLog_Dev1(needSave, logContent,...)           KFLog(LogType_Dev_Level1, needSave, logContent,##__VA_ARGS__)

#define KFLog_Dev2(needSave, logContent,...)           KFLog(LogType_Dev_Level2, needSave, logContent,##__VA_ARGS__)

//强制保存日志到文件
#define KFLog_Flush()       [[KFLoger GetInstance] flushLogs]



//这个宏是用来控制日志全部都写到文件里去
#define KFLog_FORCE(type, needSave,logContent,...)                                                    \
        {                                                                                   \
            if( (logContent != nil))                                                        \
            {                                                                               \
                NSString* logFormat = [NSString stringWithFormat:logContent,##__VA_ARGS__]; \
                [[KFLoger GetInstance]addLog:logFormat                                      \
                sourceName:__FILE__                                      \
                funcName:__FUNCTION__                                  \
                lineNum:__LINE__                                      \
                logType:type                                          \
                isNeedSave:needSave];                                    \
            }                                                                               \
        }                                                                                   \

#define KFLog_WRITE_FILE(needSave, logContent,...)           KFLog_FORCE(LogType_Dev_Level2, needSave, logContent,##__VA_ARGS__)
