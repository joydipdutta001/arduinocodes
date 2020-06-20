int IR1 = 13;     /* digital pin input for ir sensor  */
int IR2 = 15;
int IR1_out = HIGH; /* Avoiding initial false detections.    */
int IR2_out = HIGH; /* Avoiding initial false detections.    */
int counter = 0;
int i = 0;
 
#define MAX_NUMB 9

void increaseAndDisplay() {
  counter++;
  if(counter > MAX_NUMB) {
    counter = 1;
  }
  Serial.println("Increased");
  Serial.println(counter);
}

void decreaseAndDisplay() {
  if(counter) {
    counter--;

  Serial.println("decreased");
  Serial.println(counter);
  }
}
void setup() {
  Serial.begin (9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
 
}
void loop() {
  IR1_out = digitalRead(IR1);
  IR2_out = digitalRead(IR2);
  if(IR1_out == LOW) {
    increaseAndDisplay();
    delay(500);
  }
  if(IR2_out == LOW) {
    decreaseAndDisplay();
    delay(500);
  } 
  delay(100);
}
 
