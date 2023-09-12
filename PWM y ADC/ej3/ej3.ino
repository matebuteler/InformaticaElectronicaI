// En base al ejercicio 1 agregar al circuito 8 leds. Realizar una función que
// mueva dichos leds en forma de vúmetro en función de la posición del
// potenciómetro.
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9
#define pot A3
#include <Arduino.h>
float valor;
void setup() {
    Serial.begin(9600);
}

void loop() {
    valor = (analogRead(pot) * 5) / 1023;
    int leds = valor /8;
    Serial.println(valor);
    for (int i = 0; i < leds; i++) {
        digitalWrite(i, HIGH);
    }
    delay(100);
}

