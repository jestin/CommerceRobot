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
    delete m_Positions;
  }
}

void Cycle::setLegs(Leg* legs, unsigned int legCount) {
  m_nLegCount = legCount;
  
  if(m_Legs != NULL){
    delete m_Legs;
  }
  
  m_Legs = new Leg[4];
  
  for(int i = 0; i < legCount; i++){
    m_Legs[i] = legs[i];
  }
}

void Cycle::setPositions(int positions[], unsigned int positionCount) {
  if(m_Positions != NULL) {
    Serial.print("Deleting old memory...");
    delete m_Positions;
    Serial.println("done");
  }
  
  m_nPositionCount = positionCount;
  Serial.print("positionCount: ");
  Serial.println(positionCount);
  Serial.print("m_nLegCount: ");
  Serial.println(m_nLegCount);
  
  Serial.print("Allocating position memory...");
  m_Positions = new int[positionCount * m_nLegCount * 2];
  Serial.println("done");
  
  Serial.print("Setting positions in cycle...");
  for(int i = 0; i < positionCount * m_nLegCount * 2; i++) {
    m_Positions[i] = positions[i];
  }
  
  Serial.println("done");
  
  for(int pos = 0; pos < positionCount; pos++) {
    for(int servo = 0; servo < m_nLegCount * 2; servo++) {
      Serial.print(m_Positions[(pos * m_nLegCount * 2) + servo]);
      Serial.print(", ");
    }
    Serial.println("");
  }
  Serial.flush();
}

void Cycle::next() {
  Serial.print("Current Position: ");
  Serial.println(m_nCurPos);
  for(int leg = 0; leg < m_nLegCount; leg++) {
    //Serial.print("Leg");
    //Serial.println(leg);
    //Serial.print("x-servo: ");
    //Serial.println(leg * 2);
    //Serial.print("y-servo: ");
    //Serial.println((leg * 2) + 1);
    int x = m_Positions[m_nCurPos * (m_nLegCount * 2) + (leg * 2)];
    int y = m_Positions[m_nCurPos * (m_nLegCount * 2) + (leg * 2) + 1];
    //Serial.print("(");
    //Serial.print(x);
    //Serial.print(", ");
    //Serial.print(y);
    //Serial.println(")");
    //Serial.flush();
    m_Legs[leg].setPosition(x, y);
  }
  
  m_nCurPos++;
  m_nCurPos = m_nCurPos % m_nPositionCount;
}
