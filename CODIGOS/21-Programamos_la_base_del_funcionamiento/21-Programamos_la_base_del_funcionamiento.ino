#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int tiempo= 60;
int contador =0;

int botonAux1=9;
int botonAux2=10;

int botonCentral=8;
int botonAux1=9;
int botonAux2=10;

int pinServo = 6;
int pinServo = 7;

Servo pinza;
Servo pinza;

int modo = 1;
/*
1= modo maquina
2= modo libre
3= modo automatico
*/

void setup() {

    lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
    lcd.begin(20, 4);     // 20 columnas por 4 lineas para LCD 1602A
    lcd.clear();      // limpia pantalla
    pinMode(botonCentral,INPUT_PULLUP);
    pinMode(botonAux1,INPUT_PULLUP);
    pinMode(botonAux2,INPUT_PULLUP);

}

void loop() {

  int estadoBotonCentral = digitalRead(botonCentral);
  int estadoBotonAux1 = digitalRead(botonAux1);
  int estadoBotonAux2 = digitalRead(botonAux2);

//-----------------------MODO MAQUINA
 if(modo==1){
     lcd.setCursor(5, 1);
    lcd.print("Tiempo:");

     lcd.setCursor(13, 1);
    lcd.print(tiempo);

    tiempo--;
    delay(1000);

    if(tiempo<=10){
       lcd.setCursor(14, 1);
    lcd.print(" ");
    }
   
   if(tiempo<=0){
     tiempo=0;

    if(contador>=2){ // REINICIO!!
    contador=0;
    tiempo=60;
    lcd.setCursor(4, 2);
    lcd.print("Reiniciado!");
    delay(1500);
    lcd.setCursor(4, 2);
    lcd.print("           ");
  }

   }

if(estadoBotonCentral==LOW){
contador++;
}else{
contador=0;
}
if(estadoBotonAux1==LOW || estadoBotonAux2==LOW){
  lcd.clear();
  modo=2;
}

 }
 //-----------------------ACABA MODO MAQUINA
//-----------------------MODO LIBRE
 if(modo==2){

 lcd.setCursor(5, 1);
    lcd.print("Modo libre!");

if(estadoBotonCentral==LOW){
contador++;
delay(1000);
}else{
contador=0;
}

if(contador>=3){ 
    contador=0;
    tiempo=60;
   lcd.clear();
   modo=1;
  }

 }
//-----------------------ACABA MODO LIBRE


  
}
