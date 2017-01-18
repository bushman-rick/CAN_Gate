using System;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

namespace TelemetrySim
{
    [Activity(Label = "TelemetryUI")]
    public class TelemetryActivity : Activity
    {
        TextView textView;
        UdpState state;
        bool stop;
        bool busy_processing;
        bool receive_paused;
        private const int listenPort = 8353;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.Telemetry_UI);

            IPEndPoint end_point = new IPEndPoint(IPAddress.Any, listenPort);
            UdpClient udp_listener = new UdpClient(end_point);

            state = new UdpState();
            state.end_point = end_point;
            state.udp_listener = udp_listener;

            ThreadPool.QueueUserWorkItem(o => StartUDPlistener());
            textView = FindViewById<TextView>(Resource.Id.HeadingData);
        }

        private void StartUDPlistener()
        {
            state.udp_listener = new UdpClient(state.end_point);
            Receive();
            RunOnUiThread(() => textView.Text = "Listener launched");
        }

        private void StopUDPlistener()
        {
            stop = true;
        }

        private void Receive()
        {
            state.udp_listener.BeginReceive(new AsyncCallback(ProcessTelemetryData), null);
        }

        private void ProcessTelemetryData(IAsyncResult result)
        {
            state.end_point = new IPEndPoint(IPAddress.Any, listenPort);
            byte[] data = state.udp_listener.EndReceive(result, ref state.end_point);
            if (!stop && !busy_processing)
            {
                Receive();
            }
            else
            {
                receive_paused = true;
            }
            ProcessData(data);
        }

        private void ProcessData(byte[] data)
        {
            busy_processing = true;
            byte[] current_data = (byte[])data.Clone();

            int element_cnt = data.Length / 4;

            string new_UI_text = "";

            for (int i = 0; i < element_cnt; i++)
            {
                byte[] element = new byte[4];
                Array.Copy(current_data, (i * 4), element, 0, 4);
                new_UI_text = new_UI_text + "Element " + i + " : " + BitConverter.ToUInt32(element, 0).ToString() + System.Environment.NewLine; 
            }

            RunOnUiThread(() => textView.Text = new_UI_text);

            busy_processing = false;
            if (receive_paused)
            {
                receive_paused = false;
                Receive();
            }
        }
    }

    public class UdpState
    {
        public IPEndPoint end_point;
        public UdpClient udp_listener;
    }
}

