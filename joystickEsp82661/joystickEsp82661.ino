#include<ESP8266WiFi.h>

#define Joystick_x 13
#define Joystick_y 15
#define onlyAnalogPin A0


#define WIFI_SSID "*********" //enter your wifi ssid
#define WIFI_PASSWORD "*****" // enter your wifi password


void setup() {
// put your setup code here, to run once:

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

pinMode(Joystick_x, OUTPUT);
pinMode(Joystick_y, OUTPUT);
digitalWrite(Joystick_x, LOW);
digitalWrite(Joystick_y, LOW);
}

void loop() {
int x,y;
x= joystickRead(Joystick_x);
y= joystickRead(Joystick_y);
Serial.print("X = ");
Serial.print(x, DEC);
Serial.print(" Y = ");
Serial.print(y, DEC);
Serial.println();
delay(20);

}

int joystickRead(int pin) {
digitalWrite(pin, HIGH);
delay(30);
int read = analogRead(onlyAnalogPin);
digitalWrite(pin, LOW);
return read;

}
