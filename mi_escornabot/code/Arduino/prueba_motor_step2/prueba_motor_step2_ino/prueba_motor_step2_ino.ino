
#include <Stepper.h>
#define STEPS 200 //360° divided by step angle

Stepper stepper(STEPS, 8, 9, 10, 11); 

void setup(){ 
  stepper.setSpeed(60); //RPMs 
} 

void loop(){ 
  stepper.step(100); 
  delay(1000); 
  stepper.step(-100); 
  delay(1000); 
} 

