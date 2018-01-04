package com.peter.jnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.peter.jnitest.jni.PeterJni;

public class MainActivity extends AppCompatActivity {

    private PeterJni jniObject  = new PeterJni();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jniObject.TAG2="instanceValue=Peterzhukui";
    }


    public void btnOnClick(View view){
        switch (view.getId()){
            case  R.id.btn_newstr:
                Log.e("peterresult=",PeterJni.getJNIString());
                break;
            case R.id.btn_low:
                Log.e("peterresult=",PeterJni.getLowcase("PWEREW AND losw"));
                break;
            case R.id.btn_chan:
                int[] sour = new int[]{1,2,3,4,5};
                PeterJni.changeArray(sour);
                Log.e("peterresult=",sour[0]+" "+sour[1]);
                break;
            case R.id.btn_pro:
                PeterJni.accessField(jniObject);
                break;
            case R.id.btn_method:
                PeterJni.accessMethod(jniObject);
                break;
        }

    }
}
