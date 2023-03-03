#include <Servo.h>

int pinServo = 2;
int pinServoBobina = 3;
int pinServoEjemplo = 4;

Servo pinza;
Servo bobina;
Servo ejemplo;


void setup() {
  
  pinza.attach(pinServo);
  bobina.attach(pinServoBobina);
  ejemplo.attach(pinServoEjemplo);

}

void loop() {

/*
pinza.write(37); 
delay(500);
pinza.write(80);
delay(500); */
bobina.write(0);
ejemplo.write(180);
delay(1000);
bobina.write(90);
ejemplo.write(90);
delay(1000);
bobina.write(180);
ejemplo.write(0);
delay(1000);






}
