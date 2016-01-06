// Leg 1: 3,5
// Leg 2: 6,7
// Leg 3: 8,9
// Leg 4: 10,11

#include "Leg.h"
#include "Angles.h"
#include "Cycle.h"
#include "Cycles.h"
#include <Servo.h>

Leg leg1;
Leg leg2;
Leg leg3;
Leg leg4;

Cycle walkCycle;

int pos = 0;

void setup(){
  // begin serial for debugging purposes
  Serial.begin(9600);
  
  // Assign positions to leg 1
  int leg1XAngles[5] = LEG1_X_ANGLES;
  int leg1YAngles[3] = LEG1_Y_ANGLES;
  leg1.setAngles(leg1XAngles, 5, leg1YAngles, 3);

  // Assign positions to leg 2
  int leg2XAngles[5] = LEG2_X_ANGLES;
  int leg2YAngles[3] = LEG2_Y_ANGLES;
  leg2.setAngles(leg2XAngles, 5, leg2YAngles, 3);

  // Assign positions to leg 3
  int leg3XAngles[5] = LEG3_X_ANGLES;
  int leg3YAngles[3] = LEG3_Y_ANGLES;
  leg3.setAngles(leg3XAngles, 5, leg3YAngles, 3);

  // Assign positions to leg 4
  int leg4XAngles[5] = LEG4_X_ANGLES;
  int leg4YAngles[3] = LEG4_Y_ANGLES;
  leg4.setAngles(leg4XAngles, 5, leg4YAngles, 3);
  
  // Attach the legs to the control pins the legs are plugged into
  leg1.attach(3, 5);
  leg2.attach(6, 7);
  leg3.attach(8, 9);
  leg4.attach(10, 11);
  
  // Tell our walk cycle which leg is which
  Leg legs[4] = {leg1, leg2, leg3, leg4};
  walkCycle.setLegs(legs, 4);
  
  // Set the full-body positions of the walk cycle to our cycle variable
  int positions[WALK_POSITIONS * 2/*number of servos per leg*/ * 4/*number of legs*/] = WALK_CYCLE;
  walkCycle.setPositions(positions, WALK_POSITIONS);
}

void loop(){
  // tell the cycle to move to the next full-body position
  walkCycle.next();
  
  // wait a second for the robot to get to the position (reduce this value to make the robot move faster
  delay(1000);
  
  /*if(pos % 2 == 0){
    leg1.setPosition(2, 2);
    leg2.setPosition(2, 2);
    leg3.setPosition(2, 2);
    leg4.setPosition(2, 2);
  } else {
    leg1.setPosition(2, 0);
    leg2.setPosition(2, 0);
    leg3.setPosition(2, 0);
    leg4.setPosition(2, 0);
  }
  delay(1000);
  pos++;*/
}
