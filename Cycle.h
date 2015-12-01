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
    
    void setLegs(Leg* legs, unsigned int legCount);
    void setPositions(int positions[], unsigned int positionCount);
    void next();
};

#endif
