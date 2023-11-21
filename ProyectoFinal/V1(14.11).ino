#define Bocina 10
#define Infrarojo 12
#include <Keypad.h>

int Errores = 0;
bool PIR = 0;
float tiempoAlarma = 0;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad Teclado = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char contra[7] = "277353";
char ingresarContra[7];
int cifra = 0;

void setup() {
    Serial.begin(9600);
}

void sonarAlarma() {
    digitalWrite(Bocina, 1);
}

void loop() {
    char key = Teclado.getKey();

    if (key) {
        Serial.println(key);
        ingresarContra[cifra] = key;
        cifra++;
    }
    if (cifra == 6) {
        if (strcmp(contra, ingresarContra) == 0) {
            Serial.println("OK");
            Errores = 0;
        } else {
            Serial.println("DENEGADO");
            Errores++;
        }
        cifra = 0;
    }
    if (Errores == 3) {
        sonarAlarma();
    }
    if (!digitalRead(11) || !digitalRead(12)) {
        millis();
        if (millis() >= 30000) {
            sonarAlarma();
        }
    }
}