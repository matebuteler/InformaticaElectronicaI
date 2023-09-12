// Modificar el programa anterior agregando una función para que muestre
// la temperatura por medio de los display 7 segmentos. Realizar otra
// función que encienda un led cuando la temperatura supere los 28C.

#define LED_a 6
#define LED_b 7
#define LED_c 8
#define LED_d 2 //9 no anda
#define LED_e 10
#define LED_f 11
#define LED_g 12
#define com1 4
#define com2 5
#define p1 13
#define LED_28 3

//lm35 esta en A3
#include <Arduino.h>
float temp;

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
    pinMode(LED_28, OUTPUT);
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
    delay(4);
}

void supera28(int temp) { //funcion para ver si supera 28 (innecesario que sea una funcion aparte pero se hace por conformidad con la consigna)
    if (temp > 28) {
        digitalWrite(LED_28, 1);
    }
}

void loop() {
    temp = ((analogRead(A3) * 4.9 )/ 10); //4.9mv es la resolucion del arduino (5v / 1024)
    multiplex(temp); 
    supera28(temp);
    delay(100);

}