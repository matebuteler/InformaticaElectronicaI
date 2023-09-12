// Realizar un programa que según el valor medido de un potenciómetro se
// encienda el led RGB para los siguientes casos:
// 0. Pot < 150 --- Led Rojo
// 1. 150 < Pot < 300 --- Led Naranja
// 2. 300 <; Pot < 450 --- Led Amarillo
// 3. 450 < Pot < 600 --- Led Verde
// 4. 600 < Pot < 750 --- Led Celeste
// 5. 750 < Pot < 900 --- Led Azul
// 6. 900 &; Pot --- Led Violeta

#define pot A1
#define RED 1
#define GREEN 2
#define BLUE 3
int adc;
int num;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}

void color(int n) { //1 = Rojo; 2= Verde; 3=Azul; 4= Amarillo; 5= Celeste; 6= Violeta; 7= Blanco
    digitalWrite(RED, (n = 1 || n = 4 || n = 6 || n = 7));
    digitalWrite(GREEN, (n = 2 || n = 4 || n = 5 || n = 7));
    digitalWrite(BLUE, (n = 3 || n = 5 || n = 6 || n = 7));
}

void loop() {
    color(analogRead(pot)/150);
}