#include<ESP8266WiFi.h>
int sensor = 13;  // Digital pin D7


#define WIFI_SSID "*********" //enter your wifi ssid
#define WIFI_PASSWORD "*****" // enter your wifi password

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


  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(LED_BUILTIN, OUTPUT);  // declare LED as output
}
void loop() {

  long state = digitalRead(sensor);
    if(state == HIGH) {
      digitalWrite (LED_BUILTIN, LOW);
      Serial.println("Motion detected!");
      delay(100);
    }
    else {
      digitalWrite (LED_BUILTIN, HIGH);
      Serial.println("Motion absent!");
      delay(100);
      }
      delay(1000);
}
