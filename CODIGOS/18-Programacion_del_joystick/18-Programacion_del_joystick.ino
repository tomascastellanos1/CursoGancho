int arriba=2;
int abajo =3;
int izq=4;
int der=5;


void setup() {

  Serial.begin(9600);
  pinMode(arriba, INPUT_PULLUP);
  pinMode(abajo,INPUT_PULLUP);
  pinMode(izq,INPUT_PULLUP);
  pinMode(der, INPUT_PULLUP);

}

void loop() {

int estado1 = digitalRead(arriba);
int estado2 = digitalRead(abajo);
int estado3 = digitalRead(izq);
int estado4 = digitalRead(der);

if(estado1==LOW){
  Serial.println("PULSADO ARRIBA");
  delay(500);
}

if(estado2==LOW){
  Serial.println("PULSADO ABAJO");
  delay(500);
}

if(estado3==LOW){
  Serial.println("PULSADO IZQUIERDA");
  delay(500);
}

if(estado4==LOW){
  Serial.println("PULSADO DERECHA");
  delay(500);
}

}
