package com.example.simm.telemetryapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TelemetrySim extends AppCompatActivity {


    TextView textView;
    //private UdpServer myUdpServer = null;
    private boolean running = true;
    private byte[] buffer = new byte[2048];
    //private byte[] messageByte = new byte[200];
    private String test = "";
    private static int udp_port = 8583;
    private int packetLength;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_telemetry_sim);

    }

    @Override
    protected void onStart() {
        super.onStart();

        UdpServer();
    }


    private void UdpServer() {
        Runnable serverRun = new Runnable() {
            @Override
            public void run() {

                String message;
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                try {
                    DatagramSocket dsocket = new DatagramSocket(udp_port);

                    while (running) {
                        dsocket.receive(packet);
                        packetLength = packet.getLength();

                        Processor();
                        /*
                        message = new String(buffer, 0, packet.getLength());
                        //lastMessage = message;
                        Log.i("UDP packet received", message);
                        */
                    }
                } catch (Throwable e) {
                    e.printStackTrace();
                }

            }
        };
        Thread thread = new Thread(serverRun);
        thread.start();
    }

    private void Processor() {
        Runnable processorRun = new Runnable() {
            @Override
            public void run() {
                String message;
                //process the byte array
                //int arrLength = packet.getLength()
                byte[] messageByte;


                //int arrLength = buffer.length;
                messageByte = Arrays.copyOfRange(buffer,0,buffer.length);
                //byte[] currentData = Arrays.copyOf(buffer, packetLength);

                int element_cnt = packetLength / 4;

                //ByteBuffer wrapped = ByteBuffer.wrap(messageByte);
                //int num = wrapped.getInt();

                String newUiText = "";


                for (int i=0; i < element_cnt; i++) {
                    byte[] element = new byte[4];
                    System.arraycopy(messageByte, i * 4, element, 0, 4);
                    ByteBuffer wrapped = ByteBuffer.wrap(element);
                    int num = wrapped.getInt();
                    newUiText = newUiText + "Element " + i + ": " + Integer.toString(num) + "\n";

                }

                //TelemetrySim.runOnUiThread(textView.setText(newUiText));
                //UiRunner(newUiText);





                message = new String(messageByte);

                Log.i("UDP packet received", message);
                //Log.i("num ", Integer.toString(num));
                Log.i("Test", newUiText);



            }
        };

        ExecutorService executor = Executors.newCachedThreadPool();
        executor.submit(processorRun);

    }

    public void UiRunner(String msg) {
        final String str = msg;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                textView.setText(str);
            }
        });
    }








}