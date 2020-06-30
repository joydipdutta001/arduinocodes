#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"


int pins[]= { 5,4,0,2 };
int countPins = 4;

#define WIFI_SSID ""/////////ENTER WIFI SSID,PASSWORD, FIREBASE  DATABASE LINK, DATABASE SECRET KEY////////////
#define WIFI_PASSWORD ""
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

FirebaseData firebaseData;

void setup() {

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
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

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);


for(int i = 0; i< countPins; i++){

  pinMode( pins[i],OUTPUT);
}


for(int j = 0; j< countPins; j++){

 digitalWrite(pins[j], HIGH);
 }

  
}

void loop() {


    for(int fpins = 0; fpins< countPins; fpins++){


      
        if (Firebase.getInt(firebaseData,"/light"+String(int(fpins+1))+"/value"))
        {
           int val = (firebaseData.intData());
           if (val == 1)
          {
              digitalWrite(pins[fpins],LOW);
              Serial.println("Led is On");
          }
        else
        {
              digitalWrite(pins[fpins], HIGH);
              Serial.println("Led is Off");
        }
  
      }
      
    }


    delay(200);
  // put your main code here, to run repeatedly:

}
