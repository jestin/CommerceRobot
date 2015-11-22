#include "Leg.h"

Leg::Leg(){
  m_curX = 0;
  m_curY = 0;
  m_xAngles = NULL;
  m_yAngles = NULL;
}

Leg::~Leg(){
  if(m_xAngles != NULL){
    delete m_xAngles;
  }
  
  if(m_yAngles != NULL){
    delete m_yAngles;
  }
}

void Leg::setAngles(int _xAngles[], int _xSize, int _yAngles[], int _ySize){
  
  if(m_xAngles != NULL){
    delete m_xAngles;
  }
  
  if(m_yAngles != NULL){
    delete m_yAngles;
  }
  
  m_xAngles = new int[_xSize];
  for(int i = 0; i < _xSize; i++){
    m_xAngles[i] = _xAngles[i];
  }

  m_yAngles = new int[_ySize];
  for(int i = 0; i < _ySize; i++){
    m_yAngles[i] = _yAngles[i];
  }
}

void Leg::attach(int _xPin, int _yPin){
  m_xServo.attach(_xPin);
  m_yServo.attach(_yPin);
}

void Leg::setPosition(int _x, int _y){
  m_xServo.write(getXAngle(_x));
  m_yServo.write(getYAngle(_y));
  m_curX = _x;
  m_curY = _y;
}

int Leg::getXAngle(int _position){
  return m_xAngles[_position];
}

int Leg::getYAngle(int _position){
  return m_yAngles[_position];
}

