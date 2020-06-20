void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {

  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  delay(1000);
  
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  delay(1000);
  
  // put your main code here, to run repeatedly:

}
