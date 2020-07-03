#include "PID.h"

PID::PID(double* _input, double* _output){

    input = _input;
    output = _output;

    kp = 0;
    ki = 0;
    kd = 0;

    setPoint = 0;

    sampleTime = 0.5;

    power = 1

}

PID::PID(double* _input, double* _output, double _kp, double _ki, double _kd, double _setPoint){

input = _input;
output = _output;

kp = _kp;
ki = _ki;
kd = _kd;
setPoint = _setPoint;

sampleTime = 0.5;

}

void PID::calc(){

if(!power) return;

unsigned long t = micros();
double dt = t - t_prev;
dt /= 1000000;

if(dt >= sampleTime){

    error = setPoint - *input;
    dInput = *input - lastInput;
    ITerm += (ki * error);

    if(ITerm >= maxOutput) ITerm = maxOutput;
    if(ITerm <= minOutput) ITerm = minOutput;

    *output = error * kp - dInput * kd + ITerm;


    lastInput = *input;
    t_prev = t;

    if(*output >= maxOutput) *output = maxOutput;
    if(*output <= minOutput) *output = minOutput;


}

}

void PID::setConstants(double _kp, double _ki, double _kd){

/*kp = _kp;
ki = _ki * sampleTime;
kd = _kd / (double) sampleTime;*/

kp = _kp;
ki = _ki;
kd = _kd;

}

void PID::setOutputLimits(double _minOutput, double _maxOutput){

if(_minOutput > _maxOutput) return;

minOutput = _minOutput;
maxOutput = _maxOutput;

}

void PID::setSetpoint(double _setPoint){

setPoint = _setPoint;

}

void PID::setSampleTime(double _sampleTime){

    if(_sampleTime >0 ){

        double proportion = (double) _sampleTime / (double) sampleTime;

        ki *= proportion;
        kd /= proportion;

        sampleTime = _sampleTime;

    }

}

void PID::setPower(int _power)
{
    int newPower = !(_power == power);
    if(newPower && !power)
    {  //Se acaba de encender el PID
        initialize();
    }
    power = _power;
}

void PID::initialize(){

    lastInput = *input;
    ITerm = *output;
    if(ITerm > maxOutput) ITerm = maxOutput;
    if(ITerm < minOutput) ITerm = minOutput;

}

int PID::isPowered(){

	return power;

}

