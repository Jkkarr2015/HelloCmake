package com.example.jkarr.hello_cmake;

import android.os.AsyncTask;
import android.renderscript.Sampler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.SwitchCompat;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Switch;

import org.json.JSONArray;
import org.json.JSONObject;

import java.net.URL;
import java.util.Scanner;

import static android.graphics.Color.GREEN;

public class DownloadActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_download);
        JSONArray region = new JSONArray();
        try{
            String s = "http://maps.aphtech.org/osm/toc_osm.json";

            region = new Loader().execute(s).get();
        } catch (Exception e) {
            e.printStackTrace();
        }
        LinearLayout linearLayout = findViewById(R.id.myLayout);

        for (int i=0; i < region.length(); i++ ) {
            final SwitchCompat slide = new SwitchCompat(this);
            try {
                slide.setText(region.getJSONObject(i).getString("name"));
                slide.setTextSize(20);
                slide.setTag(region.getJSONObject(i).getString("name"));
                slide.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Log.i("JDK", "Click " + slide.getText() + " " + slide.getTag());
                    }
                });


                linearLayout.addView(slide);

            }catch(Exception e){

            }
        }



        //this.setContentView(linearLayout, new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));
    }

    private class Loader extends AsyncTask<String,Void,JSONArray> {

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
