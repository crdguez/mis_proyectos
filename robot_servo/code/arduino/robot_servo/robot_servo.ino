#include "Servo.h"

Servo servoR, servoL;

//Delays
int defaultDelay = 200, lineasDelay = 0;
int giro_180 = 1028, giro_90 = 514, giro_45 = 257, giro_30 = 200; //Delays para diferentes ángulos
String inString = ""; // String para lectura/escritura desde Protocoder

void setup() {

  Serial.begin(19200); //NO MODIFICAR!!!!!!!!!!!
  Serial.flush();

  servoL.attach(4);
  servoR.attach(5);

  servoR.write(90);
  servoL.write(90);
}

//Funciones de movimiento
void avanzar () {
  servoR.write(180);
  servoL.write(0);
}

void retroceder() {
  servoR.write(0);
  servoL.write(180);
}
void parar() {
  servoR.write(90);
  servoL.write(90);
}
void izquierda() {
  servoR.write(180);
  servoL.write(180);
}
void derecha() {
  servoR.write(0);
  servoL.write(0);
}

void giro_180_grados() {
  servoR.write(180);
  servoL.write(180);
  delay(giro_180);
  parar();
}

void izquierdaLineas() {
  servoR.write(180);
  servoL.write(90);
  delay(lineasDelay);
  parar();
}

void derechaLineas() {
  servoR.write(90);
  servoL.write(0);
  delay(lineasDelay);
  parar();
}

void loop() {
avanzar();
delay(2000);
parar();
delay(10000);
}
