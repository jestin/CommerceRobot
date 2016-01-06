// This class abstracts a leg of the robot, such that we
// can set its position by giving it an X,Y value.

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

    // Defines the angles for each position
    void setAngles(int _xAngles[], int _xSize, int _yAngles[], int _ySize);
    
    // attaches the leg to specific pins on the arduino
    void attach(int _xPin, int _yPin);
    
    // sets the angles of the robot, by giving it a predefined X,Y position
    void setPosition(int _x, int _y);
};
#endif
