
/*
Realizar un algoritmo con dos display7seg que por medio de un pulsador comience una cuenta regresiva de 24 segundos y al finalizar, 
suene un buzzer y quedar esperando que se presione nuevamente el pulsador para reiniciar la cuenta regresiva. 
En cualquier momento que se presione el pulsador la cuenta debe reiniciar a 24 segundos y recomenzar la cuenta atrás. 
Con un segundo pulsador, la cuenta debe poder pausarse y reanudarse en cualquier momento.
*/



#define LED_a 0
#define LED_b 1
#define LED_c 2
#define LED_d 3
#define LED_e 4
#define LED_f 5
#define LED_g 6
#define buzzer 11
#define com1 7
#define com2 8
#define boton1 9
#define boton2 10
#include <Arduino.h>

unsigned long lastTime = 0;

bool counting = false;
bool estado1;
bool estado2; 
int disp = 24; //numero en el display
bool estado1_anterior;
bool estado2_anterior;

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

void setup(){
    pinMode(LED_a, OUTPUT);
    pinMode(LED_b, OUTPUT);
    pinMode(LED_c, OUTPUT);
    pinMode(LED_d, OUTPUT);
    pinMode(LED_e, OUTPUT);
    pinMode(LED_f, OUTPUT);
    pinMode(LED_g, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(com1, OUTPUT);
    pinMode(com2, OUTPUT);
    pinMode(boton1, INPUT);
    pinMode(boton2, INPUT);
}  

// BOTON 1: Comienza cuenta regresiva desde 24
// BOTON 2: Pausa y reanuda cuenta regresiva

void loop(){
    estado1 = digitalRead(boton1);
    estado2 = digitalRead(boton2);

    if (estado1 and !estado1_anterior) {
        disp = 24;
        counting = true;
    }

    if (estado2 and !estado2_anterior) {
            counting = !counting;
        }
    
    if (counting and (millis() - lastTime >= 1000)) { //
        digitalWrite(buzzer,LOW);
        multiplex(disp);
        if (disp == 0) {
            digitalWrite(buzzer, HIGH);
            counting = false;
        } else {
            disp--;
        }
      lastTime = millis();
    }
    estado1_anterior = estado1;
    estado2_anterior = estado2;
}