// Continuando con el ejercicio anterior hacer una función que permita
// mostrar de forma porcentual el valor del potenciómetro en el par de
// displays 7 segmentos de la placa.
#define LED_a 0
#define LED_b 1
#define LED_c 2
#define LED_d 3
#define LED_e 4
#define LED_f 5
#define LED_g 6
#define com1 7
#define com2 8
#define pot A3
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
  // se asegura de que todos los pines estén en 0
  digitalWrite(LED_a,0);
  digitalWrite(LED_b,0);
  digitalWrite(LED_c,0);
  digitalWrite(LED_d,0);
  digitalWrite(LED_e,0);
  digitalWrite(LED_f,0);
  digitalWrite(LED_g,0);

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
    delay(4);
}

void loop() {
    int valor = analogRead(pot);
    multiplex((valor *100)/ 1023); 
    delay(100);
}