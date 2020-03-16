
/*
2/23/20
Module 4 Hoist Code
Aspects needed to code:
OLED?
MPU6050??

Load Cell
DAT on 5 
CLK on 6
JOYSTICK - A0
POT - A1
Servo1 - 2
Button - 4
Servo2 - 3
*/


#include <Servo.h>
#include <HX711.h>
#define DOUT 5
#define CLK 6

Servo servo1; // pulley one
Servo servo2; //cut one

HX711 scale;

int xval = 0; //joystick
int angle1 = 0; // pulley one
int pot = 1023; // controls pulley servo speed
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
  scale.begin(DOUT, CLK);
  //this line MAY pose an issue if it does we improvisin
  //scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare();

}

void loop() {
  xval = analogRead(A0);
  pot = analogRead(A1);
  angle1 = map(analogRead(A0), 0,1023,900,2100);
  servo1.write(angle1);
  buttonState = digitalRead(buttonPin);
  //servo1.writeMicroseconds(pot);
  

// I want to change this to servo 2!
  if (buttonState == HIGH) {
    angle2 = 180;
    servo2.write(angle2);
  } else {
    angle2 = 0;
    servo2.write(angle2);
  }
  // this seems important scale.get_units()
  if (scale.get_units() >= 3){
    angle2 = 180;
    servo2.write(angle2);
  }
  delay(15);
}
