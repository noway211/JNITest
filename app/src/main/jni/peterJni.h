/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_peter_jnitest_jni_PeterJni */

#ifndef _Included_com_peter_jnitest_jni_PeterJni
#define _Included_com_peter_jnitest_jni_PeterJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    getJNIString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_peter_jnitest_jni_PeterJni_getJNIString
  (JNIEnv *, jclass);

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    getLowcase
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_peter_jnitest_jni_PeterJni_getLowcase
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    changeArray
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_changeArray
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    accessField
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_accessField
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    accessMethod
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_accessMethod
  (JNIEnv *, jclass, jobject);

#ifdef __cplusplus
}
#endif
#endif