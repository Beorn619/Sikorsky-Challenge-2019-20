/*
2/23/20
Module 4 Hoist Code
Aspects needed to code:
OLED?
MPU6050??
Load Cell*
****Load cell still needs to be programmed for
Load cell also not present but WOULD be DAT on 5 
  and CLK on 6
POT/JOYSTICK - A0
Servo1 - 2
Button - 4
Servo2 - 3
*/

#include <Servo.h>

Servo servo1; // pulley one
Servo servo2; //cut one

int xval = 0; //joystick
int angle1 = 0; // pulley one
const int buttonPin = 4;
int buttonState = 0;
int angle2 = 0; // cut one

void setup() {
  Serial.begin(100);
  servo1.attach(2);
  servo1.write(angle1);
  servo2.attach(3);
  servo2.write(angle2);
  pinMode(buttonPin, INPUT);

}

void loop() {
  xval = analogRead(A0);
  angle1 = map(analogRead(A0), 0,1023,900,2100);
  servo1.write(angle1);
  buttonState = digitalRead(buttonPin);

// I want to change this to servo 2!
  if (buttonState == HIGH) {
    angle2 = 180;
    servo2.write(angle2);
  } else {
    angle2 = 0;
    servo2.write(angle2);
  }
  delay(15);
}
