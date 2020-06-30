#include<ESP8266WiFi.h>
const int s0 = 2; //D4
  const int s1 = 14; //D5
  const int s2 = 12; //D6
  const int s3 = 13; //D7
  const int out = 15;  //D8
  int red = 0; 
 int green = 0;
 int blue = 0;  
 void setup() 
  {    
Serial.begin(115200); 
    WiFi.begin("ssid", "password");//enter your router ssid and password(you can do the same with your mobile hotspot)
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
  pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);
     digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
  }   
void loop()
 {   
 color(); 
  Serial.print("R Intensity:");
    Serial.print(red, DEC);
   Serial.print(" G Intensity: "); 
   Serial.print(green, DEC); 
   Serial.print(" B Intensity : ");
    Serial.print(blue, DEC);  
    if (red < blue && red < green && red < 20)
  {     Serial.println(" - (Red Color)");     }  
   else if (blue < red && blue < green)  
   {     Serial.println(" - (Blue Color)");     }  
   else if (green < red && green < blue) 
   {     Serial.println(" - (Green Color)");     }   
 else{  Serial.println();    } 
 delay(300);     
} 
  void color() 
 {      digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);    
//count OUT, pRed, RED
    red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE   
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s2, HIGH);    //count OUT, pGreen, GREEN   
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 }
