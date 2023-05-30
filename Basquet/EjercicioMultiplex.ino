
//Crear un algoritmo para un Arduino conectado a un display 7 segmentos y un parlante el cual mediante dos botones implementados por "click" permita realizar las siguientes tareas:
//1. Botón 1: al presionar debe incrementar la cuenta en 1 que se ve en el display hasta un máximo de 9. Si la cuenta se pasa de tal valor el número debe comenzar nuevamente en 0.
//2. Botón 2: al presionar el display debe automáticamente comenzar a realizar una cuenta regresiva desde el valor que quedó seteado en el display hasta llegar a 0.
//3. al terminar la cuenta regresiva debe sonar la alarma 5 veces para indicar que terminó la cuenta y quedar listo para volver a setear la nueva cuenta del punto 1.
#define LED_a 2
#define LED_b 3
#define LED_c 4
#define LED_d 5
#define LED_e 6
#define LED_f 7
#define LED_g 8 
#define buzzer 9
#define com1 10
#define com2 11
#define boton1 12
#define boton2 14
#include <Arduino.h>

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

  if (n!=1 and n!=6) {
    digitalWrite(LED_a,1);
  }
  if (n!=5 and n!=6) {
    digitalWrite(LED_b,1);
  }
  if (n!=2) {
    digitalWrite(LED_c,1);
  }
  if (n!=1 and n!=4 and n!=7 and n!=9) {
    digitalWrite(LED_d,1);
  }
  if (n!=1 and n!=3 and n!=4 and n!=5 and n!=7 and n!=9) {
    digitalWrite(LED_e,1);
  }
  if (n!=1 and n!=2 and n!=3 and n!=7){
    digitalWrite(LED_f,1);
  }
  if (n!= 0 and n!=1 and n!=7) {
    digitalWrite(LED_g,1);
  }
}

void multiplex(int n) {
    int decena = n/10;
    int unidad = n%10;
    digitalWrite(com1, HIGH); //turns on the first display
    digitalWrite(com2, LOW); // off second display
    disp7seg(decena);
    delay(5);
    digitalWrite(com1, LOW); //turns off the first display
    digitalWrite(com2, HIGH); //turns on the second display
    disp7seg(unidad);
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
void buzz(int n) {
    for (int i = 0; i < n; i++) {
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        delay(200);
    }
    
}   

// BOTON 1: Comienza cuenta regresiva desde 24
// BOTON 2: Pausa y reanuda cuenta regresiva
bool counting; 
int i = 24; // i being the value shown on the display (0-24)
void loop(){
    bool estado1 = digitalRead(boton1);
    bool estado2 = digitalRead(boton2);
    if (estado1 and !estado1_anterior) {
        i = 24;
        counting = true;
    }

    if (estado2 and !estado2_anterior) {
            counting = !counting;
        }
    
    while (counting) {
        multiplex(i);
        if (i == 0) {
            buzz(5);
            counting = false;
        }
        i--;
        delay(1000);
    }
    estado1_anterior = estado1;
    estado2_anterior = estado2;
}