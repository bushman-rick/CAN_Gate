/*
http://stackoverflow.com/questions/16752205/simple-udp-server-for-android-and-get-multi-messages
 */

package com.example.simm.udp_test;

import android.os.AsyncTask;
import android.os.StrictMode;
import android.util.Log;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 * Created by simm on 19/12/2016.
 */

public class UDP_Server extends Thread {

    private boolean running = true;
    private String lastMessage = "";
    private int udp_port = 8583;

        public void run() {
            String message;
            byte[] lmessage = new byte[2048];
            DatagramPacket packet = new DatagramPacket(lmessage, lmessage.length);

            try {
                DatagramSocket dsocket = new DatagramSocket(udp_port);

                while(running) {
                    dsocket.receive(packet);
                    message = new String(lmessage, 0, packet.getLength());
                    lastMessage = message;
                    Log.i("UDP packet received", message);
                }
            } catch (Throwable e) {
                e.printStackTrace();
            }

           /* if (dsocket != null) {
                dsocket.close();
            } */
        }

        public void kill() {
            running = false;
        }

        /* Uncomment if you want the message into a string, could display in Toast dialog
        public String getLastMessage() {
            return lastMessage;
        }
        */
    }





    /*public void run() {
        String message;
        byte[] lMessage = new byte[2048];
        DatagramPacket packet = new DatagramPacket(lMessage, lMessage.length);

        try {
            DatagramSocket dsocket = new DatagramSocket(udp_port);

            while (running) {
                dsocket.receive(packet);
            }


        } catch {

        }



    } */


