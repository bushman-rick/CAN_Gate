using System;
using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;

namespace TelemetrySim
{
    // main activity, displays splash
    [Activity(Theme = "@style/Theme.NoTitle", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivity : Activity
    {
        protected override void OnCreate(Bundle bundle)
        {
            RequestWindowFeature(WindowFeatures.NoTitle);
            base.OnCreate(bundle);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            // Get our UI controls from the loaded layout:
            ImageButton launchButton = FindViewById<ImageButton>(Resource.Id.LaunchButton);


            launchButton.Click += (object sender, EventArgs e) =>
            {
                Intent intent = new Intent(this, typeof(TelemetryActivity));
                StartActivity(intent);
            };

        }
    }
}


