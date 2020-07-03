/*
 * Example of use of the library brushlessMt by Miguel Sánchez Domínguez
 */

#include "brushlessMt.h"

#define INPUT_PIN A0

//Declaration of variables we will be using

int vel;
int maxVel = 1750, minVel = 1000;

//Declaration of the brushless motor object
brushlessMt mt;

void setup() {
  mt.init(5);                                   //We attach the motor to a PWM pin.
  mt.setRange(minVel, maxVel);                  //Set the range of velocities in wich the motor will work.
                                                //Theese values must vary between 1000 and 2000.
  mt.powerOff();                                //This is equivalent to set the motor velocity to 1000. 

}

void loop() {
  int reading = analogRead(INPUT_PIN);
  vel = map(reading, 0, 1023, minVel, maxVel);  //We set the motor velocity accordingly to the reading

}
