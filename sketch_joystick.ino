#define SERVOXPIN 6
#define SERVOYPIN 5

#define JOYSTICKVX A0
#define JOYSTICKVY A1

#define JOYSTICKSW 7

#include <Servo.h>

Servo ServoX; // x axis servo
Servo ServoY; // y axis servo



int xOrientation; // orientation of the ServoX
int yOrientation; // orientation of the ServoY

int xRead; // the readen value from vx of the joystick
int yRead; // the readen value from vy of the joystick

void setup() {
  // put your setup code here, to run once:
  ServoX.attach(SERVOXPIN);
  ServoY.attach(SERVOYPIN);

  pinMode(JOYSTICKSW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read analog signals from vx and vy analog pins of the joystick module.
  xRead = analogRead(JOYSTICKVX);
  yRead = analogRead(JOYSTICKVY);

  // the readen signal is between 0 - 1023 Servo can have orientation of 0 - 180. So map the intervals.
  xOrientation = map(xRead, 0, 1023, 0, 180);
  yOrientation = map(yRead, 0, 1023, 0, 180);

  // write the calculated orientations to servos
  ServoX.write(xOrientation);
  ServoY.write(yOrientation);
}
