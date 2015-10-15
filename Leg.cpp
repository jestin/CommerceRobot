#include "Leg.h"

Leg::Leg(){
  m_curX = 0;
  m_curY = 0;
}

Leg::~Leg(){
}

void Leg::setAngles(int _xAngles[], int _xSize, int _yAngles[], int _ySize){
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

