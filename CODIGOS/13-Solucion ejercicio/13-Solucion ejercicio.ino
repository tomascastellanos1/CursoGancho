#include <Servo.h>

Servo pinza;
int pinServo = 2;


void setup() {
  
  pinza.attach(pinServo);

}

void loop() {
 
pinza.write(37);
delay(1000);
pinza.write(80);
delay(1000);



}
