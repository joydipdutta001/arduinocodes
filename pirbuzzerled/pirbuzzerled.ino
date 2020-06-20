
int sensor = 13;


void setup() {
  Serial.begin (9600);
  pinMode(sensor, INPUT);  
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(8,LOW);
      long state = digitalRead(sensor);
    if(state == HIGH) {
      digitalWrite (LED_BUILTIN, LOW);
      Serial.println("Motion detected!");
      digitalWrite(8,HIGH);
      delay(100);
    }
    else {
      digitalWrite (LED_BUILTIN, HIGH);
      Serial.println("Motion absent!");
      delay(100);
     digitalWrite(8,LOW);
      }
      delay(1000);
}
