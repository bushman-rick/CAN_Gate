package com.example.simm.telemetrysim;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketAddress;

public class TelemetrySim extends AppCompatActivity {

    TextView textView;
    UdpState state;
    boolean stop;
    boolean busy_processing;
    boolean receive_paused;
    private static int listenPort = 8353;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_telemetry_sim);

        DatagramSocket dsocket = new DatagramSocket(listenPort);
        DatagramPacket packet = new DatagramPacket(lmessage, lmessage.length);

        state = new UdpState();
        state.dsocket = dsocket;
        state.packet = packet;




    }


    public class UdpState {
        DatagramSocket dsocket;
        DatagramPacket packet;
    }


}