#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C
#include <Servo.h>
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int tiempo= 6000;


int botonCentral=A1;
int botonAux2=A2;
int botonAux1=A3;

int arriba = 7;
int abajo = 2;
int izquierda = 8;
int derecha = 4;


int pinBobina = 3;
int pinPinza = 5;
int pinIZQyDER1 = 6;
int pinIZQyDER2 = 9;
int pinARRyABA1 = 10;
int pinARRyABA2 = 11;



Servo railesIZQyDER1;
Servo railesIZQyDER2;

Servo railesARRyABA1;
Servo railesARRyABA2;

Servo Bobina;
Servo Pinza;


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

    pinMode(arriba,INPUT_PULLUP);
    pinMode(abajo,INPUT_PULLUP);
    pinMode(izquierda,INPUT_PULLUP);
    pinMode(derecha,INPUT_PULLUP);

    railesIZQyDER1.attach(pinIZQyDER1);
    railesIZQyDER2.attach(pinIZQyDER2);
   
    railesARRyABA1.attach(pinARRyABA1);
    railesARRyABA2.attach(pinARRyABA2);

    Bobina.attach(pinBobina);
    Pinza.attach(pinPinza);

}

void loop() {

  int estadoBotonCentral = digitalRead(botonCentral);
  int estadoBotonAux1 = digitalRead(botonAux1);
  int estadoBotonAux2 = digitalRead(botonAux2);

  int estadoJoyArriba = digitalRead(arriba);
  int estadoJoyAbajo = digitalRead(abajo);
  int estadoJoyIzquierda = digitalRead(izquierda);
  int estadoJoyDerecha = digitalRead(derecha);


//-----------------------MODO MAQUINA
 if(modo==1){
     lcd.setCursor(5, 1);
    lcd.print("Tiempo:");

     lcd.setCursor(13, 1);
    lcd.print(tiempo);

    lcd.setCursor(15, 1);
    lcd.print("  ");


    tiempo--;

 

    if(tiempo<=1000){
       lcd.setCursor(14, 1);
    lcd.print("  ");
    }

  if (estadoJoyArriba==true && estadoJoyAbajo==true){
railesARRyABA1.write (90); 
railesARRyABA2.write (90); 
}
 if (estadoJoyIzquierda==true && estadoJoyDerecha==true){
railesIZQyDER1.write (90); 
railesIZQyDER2.write (90); 
}

  if (estadoJoyIzquierda==false){ 
  railesIZQyDER1.write (0); 
  railesIZQyDER2.write (180); 
 
  }else{
  railesIZQyDER1.write (90); 
  railesIZQyDER2.write (90); 
  }
  
  if (estadoJoyDerecha==false){ 
  railesIZQyDER1.write (180); 
  railesIZQyDER2.write (0); 

  }

  if (estadoJoyArriba==false){ 
 railesARRyABA1.write (0); 
 railesARRyABA2.write (180); 

  }
  
  if (estadoJoyAbajo==false){ 
 railesARRyABA1.write (180); 
 railesARRyABA2.write (0); 

  }
   
   if(tiempo<=0){
     tiempo=0;
     modo=3;
   }

     if(estadoBotonAux1==LOW){ //Boton AUX1: MODO 2
     lcd.clear();
     delay(500);
      modo=2;
     }

   
 
   

if(estadoBotonCentral==LOW){ //Boton Central: Uso máquina
 modo=3;
}


 }
 //-----------------------ACABA MODO MAQUINA
//-----------------------MODO LIBRE
 if(modo==2){

 lcd.setCursor(5, 0);
    lcd.print("Modo libre!");
    

     if (estadoJoyArriba==true && estadoJoyAbajo==true){
railesARRyABA1.write (90); 
railesARRyABA2.write (90); 
}
 if (estadoJoyIzquierda==true && estadoJoyDerecha==true){
railesIZQyDER1.write (90); 
railesIZQyDER2.write (90); 
}

  if (estadoJoyIzquierda==false){ 
  railesIZQyDER1.write (0); 
  railesIZQyDER2.write (180); 
  }
  
  if (estadoJoyDerecha==false){ 
  railesIZQyDER1.write (180); 
  railesIZQyDER2.write (0); 
  }

  if (estadoJoyArriba==false){ 
 railesARRyABA1.write (0); 
 railesARRyABA2.write (180); 
  }
  
  if (estadoJoyAbajo==false){ 
 railesARRyABA1.write (180); 
 railesARRyABA2.write (0); 
  }

   if (estadoBotonAux1==true && estadoBotonAux2==true){
Bobina.write (90); 
Bobina.write (90); 
}

if(estadoBotonCentral==LOW){ //Boton Central: Abre y cierra la pinza
Pinza.write(37);   // cierra la pinza
}else{
Pinza.write(80);   // sino, la pinza siempre está abierta
}


  if(estadoBotonAux1==LOW){ //Boton AUX1: Sube la pinza
   Bobina.write(0);
  }
  if(estadoBotonAux2==LOW){ //Boton AUX2: Baja la pinza
   Bobina.write(180);
  }



 }
//-----------------------ACABA MODO LIBRE

if(modo==3){
  railesIZQyDER1.write (90); 
  railesIZQyDER2.write (90); 
  railesARRyABA1.write (90); 
  railesARRyABA2.write (90); 
  Pinza.write(80);   // abre la pinza
  Bobina.write(180); //bobina baja
  delay(3000); //durante 3 segundos
  Bobina.write(90); //bobina parada
  delay(1000); //durante un segundo
  Pinza.write(37); //cierra la pinza
  delay(1500); //durante segundo y medio
  Bobina.write(0);//bobina sube
  delay(3000);//durante 3 segundos
  Bobina.write(90);
  railesIZQyDER1.write (180); 
  railesIZQyDER2.write (0); 
  railesARRyABA1.write (180); 
  railesARRyABA2.write (0); 
  delay(4000);
  railesIZQyDER1.write (90); 
  railesIZQyDER2.write (90); 
  railesARRyABA1.write (90); 
  railesARRyABA2.write (90); 
  delay(1000);
  Pinza.write(80);
  delay(500);
 modo=1;
tiempo=6000;
}
  
}