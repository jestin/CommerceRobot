#include "Cycle.h"

Cycle::Cycle() {
  m_Legs = NULL;
  m_Positions = NULL;
  m_nCurPos = 0;
  m_nPositionCount = 0;
  m_nLegCount = 0;
}

Cycle::~Cycle() {
  if(m_Legs != NULL) {
    delete m_Legs;
  }
  
  if(m_Positions != NULL) {
    free(m_Positions);
  }
}

void Cycle::setLegs(Leg** legs, unsigned int legCount) {
  m_nLegCount = legCount;
  
  if(m_Legs != NULL){
    delete m_Legs;
  }
  
  m_Legs = legs;
}

void Cycle::setPositions(int* positions, unsigned int positionCount) {
  m_nPositionCount = positionCount;
  
  m_Positions = (int**) malloc(sizeof(int) * positionCount * m_nLegCount);
  
  for(int pos = 0; pos < positionCount; pos++) {
    for(int servo = 0; servo < m_nLegCount * 2; servo++) {
      int servoPos = positions[(pos * (m_nLegCount * 2)) + servo];
      m_Positions[pos][servo] = servoPos;
      Serial.print(servoPos);
      Serial.print(", ");
    }
    Serial.println("");
  }
}

void Cycle::next() {
  Serial.print("Current Position: ");
  Serial.println(m_nCurPos);
  for(int leg = 0; leg < m_nLegCount; leg++) {
    Serial.print("Leg");
    Serial.println(leg);
    //Serial.print("(leg * 2) + 1 = ");
    //Serial.println((leg * 2) + 1);
    int x = m_Positions[m_nCurPos][leg * 2];
    int y = m_Positions[m_nCurPos][(leg * 2) + 1];
    Serial.print("(");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.println(")");
    m_Legs[leg]->setPosition(x, y);
  }
  
  m_nCurPos++;
  
  if(m_nCurPos >= m_nPositionCount) {
    m_nCurPos = 0;
  }
}
