#include <Servo.h>
Servo cola;

const int COLA = 2;
const int OJOS = 3;
const int TRIG = 5;
const int ECHO = 6;

int angulo;
int salto;
int espera;

int duracion;
int distancia;

void setup() {
  pinMode(OJOS, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);

  cola.attach(COLA);
  salto = 3;
  espera = 0;
  
}

void loop() {

  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);

  duracion = pulseIn(ECHO, HIGH);
  distancia = duracion / 58.2;

  Serial.println(distancia);

 
  if (distancia <= 100 && distancia >= 0)
  {
    int brillo = map(distancia, 0, 100, 100, 2);
    analogWrite(OJOS, brillo);
    
    espera = map (distancia, 0, 100, 0, 40);
    angulo += salto;
    cola.write(angulo);
    if (angulo >= 45 || angulo <= 0) {salto *= -1;}
    delay(espera);

    Serial.println("Espera= " + (String)espera);
  }

  else {analogWrite(OJOS, 2);}
  
}
