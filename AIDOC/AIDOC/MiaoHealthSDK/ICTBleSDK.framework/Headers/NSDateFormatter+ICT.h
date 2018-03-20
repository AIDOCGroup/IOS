//
//  NSDateFormatter+ICT.h
//  iCareTek
//
//  Created by MikeZhou on 14-5-22.
//  Copyright (c) 2014年 iCareTech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDateFormatter (ICT)

/*
 * 以点号分隔 yyyy.MM.dd
 */
+ (NSDateFormatter *)YMDPointDateFormatter;

/*
 *yyyyMMddHHmmss
 */
+ (NSDateFormatter *)BLEDateFormatter;

/*
 *HHmm
 */
+ (NSDateFormatter *)BLEDateFormatterHM;

/*
 *MM.dd
 */
+ (NSDateFormatter *)MDPointDateFormatter;

/*
 *点分秒
 */
+ (NSDateFormatter *)trendsDateFormatter;

/*
 *yyyy.MM.dd HH:mm:ss
 */
+ (NSDateFormatter *)warnHistoryFormatter;

/**
 *  yyyy-MM-dd HH:mm:ss
 *
 *  @return
 */
+ (NSDateFormatter *)ymdhmsDashFormatter;

/**
 *  yyyy-MM-dd HH:mm:ss SSS
 *
 *  @return
 */
+ (NSDateFormatter *)ymdhmsSDashFormatter;

/**
 *  yyyy-MM-dd HH:mm
 *
 *  @return
 */
+ (NSDateFormatter *)ymdhmDashFormatter;



/**
 *  yyyy-MM-dd
 *
 *  @return
 */
+ (NSDateFormatter *)ymdDashFormatter;


/**
 *	@brief	中文某年某月某日
 */
+ (NSDateFormatter *)chineseYmd;


/**
 *	@brief	中文某年某月
 */
+ (NSDateFormatter *)chineseYm;

/**
 *	@brief	中文某月某日
 */
+ (NSDateFormatter *)chineseMd;

/**
 *	@brief	中文某年某月某日某时某分
 */
+ (NSDateFormatter *)chineseYmdhm;

/**
 *	@brief	年/月/日 时:分:秒
 */
+ (NSDateFormatter *)snoringInfoDateFormat;


@end
