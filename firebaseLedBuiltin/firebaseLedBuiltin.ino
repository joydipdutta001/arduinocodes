#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"


int p1= 5;
int p2 = 4;
int p3 = 0;
int p4 = 2;

#define WIFI_SSID "joydip"
#define WIFI_PASSWORD "duta$130456"
#define FIREBASE_HOST "ledblinking-50dc6.firebaseio.com"
#define FIREBASE_AUTH "JxPOQLVklujpjZYVwR9c4CzJ4pBCcD6zX2NZzgzz"

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
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);

  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH);
  digitalWrite(p4, HIGH);
  
}

void loop() {


   if (Firebase.getInt(firebaseData,"/light1/value"))
    {
      int val = (firebaseData.intData());
      if (val == 1)
      {
        digitalWrite(p1,LOW);
        Serial.println("Led is On");
      }
      else{
        digitalWrite(p1, HIGH);
        Serial.println("Led is Off");
      }
  
      
    }
    if (Firebase.getInt(firebaseData,"/light2/value"))
    {
      int val2 = (firebaseData.intData());
      if (val2 == 1)
      {
        digitalWrite(p2,LOW);
        Serial.println("Led is On");
      }
      else{
        digitalWrite(p2, HIGH);
        Serial.println("Led is Off");
      }
  
      
    }
    if (Firebase.getInt(firebaseData,"/light3/value"))
    {
      int val3 = (firebaseData.intData());
      if (val3 == 1)
      {
        digitalWrite(p3,LOW);
        Serial.println("Led is On");
      }
      else{
        digitalWrite(p3, HIGH);
        Serial.println("Led is Off");
      }
  
      
    }if (Firebase.getInt(firebaseData,"/light4/value"))
    {
      int val4 = (firebaseData.intData());
      if (val4 == 1)
      {
        digitalWrite(p4,LOW);
        Serial.println("Led is On");
      }
      else{
        digitalWrite(p4, HIGH);
        Serial.println("Led is Off");
      }
  
      
    }

    delay(200);
  // put your main code here, to run repeatedly:

}
