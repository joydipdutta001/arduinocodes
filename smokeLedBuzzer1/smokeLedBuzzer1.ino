#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"

////////////////////////////////////////////ENTER DETAILS HERE//////////////////////////////////////
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "password"
#define FIREBASE_HOST "firebaseURL.com"
#define FIREBASE_AUTH "database secret key"
////////////////////////////////////////////////////////////////////////////////////////////////////


FirebaseData firebaseData;

int smp = A0;
int ledPin = 5;
int buzzPin = 4;


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

  pinMode(smp,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);

}

void loop() {

  float g = analogRead(smp);
  float value = (g/1023*100);

  Serial.println("Smoke sensor value is:");
  Serial.println(value);
  
   if (Firebase.getInt(firebaseData,"/value"))
    {
      int val = (firebaseData.intData());
      if (val == 1)
      {
        digitalWrite(ledPin,LOW);
        Serial.println("Led is On");
      }
      else{
        digitalWrite(ledPin, HIGH);
        Serial.println("Led is Off");
      }
  
      
    }

     if (Firebase.pushFloat(firebaseData,"/smoke",value))
    {
      Serial.print("Passed->"); Serial.print(value);
  
      
    }

  if (value >= 16){
    digitalWrite(buzzPin,HIGH);
    Serial.println("Alert Smoke level reached above!!!!");
  }else{
    digitalWrite(buzzPin,LOW);
    Serial.println("Safe");
  }

  delay(1000);
  // put your main code here, to run repeatedly:

}
