// Encender el LED RGB y conformar los siguientes coleres:
// ROJO 0 
// VERDE 1
// AZUL 2
// AMARILLO 3 R & G
// CELESTE 4  G & B
// VIOLETA 5
// BLANCO 6

 #define RED 8
 #define GREEN 9
 #define BLUE 10

 void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
 }

void loop() {
    for (int col = 0; col < 7; col++) {
        digitalWrite(RED, (col == 0 || col == 3 || col == 5 || col == 6));
        digitalWrite(GREEN, (col == 1 || col == 3 || col == 4 || col == 6));
        digitalWrite(BLUE, (col == 2 || col == 4 || col == 5 || col == 6));
        delay(1000);
    }
}
