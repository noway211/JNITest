package com.peter.jnitest.jni;


import android.util.Log;

/**
 * Created by Administrator on 2018/1/3.
 */

public class PeterJni {

    public static String TAG = "peterjava";

    public String TAG2="fdasfsfdsafd";

    static {
        System.loadLibrary("peterjni");
    }


    public static void testStaticMethod(){
        Log.e(TAG,"static method call");
    }

    private void testInstanceMethod(){
        Log.e(TAG,"object method call");
    }

    public static native String getJNIString();

    public static native String getLowcase(String sourceString);

    public static native  void changeArray(int[] source);

    public static native void accessField(Object object);

    public static native void accessMethod(Object object);





}
