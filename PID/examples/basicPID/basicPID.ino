/*
 * Example of use of the library PID by Miguel Sánchez Domínguez
 * 
 * NOTE: To make this library I used http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/ as reference
 * 
 */

#include "PID.h"

#define INPUT_PIN A1
#define OUTPUT_PIN 5

//Declaration of variables we will be using.

double kp = 1, ki = 0.2, kd = 0.5;
double input, output, setpoint, sampleTime = 0.05;

//Declarations of the PID object

PID pid(&input, &output);                           //This is the most basic declaration of the PID object

//PID pid(&input, &output, kp, ki, kd, setpoint)    //We could also declared the object like that

void setup() {

  pid.setConstants(kp, ki, kd);   //We set the constants of the PID. By default they are all 0
  pid.setSetpoint(setpoint);      //The value we want in the output. By default its 0
  pid.setSampleTime(sampleTime);  //Sample time in seconds. By default is 0.5
  pid.setOutputLimits(0, 255);    //The output will vary between those values
  //pid.setPower(POWEROFF);       //We can also power it off. By default its powered.

}

void loop() {
  input = analogRead(INPUT_PIN);
  
  pid.calc();                     //We run the pid calculations, updating the output value

  analogWrite(OUTPUT_PIN, output);

}
