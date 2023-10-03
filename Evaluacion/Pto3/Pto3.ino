// Encender el LED RGB y conformar los siguientes coleres:
// ROJO 0 
// VERDE 1
// AZUL 2
// AMARILLO 3 R & G
// CELESTE 4  G & B
// VIOLETA 5
// BLANCO 6

// 3. Con un tercer pulsador debe poder cambiar entre modo encendido, o intermitente.

#define RED 8
#define GREEN 9
#define BLUE 10
#define p1 11
#define p2 12
#define p3 13

int p1_ant = 0;
int p2_ant = 0;
int p3_ant = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
}
// p1 = Turn the led on
// The LED must change between the colors defined above
// p2 = Turn the led off
// p3 = Change the led mode to intermittent

void loop() {
    if (digitalRead(p1) and !p1_ant) {
        for (int col = 0; col < 7; col++) {
            digitalWrite(RED, (col == 0 || col == 3 || col == 5 || col == 6));
            digitalWrite(GREEN, (col == 1 || col == 3 || col == 4 || col == 6));
            digitalWrite(BLUE, (col == 2 || col == 4 || col == 5 || col == 6));
            delay(1000);
        }
    }
    if (digitalRead(p2) and !p2_ant) {
        digitalWrite(RED, 0);
        digitalWrite(GREEN, 0);
        digitalWrite(BLUE, 0);
    }
    if (digitalRead(p3) and !p3_ant) {
        for (int col = 0; col < 7; col++) {
            digitalWrite(RED, (col == 0 || col == 3 || col == 5 || col == 6));
            digitalWrite(GREEN, (col == 1 || col == 3 || col == 4 || col == 6));
            digitalWrite(BLUE, (col == 2 || col == 4 || col == 5 || col == 6));
            delay(1000);
            digitalWrite(RED, 0);
            digitalWrite(GREEN, 0);
            digitalWrite(BLUE, 0);
            delay(500);
        }
    }
    p1_ant = digitalRead(p1);
    p2_ant = digitalRead(p2);
    p3_ant = digitalRead(p3);
}
