/* Sourced from:
https://www.reddit.com/r/androiddev/comments/2tm4lj/udp_sending_and_receiving_androidjava/
http://stackoverflow.com/questions/14493241/android-asynctask-sending-udp-packet

 */

package com.example.simm.udp_test;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.view.ViewPropertyAnimatorCompatSet;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.net.InetAddress;

public class MainActivity extends AppCompatActivity {

    EditText mEditIP;
    EditText mEditPort;
    // made public so it can be read from the payload class
    public String usrIP = "";
    public int usrPort = 0;
    private UDP_Server myUDP_Server = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Point to the text fields
        mEditIP = (EditText)findViewById(R.id.ipAddr);
        mEditPort = (EditText)findViewById(R.id.port);

    }

    protected void onResume() {
        myUDP_Server = new UDP_Server();
        myUDP_Server.start();
        super.onResume();
    }

    protected void onPause() {
        myUDP_Server.kill();
    }

    // SendUDP will identify the send button and convert user input into the required type
    public void sendUDP (View view) {
        Button sendClick = (Button) findViewById(R.id.send);
        sendClick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Convert input in text fields into a String and int
                usrIP = mEditIP.getText().toString();
                usrPort = Integer.parseInt(mEditPort.getText().toString());
                //Call the payload class and execute
                new Payload().execute();

            }
        });
    }

    //Payload class to handle all networking on a separate thread from the main UI thread.
    public class Payload extends AsyncTask<String, Integer, Boolean>{

        // doInBackground is required for the AsyncTask to function.
        @Override
        protected Boolean doInBackground(String... arg0) {

            try {


                byte[] message = "Hello".getBytes();

                InetAddress address = InetAddress.getByName(usrIP);

                // fill the contents of the UDP
                DatagramPacket packet = new DatagramPacket(message, message.length, address, usrPort);

                // initialize socket for sending
                DatagramSocket dsocket = new DatagramSocket();
                dsocket.send(packet);
                // close off socket
                dsocket.close();
            // catch errors and display to console
            } catch (Exception e) {
                System.err.println(e);
            }
            return null;
        }
    }
}



    /* This was code used before I found out I needed to run networking stuff on a separate thread.

     void payload() {

        usrIP = mEditIP.getText().toString();
        usrPort = Integer.parseInt(mEditPort.getText().toString());




        if (usrIP.equals("")) {
            Toast.makeText(MainActivity.this, "You did not enter an IP", Toast.LENGTH_SHORT).show();
            return;
        }



        else {
            try {

                byte[] message = "Hello".getBytes();

                InetAddress address = InetAddress.getByName(usrIP);

                DatagramPacket packet = new DatagramPacket(message, message.length, address, usrPort);

                DatagramSocket dsocket = new DatagramSocket();
                dsocket.send(packet);
                dsocket.close();
                Toast.makeText(MainActivity.this, "Sent", Toast.LENGTH_SHORT).show();
                return;


            } catch (Exception e) {
                System.err.println(e);
            }
        }

    } */


