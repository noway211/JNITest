#ifndef __A_LOG_H__
#define __A_LOG_H__

#include <android/log.h>

#define  LOG_TAG "peter-jni"

//#define  LOGD(fmt, args...)  __android_log_print(ANDROID_LOG_DEBUG,TAG, fmt, ##args)
#define  LOGD(fmt, args...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, fmt, ##args)

#endif

