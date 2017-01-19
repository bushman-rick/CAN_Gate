package com.example.simm.telemetrysim;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Telemetry extends AppCompatActivity {

    private TextView headOut;
    private String testString = "TEST!";
    private UdpServer myUdpServer = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_telemetry);

        headOut = (TextView) findViewById(R.id.headOut);
        //headOut.setText(lastMessage);
    }

    protected void onResume() {
        myUdpServer = new UdpServer();
        myUdpServer.start();
        super.onResume();
    }

    protected void onPause() {
        myUdpServer.kill();
    }

    private class UdpServer extends Thread {

        private boolean running = true;
        private String lastMessage = "";
        private char[] headingArr;
        private char[] accelArr;
        private char[] trackArr;
        private char[] coordXArr;
        private char[] coordYArr;
        private String testT = "";
        private String conv = "";
        private float track;
        //test strings
        private StringBuilder hex = new StringBuilder();
        private String hexC;



        public void run() {
            int udp_port = 8583;
            String message;
            char[] testA;

            byte[] lmessage = new byte[2048];

            DatagramPacket packet = new DatagramPacket(lmessage, lmessage.length);

            try {
                DatagramSocket dsocket = new DatagramSocket(udp_port);

                while (running) {
                    dsocket.receive(packet);
                    message = new String(lmessage, 0, packet.getLength());
                    lastMessage = message;
                    // take input and turn it into a char array
                    testA = message.toCharArray();
                    headingArr = Arrays.copyOfRange(testA,0,4);
                    accelArr = Arrays.copyOfRange(testA,4,8);
                    // ...
                    // copy the relevant section of the char array into the track array
                    trackArr = Arrays.copyOfRange(testA,8,12);
                    coordXArr = Arrays.copyOfRange(testA,12,16);
                    coordYArr = Arrays.copyOfRange(testA,16,20);

                    //testT = String.valueOf(trackArr);

                    // This is where I need some help...
                    // track is a float declared earlier and it is possible to cast char into a
                    // float without explicitly declaring it cus a char requires more bytes.
                    // This will display a number that has come from hex but I need the whole hex
                    // in the array in order to display the correct number.
                    track = trackArr[1];
                    //track = Float.parseFloat(testT);


                        for (int i=0; i<headingArr.length; i++) {
                            //track = trackArr[i];

                            hex.append(String.format("%04x", (int) headingArr[i]));
                            hex.append(String.format("%04x", (int) accelArr[i]));
                            hex.append(String.format("%04x", (int) trackArr[i]));
                            hex.append(String.format("%04x", (int) coordXArr[i]));
                            hex.append(String.format("%04x", (int) coordYArr[i]));
                            hexC = hex.toString();


                        }

                    runOnUiThread(updateTextMessage);
                    //Log.i("UDP packet received", Arrays.toString(testT));
                    //Log.i("UDP packet received", f);
                    Log.i("UDP packet received", Float.toString(track));
                }
            } catch (Throwable e) {
                e.printStackTrace();
            }

        }

        public void kill() {
            running = false;
        }

        public String getLastMessage() {
            return lastMessage;
        }

        public float getTheDigits() {
            return track;
        }

    }

    private Runnable updateTextMessage = new Runnable() {
        public void run() {
            if (myUdpServer == null) return;
            headOut.setText(myUdpServer.getLastMessage());
        }
    };
}