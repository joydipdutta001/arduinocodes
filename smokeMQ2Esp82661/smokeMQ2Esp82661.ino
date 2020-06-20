#include<ESP8266WiFi.h>

int smp = A0;

void setup() {

Serial.begin(115200); 
    WiFi.begin("joydip", "duta$130456");
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

  pinMode(smp,INPUT);

}

void loop() {

  float g = analogRead(smp);
  float value = (g/1023*100);

  Serial.println("Smoke sensor value is:");
  Serial.println(value);

  delay(1000);
  // put your main code here, to run repeatedly:

}
