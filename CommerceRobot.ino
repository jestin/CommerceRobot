// Leg 1: 3,5
// Leg 2: 6,7
// Leg 3: 8,9
// Leg 4: 10,11

#include "Leg.h"
#include <Servo.h>

Leg leg1;
Leg leg2;
Leg leg3;
Leg leg4;

void setup(){
  leg1.attach(3, 5);
  leg2.attach(6, 7);
  leg3.attach(8, 9);
  leg4.attach(10, 11);
}

void loop(){
}
