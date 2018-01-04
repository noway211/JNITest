//
// Created by Administrator on 2018/1/3.
//
#include "peterJni.h"
#include "log.h"
#include <jni.h>
#include <android/log.h>
#include <cstring>


/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    getJNIString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_peter_jnitest_jni_PeterJni_getJNIString
  (JNIEnv *env, jclass){
    LOGD("new jni String");
    return env->NewStringUTF("jni-string-hello world");
  }

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    getLowcase
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_peter_jnitest_jni_PeterJni_getLowcase
  (JNIEnv *env, jclass, jstring sourcestr){

        // 为了在原生代码中使用Java字符串，需要先将Java字符串转换成C字符串
         // 这个函数可以将Unicode格式的Java字符串转换成C字符串
         // 第二个参数指定了是指向堆内原有对象还是拷贝一份新的对象
         // 这种获取的字符串只读
         const char *str = env->GetStringUTFChars(sourcestr, JNI_FALSE);
         LOGD("sourceString %s",str);
         // 获取字符串长度
         jint length = env->GetStringLength(sourcestr);
         char strs[length];
         // 这里必须要这么复制，自己手动改会有一个特殊字符（猜测是结尾的符号），
         // 在生成UTF字符串的时候会报错
         strcpy(strs, str);
         for (int i = 0; i < length; i++) {
             char c = str[i];
             if (c >= 'A' && c <= 'Z') {
                 strs[i] = (char) (c + 32);
             } else {
                 strs[i] = c;
             }
         }

         LOGD("newString %s",  strs);
         // 释放JNI函数返回的C字符串
         env->ReleaseStringUTFChars(sourcestr, str);
         return env->NewStringUTF(strs);
  }

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    changeArray
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_changeArray
  (JNIEnv *env, jclass, jintArray array_){
       LOGD("JNIchangeArray");
       jint *invalue = env->GetIntArrayElements(array_ , NULL);
       jint length = env->GetArrayLength(array_);
       // 这里对每个元素做+1操作
       for (int i = 0 ;i < length; i++){
           invalue[i] += 2;
       }
       // 释放JNI函数返回的C int 数组
        env->ReleaseIntArrayElements(array_, invalue,0);

  }

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    accessField
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_accessField
  (JNIEnv *env, jclass, jobject instance){
        jclass clazz = env->GetObjectClass(instance);
         // JNI提供了用域ID访问两类域的方法，可以通过给定实例的class对象获取域ID
         // 用GetObjectClass函数可以获得class对象
         // 获取实体对象属性id
         jfieldID instanceFieldId = env->GetFieldID(clazz, "TAG2", "Ljava/lang/String;");
         // 获取属性值
         jstring jstr_value = (jstring) env->GetObjectField(instance, instanceFieldId);
         const char *ch_value = env->GetStringUTFChars(jstr_value, NULL);
         LOGD("getinstanceFieldValue %s",ch_value);

          // 释放JNI函数返回的C字符串
          env->ReleaseStringUTFChars(jstr_value, ch_value);
        //获取静态属性
         jfieldID staticFieldId = env->GetStaticFieldID(clazz, "TAG", "Ljava/lang/String;");
        //获取静态属性值
        jstring jstatic_value = (jstring) env->GetStaticObjectField(clazz,staticFieldId);
        const char *stach_value = env->GetStringUTFChars(jstatic_value, NULL);
         LOGD("getStaticFieldValue %s",stach_value);

       // 释放JNI函数返回的C字符串
          env->ReleaseStringUTFChars(jstatic_value, stach_value);





  }

/*
 * Class:     com_peter_jnitest_jni_PeterJni
 * Method:    accessMethod
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_peter_jnitest_jni_PeterJni_accessMethod
  (JNIEnv *env, jclass, jobject instance){
    jclass clazz = env->GetObjectClass(instance);
     //获取方法id，
     jmethodID i_id = env->GetMethodID(clazz, "testInstanceMethod", "()V");
     jmethodID s_id = env->GetStaticMethodID(clazz, "testStaticMethod", "()V");
     //反射调用方法
     env->CallVoidMethod(instance,i_id);
     env->CallStaticVoidMethod(clazz,s_id);

  }



