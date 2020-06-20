#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"

#define WIFI_SSID "joydip"
#define WIFI_PASSWORD "duta$130456"
#define FIREBASE_HOST "ledblinking-50dc6.firebaseio.com"
#define FIREBASE_AUTH "JxPOQLVklujpjZYVwR9c4CzJ4pBCcD6zX2NZzgzz"

int ledPin=5;

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
  
  pinMode(ledPin, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {

  if (Firebase.getInt(firebaseData, "/value")){
    int val = (firebaseData.intData());
if (val == 1){
  digitalWrite(ledPin, HIGH);
  Serial.println("Led is ON");
}else{
  digitalWrite(ledPin,LOW);
  Serial.println("Led is OFF");
}
    
  }

  delay(100);
  // put your main code here, to run repeatedly:

}
