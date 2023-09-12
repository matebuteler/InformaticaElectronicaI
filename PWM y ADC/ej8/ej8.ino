// Conectar los puertos 9, 10 y 11 a los pines del led RGB de la placa.
// Hacer un algoritmo para que encienda y apague de forma gradual los
// colores Rojo, Verde y Azul de a uno a la vez.
#define RED 9
#define GREEN 10
#define BLUE 11
void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}

void loop() {
    digitalWrite(RED, 1);
    delay(1000);
    digitalWrite(RED,0);
    digitalWrite(GREEN,1);
    delay(1000);
    digitalWrite(GREEN,0);
    digitalWrite(BLUE,1);
    delay(1000);
    digitalWrite(BLUE,0);
}