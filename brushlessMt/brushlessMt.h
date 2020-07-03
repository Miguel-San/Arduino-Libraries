#ifndef BRUSHLESSMT_H_INCLUDED
#define BRUSHLESSMT_H_INCLUDED


#include <Arduino.h>
#include <Servo.h>

class brushlessMt{

public:

    brushlessMt();
    void init(int pin);
    void setRange(int _minVel, int _maxVel);
    void setVel(int _vel);
    void powerOff();
    int getVel();

private:

    Servo mt;

    int vel;
    int maxVel;
    int minVel;

};

#endif // BRUSHLESSMT_H_INCLUDED
