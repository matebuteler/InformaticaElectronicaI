// Continuando con el ejercicio anterior hacer una función que permita
// mostrar de forma porcentual el valor del potenciómetro en el par de
// displays 7 segmentos de la placa.
#define LED_a 6
#define LED_b 7
#define LED_c 8
#define LED_d 2 //9 no anda
#define LED_e 10
#define LED_f 11
#define LED_g 12
#define com1 5
#define com2 4


#include <Arduino.h>

unsigned long lastTime = 0;

bool counting = false; 

void setup() {
    pinMode(LED_a,OUTPUT);
    pinMode(LED_b,OUTPUT);
    pinMode(LED_c,OUTPUT);
    pinMode(LED_d,OUTPUT);
    pinMode(LED_e,OUTPUT);
    pinMode(LED_f,OUTPUT);
    pinMode(LED_g,OUTPUT);
    pinMode(com1,OUTPUT);
    pinMode(com2,OUTPUT);
//    pinMode(pot,INPUT);
}

void disp7seg(int n){
  digitalWrite(LED_a, (n != 1 && n != 6 && n != 4));
  digitalWrite(LED_b, (n != 5 && n != 6));
  digitalWrite(LED_c, (n != 2));
  digitalWrite(LED_d, (n != 1 && n != 4 && n != 7 && n != 9));
  digitalWrite(LED_e, (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9));
  digitalWrite(LED_f, (n != 1 && n != 2 && n != 3 && n != 7));
  digitalWrite(LED_g, (n != 0 && n != 1 && n != 7));
  }


void multiplex(int n) { //com1 = decena, com2 = unidad
    int decena = n/10;
    int unidad = n%10;
    digitalWrite(com2, HIGH); // apaga display de la unidad
    disp7seg(decena);	   // muestra decena
    digitalWrite(com1, LOW); // enciende display decena
    delay(4);
    digitalWrite(com1, HIGH); // apaga display decena
    disp7seg(unidad);	    // muestra unidad
    digitalWrite(com2, LOW); // enciende display unidad
    delay(8);
}

void loop() {
    int valor = (analogRead(A3) * 100)/1023;
    multiplex(valor); 
    delay(100);
}