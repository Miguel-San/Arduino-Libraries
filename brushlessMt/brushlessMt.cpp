#include "brushlessMt.h"

brushlessMt::brushlessMt(){}

void brushlessMt::init(int pin){

    mt.attach(pin);
    vel = 1000;
    mt.writeMicroseconds(vel);

}

void brushlessMt::setRange(int _minVel, int _maxVel){

    minVel = _minVel;
    maxVel = _maxVel;

}

void brushlessMt::setVel(int _vel){

    if(_vel > maxVel) vel = maxVel;
    else if(_vel < minVel) vel = minVel;
    else vel = _vel;

    mt.writeMicroseconds(vel);

}

void brushlessMt::powerOff(){

    mt.writeMicroseconds(1000);

}

int brushlessMt::getVel(){

    return vel;

}

