#include <Servo.h>

Servo pinza;
int pinServo = 2;


void setup() {
  
  pinza.attach(pinServo);

}

void loop() {
 
pinza.write(0);
delay(5000);
pinza.write(90);
delay(5000);

}
