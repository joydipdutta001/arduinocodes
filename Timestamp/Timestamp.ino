#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include "time.h";
////////////////////////////////////////////////////////////ENTER DETAILS////////////////////////////////////////
#define FIREBASE_HOST "********************"
#define FIREBASE_AUTH "*********************"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Define Firebase Data object
FirebaseData firebaseData;

void setup()
{

  Serial.begin(115200);
  Serial.println();
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  configTime(0,0, "pool.ntp.org", "time.nist.gov");
 const char*  timeZone1 = "IST-5:30";
// String timeZone2 ="GMT0BST,M3.5.0/01,M10.5.0/02";
  setenv("TZ", timeZone1, 1);
  
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}



String get_time(){

  time_t now;
  time(&now);
  char time_output[30];
  strftime(time_output, 30, "%a %d-%m-%y %T", localtime(&now));
  return String(time_output);
  
    Serial.println("------------------------------------");


}


void loop()
{
    Serial.println("Set Timestamp test...");
  Serial.println(get_time());
  delay(1000);

  
  String path = "/Test";

  if (Firebase.setTimestamp(firebaseData, path + "/Set/Timestamp"))
  {
    Serial.println("PASSED");

    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
}
