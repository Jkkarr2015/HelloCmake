package com.example.jkarr.hello_cmake;

import android.app.DownloadManager;
import android.content.Intent;
import android.location.Location;
import android.net.Uri;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;

import java.io.File;
import java.util.ArrayList;
import java.util.Vector;

public class MainActivity extends AppCompatActivity {

    //Used to load the 'native-lib' library on application startup.
    static {

        System.loadLibrary("native-lib");
        System.loadLibrary("protobuf-lite");

        System.loadLibrary("z");

    }



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //File filePath = getExternalFilesDir(null);

        OSMMapDL2 map = new OSMMapDL2();


        File filePath = map.createOSMDir();
        // Example of a call to a native method
        testBeaconSearch();
        testPOISearch();
        TextView tv = (TextView) findViewById(R.id.sample_text);
        String foo1 = stringFromJNI();
        tv.setText(foo1);
        downLoadFiles(filePath);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void testBeaconSearch();
    public native void testPOISearch();
    //public native ArrayList<String> testPOItest();
    public void downLoadFiles(File filePath){
        long downloadReference;
        Uri map_url = Uri.parse("http://maps.aphtech.org/osm/north-america/Kentucky/kansas-latest_Beacon.osm.pbf");
        DownloadManager downloadManager = (DownloadManager)getSystemService(DOWNLOAD_SERVICE);
        DownloadManager.Request request = new DownloadManager.Request(map_url);
        request.setTitle("Map Download");
        request.setDescription("Downloading map for nearby");

        request.setDestinationInExternalFilesDir(MainActivity.this, filePath.toString(), "kansas-latest_Beacon.osm.pbf" );

        downloadReference = downloadManager.enqueue(request);
    }

    public void onButtonClick(View view){
        Intent i = new Intent();
        i.setClass(this, DownloadActivity.class);
        startActivity(i);

    }

}
