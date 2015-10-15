#ifndef LEG_H
#define LEG_H

#include <Servo.h>
#include <Arduino.h>

class Leg {
  private:
    int m_curX;
    int m_curY;
    Servo m_xServo;
    Servo m_yServo;

    int m_xAngleCount;
    int* m_xAngles;

    int m_yAngleCount;
    int* m_yAngles;

    int getXAngle(int _position);
    int getYAngle(int _position);
    
  public:
    Leg();
    ~Leg();

    void setAngles(int _xAngles[], int _xSize, int _yAngles[], int _ySize);
    void attach(int _xPin, int _yPin);
    void setPosition(int _x, int _y);
};
#endif
