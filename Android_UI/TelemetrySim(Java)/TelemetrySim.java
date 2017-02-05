package com.example.simm.telemetryapp;

import android.os.Handler;
import android.os.Message;
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


    private TextView textView;
    private boolean running = true;
    //byte buffer for incoming packets
    private byte[] buffer = new byte[2048];
    //set the listening port to receive packets
    private static int udp_port = 8583;
    private int packetLength;
    //defines a fixed threadpool otherwise threads continuously spawn.
    private ExecutorService workerPool = Executors.newFixedThreadPool(10);
    volatile boolean isRunning = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_telemetry_sim);


        textView = (TextView)findViewById(R.id.HeadingData);

    }

    @Override
    protected void onStart() {
        super.onStart();

        UdpServer();
    }

    @Override
    protected void onStop() {
        super.onStop();

        isRunning = false;
    }

    @Override
    protected void onResume() {
        super.onResume();

        isRunning = true;
    }

    //Runs the UDP server on another thread
    private void UdpServer() {
        Runnable serverRun = new Runnable() {
            @Override
            public void run() {

                //used for debugging
                String message1;

                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                try {
                    DatagramSocket dsocket = new DatagramSocket(udp_port);

                    while (isRunning) {

                        dsocket.receive(packet);

                        //int used for data processing in Processor()
                        packetLength = packet.getLength();

                        //assigns each task to a new thread from the threadpool
                        Processor();

                        //Used for debugging, uncomment to trace problems in the log.
                        message1 = new String(buffer, 0, packet.getLength());
                        Log.i("message1", message1);
                    }


                } catch (Throwable e) {
                    e.printStackTrace();
                }


            }



        };
        //run the server on another thread
        Thread thread = new Thread(serverRun);
        thread.start();
    }

    //data processing to split the packet into human readable information
    private void Processor() {
        Runnable processorRun = new Runnable() {
            @Override
            public void run() {

                //debugging string for monitor output
                String message2;
                byte[] messageByte;
                String newUiText = "";

                //copy the buffer into a new array
                messageByte = Arrays.copyOfRange(buffer,0,buffer.length);

                //split the length of information into 4 equal sections
                int element_cnt = packetLength / 4;

                //loop to split the byte array, process bytes to int and then to String for the TextView
                for (int i=0; i < element_cnt; i++) {
                    byte[] element = new byte[4];
                    System.arraycopy(messageByte, i * 4, element, 0, 4);
                    ByteBuffer wrapped = ByteBuffer.wrap(element);
                    int num = wrapped.getInt();
                    newUiText = newUiText + "Element " + i + ": " + Integer.toString(num) + "\n";

                }

                //TelemetrySim.runOnUiThread(textView.setText(newUiText));
                UiRunner(newUiText);

                //Debugging for monitor output
                message2 = new String(messageByte);
                Log.i("message2", message2);
                Log.i("Test", newUiText);

            }
        };

        //assign each task to a new thread from the threadpool
        workerPool.execute(processorRun);


    }

    //display the packet information on the UI thread
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
