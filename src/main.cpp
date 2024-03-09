#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char *ssid = "Wokwi-GUEST";
const char *password = "";

// Define NTP settings
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 0;

// Define UDP and NTP Client objects
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, gmtOffset_sec, daylightOffset_sec);
//_____________________________________________________________________________________________________________________________
void setup()
{
  Serial.begin(115200);
  //-----------------------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
  Serial.println(WiFi.localIP());
  //-----------------------------------------
  timeClient.begin();
  while (!timeClient.update())
  {
    timeClient.forceUpdate();
  }
  Serial.println("Time set from NTP.");
  //-----------------------------------------
}
//_____________________________________________________________________________________________________________________________
void loop()
{
  if (timeClient.update())
  {
    Serial.println("-------------------------------------------------------");

    Serial.println("getEpochTime: " + String(timeClient.getEpochTime()));
    Serial.println("getFormattedTime: " + String(timeClient.getFormattedTime()));

    Serial.print("Current getSeconds: " + String(timeClient.getSeconds()));
    Serial.print("\tgetMinutes: " + String(timeClient.getMinutes()));
    Serial.print("\tgetHours: " + String(timeClient.getHours()));
    Serial.println("\tgetDay: " + String(timeClient.getDay()));
  }
  delay(1000);
}
//__________________________________________________________________________________________________________