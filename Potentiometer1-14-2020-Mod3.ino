/*
Demonstration of the potentiometer working with serial port
*/

// potentiometer value = 0
int pot = 0;


// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // 
  pot = analogRead(A4);
  Serial.println(pot);
  // wait for x milliseconds to see what happens

  delay(1000);
}
