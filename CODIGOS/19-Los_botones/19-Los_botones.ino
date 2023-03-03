int boton1 =2;
int boton2 =3;
int boton3 =4;


int contador=0;

void setup() {

Serial.begin(9600);
pinMode(boton1,INPUT_PULLUP);
pinMode(boton2, INPUT_PULLUP);
pinMode(boton3, INPUT_PULLUP);

}

void loop() {

Serial.println(contador);

int estadoboton1 = digitalRead(boton1);
int estadoboton2= digitalRead(boton2);
int estadoboton3= digitalRead(boton3);

if(estadoboton1==LOW){
 contador+=1;
 delay(500);
}
if(estadoboton2==LOW){
 contador-=1;
 delay(500);
}
if(estadoboton3==LOW){
 contador=0;
 delay(500);
}

}
