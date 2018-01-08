package com.example.jkarr.hello_cmake;

import android.os.Environment;
import android.util.Log;

import java.io.File;
import java.util.Dictionary;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by jkarr on 1/2/2018.
 */

public class OSMMapDL2 {
    boolean ignoreDowloadRequests;
    boolean isDownloading;


    File  createOSMDir(){
        File direct = new File(Environment.getDataDirectory() + "/osm");

        if(!direct.exists()){
            Log.i("JDK", "Making New Directory");
            direct.mkdirs();
        }
        return direct;
    }//end createOSMdir

    /*
    boolean isDownloadingRegion(Dictionary region){
        return regionsDownloading.contains(region);
    }//end isDownloadingRegion
    */
    boolean isRegionOnDisk(Dictionary region){
        boolean bRes = true;
        String dir = Environment.getDataDirectory() + "/osm";


        return bRes;
    }

}//end class
