// Leg 1: 3,5
// Leg 2: 6,7
// Leg 3: 8,9
// Leg 4: 10,11

#include "Leg.h"
#include "Angles.h"
#include <Servo.h>

Leg leg1;
Leg leg2;
Leg leg3;
Leg leg4;

void setup(){
  int leg1XAngles[5] = LEG1_X_ANGLES;
  int leg1YAngles[3] = LEG1_Y_ANGLES;
  leg1.setAngles(leg1XAngles, 5, leg1YAngles, 3);

  int leg2XAngles[5] = LEG2_X_ANGLES;
  int leg2YAngles[3] = LEG2_Y_ANGLES;
  leg2.setAngles(leg2XAngles, 5, leg2YAngles, 3);

  int leg3XAngles[5] = LEG3_X_ANGLES;
  int leg3YAngles[3] = LEG3_Y_ANGLES;
  leg3.setAngles(leg3XAngles, 5, leg3YAngles, 3);

  int leg4XAngles[5] = LEG4_X_ANGLES;
  int leg4YAngles[3] = LEG4_Y_ANGLES;
  leg4.setAngles(leg4XAngles, 5, leg4YAngles, 3);
  
  leg1.attach(3, 5);
  leg2.attach(6, 7);
  leg3.attach(8, 9);
  leg4.attach(10, 11);
}

void loop(){
  for(int x = 0; x < 5; x ++){
    for(int y = 0; y < 3; y++){
      leg1.setPosition(x, y);
      leg2.setPosition(x, y);
      leg3.setPosition(x, y);
      leg4.setPosition(x, y);
      delay(500);
    }
  }
}
