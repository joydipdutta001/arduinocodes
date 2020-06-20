// choose pin for the LED
#include<ESP8266WiFi.h>
int inputPin = 13; //D7 choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status
const buzz = A0;
void setup() 
{ Serial.begin(115200); 
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
  pinMode(buzz,OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(LED_BUILTIN, LOW); // turn LED OFF   
      digitalWrite(buzz,LOW);
   } 
   else 
   { 
      digitalWrite(LED_BUILTIN, HIGH); // turn LED ON 
      digitalWrite(buzz,LOW);
   } 
}
