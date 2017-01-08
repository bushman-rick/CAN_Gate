package com.example.simm.telemetrysim;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

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


        public void run() {
            int udp_port = 8583;
            String message;
            byte[] lmessage = new byte[2048];

            DatagramPacket packet = new DatagramPacket(lmessage, lmessage.length);

            try {
                DatagramSocket dsocket = new DatagramSocket(udp_port);

                while (running) {
                    dsocket.receive(packet);
                    message = new String(lmessage, 0, packet.getLength());
                    lastMessage = message;
                    runOnUiThread(updateTextMessage);
                    Log.i("UDP packet received", message);
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

    }

    private Runnable updateTextMessage = new Runnable() {
        public void run() {
            if (myUdpServer == null) return;
            headOut.setText(myUdpServer.getLastMessage());
        }
    };
}