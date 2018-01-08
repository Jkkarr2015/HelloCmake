package com.example.jkarr.hello_cmake;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Environment;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.File;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created by jkarr on 1/5/2018.
 */

public class TocLoader {

    public static final String OSMurlbase = "http://maps.aphtech.org/osm/";
    public static final String osmDirectory = Environment.getDataDirectory() + "/osm";






    private class loader extends AsyncTask<String,Void,JSONArray> {

        private Exception exception;

        protected JSONArray doInBackground(String... s){


            try {
                URL url = new URL(s[0]);

                //Converts Json file from URL to a string
                Scanner scan = new Scanner(url.openStream());
                String str = new String();
                while (scan.hasNext())
                    str += scan.nextLine();
                scan.close();

                JSONObject obj = new JSONObject(str);

                JSONArray continent = obj.getJSONArray("continents");

                JSONObject northAmerica = continent.getJSONObject(0);

                JSONArray countries = northAmerica.getJSONArray("countries");

                JSONObject us = countries.getJSONObject(0);

                JSONArray region = us.getJSONArray("regions");

                return region;

            }
            catch(Exception e){
                this.exception = e;
            }

            JSONArray blank = new JSONArray();
            return blank;



        }

        protected void onPostExecute(JSONArray result) {
            //do stuff
            myMethod(result);
        }

        private JSONArray myMethod(JSONArray myValue) {
            //handle value
            return myValue ;
        }



    }
}
