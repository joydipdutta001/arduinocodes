#include <Servo.h>
#define trigPin 13
#define echoPin 12

Servo msv;
 
int pos = 0;  


void setup() {
  Serial.begin (9600);
  msv.attach(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
 
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance <=7){            //Condition for servo is below 7 cm
      msv.write(0);
      delay(500);
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    msv.write(pos);                  // tell servo 2 to go to position in variable 'pos'
    delay(10);                       // waits 5ms for the servo to reach the position
  }
                            // waits 5ms for the servo to reach the position
  }
     
  }
        
      
  
  delay(500);
}
