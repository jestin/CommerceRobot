// This class defines a movement cycle that keeps track of
// all the robots legs, and which position in the cycle the
// robot is at.

#ifndef CYCLE_H
#define CYCLE_H

#include "Leg.h"
#include <Arduino.h>

class Cycle {
  private:
    unsigned int m_nLegCount;
    Leg* m_Legs;
    
    int m_nCurPos;
    unsigned int m_nPositionCount;
    int* m_Positions;
    
  public:
    Cycle();
    ~Cycle();
    
    // Tells the cycle which legs are which
    void setLegs(Leg* legs, unsigned int legCount);
    
    // Defines the different full-body positions that this cycle includes
    void setPositions(int positions[], unsigned int positionCount);
    
    // Moves the robot to the next full-body position
    void next();
};

#endif
