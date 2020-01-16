/*

Demonstration of the potentiometer working with serial port
and the servo controlled by the potentiometer

*/


// potentiometer value = 0

#include <Servo.h>

Servo servo;

int pot = 0;
int angle = 0;




// the setup routine runs once when you press reset:

void setup() {

  Serial.begin(9600);
  servo.attach(8);
  servo.write(angle);

}



// the loop routine runs over and over again forever:

void loop() {

  // 

  pot = analogRead(A4);
  angle = map(analogRead(A4), 0,1023,900,2100);
  servo.write(angle);

  Serial.println(pot);

  // wait for x milliseconds to see what happens



  delay(15);

}
