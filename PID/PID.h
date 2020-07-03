#ifndef PID_H_INCLUDED
#define PID_H_INCLUDED

#include "Arduino.h"

#define POWERON 1
#define POWEROFF 0

class PID{

public:

    PID(double* _input, double* _output);
    PID(double* _input, double* _output ,double _kp, double _ki, double _kd, double _setPoint);

    void calc();
    void setConstants(double _kp, double _ki, double _kd);
    void setOutputLimits(double _minOutput, double _maxOutput);
    void setSetpoint(double _setPoint);
    void setSampleTime(double _sampleTime);
    void setPower(int _power);
    int isPowered();

private:

    unsigned long t_prev = 0;
    double sampleTime;                 //En segundos. Por defecto, medio segundo
    double kp, ki, kd;
    double *input, *output;
    double setPoint;
    double error, ITerm, lastInput, dInput;
    double maxOutput, minOutput;
    int power = 0;

    void initialize();

};

#endif // PID_H_INCLUDED
