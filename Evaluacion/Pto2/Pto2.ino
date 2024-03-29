// Encender el LED RGB y conformar los siguientes coleres:
// ROJO 0 
// VERDE 1
// AZUL 2
// AMARILLO 3 R & G
// CELESTE 4  G & B
// VIOLETA 5
// BLANCO 6

// Implementando dos pulsadores por flanco se debe poder prender y apagar el led

#define RED 8
#define GREEN 9
#define BLUE 10
#define p1 11
#define p2 12

int p1_ant = 0;
int p2_ant = 0;
bool on = 0;

void setup() {
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
 }

void loop() {
    if (digitalRead(p1) and !p1_ant) on = 1;
    if (digitalRead(p2) and !p2_ant) on = 0;

    for (int col = 0; on; col++) {
        if (col > 7) col = 0;
        digitalWrite(RED, (col == 0 || col == 3 || col == 5 || col == 6));
        digitalWrite(GREEN, (col == 1 || col == 3 || col == 4 || col == 6));
        digitalWrite(BLUE, (col == 2 || col == 4 || col == 5 || col == 6));
        delay(1000);
    }
    p1_ant = digitalRead(p1);
    p2_ant = digitalRead(p2);
}
