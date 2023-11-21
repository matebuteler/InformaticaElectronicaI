// Una alarma con Arduino.
// Componentes: ESP8266, Sensor de movimiento PIR, Bocina, Keypad
// Estadios: 1. Desarmado 2. Armado
// Armado: 
// El sistema activará la bocina 15s después de que se detecte movimiento.
// Desarmado:
// Una vez que se ingresa la contraseña en el keypad, el sistema se desactiva.
// Para armar nuevamente, se presiona el botón # del keypad.
#include <Keypad.h>
const byte Bocina 10
const byte PIR 2
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {5, 4, 3, 2};
int password[4] = {5,5,5,5};
int input[4];
int i;
bool sonando = false;
int Errores = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4, 4 );

void setup() {
    Serial.begin(9600);
    pinMode(Bocina, OUTPUT);
    pinMode(PIR, INPUT);
    digitalWrite(Bocina, sonando);
}

void loop() {
    char key = keypad.getKey();
    if (key != NO_KEY) {
        Serial.println(key);
        if (key == '#') {
            if (input[0] == password[0] && input[1] == password[1] && input[2] == password[2] && input[3] == password[3]) {
                Serial.println("Desarmado");
                Errores = 0;
                sonando = false;
                digitalWrite(Bocina, sonando);
            } else {
                Serial.println("Contraseña incorrecta");
                Errores++;
                if (Errores >= 3) {
                    Serial.println("Alarma activada");
                    sonando = true;
                    digitalWrite(Bocina, sonando);
                }
            }
            for (i = 0; i < 4; i++) {
                input[i] = 0;
            }
        } else {
            for (i = 0; i < 4; i++) {
                if (input[i] == 0) {
                    input[i] = key - '0';
                    break;
                }
            }
        }
    }
    if (digitalRead(PIR) == HIGH) {
        Serial.println("Movimiento detectado");
        delay(15000);
        if (digitalRead(PIR) == HIGH) {
            Serial.println("Alarma activada");
            sonando = true;
            digitalWrite(Bocina, sonando);
        }
    }
}
``` 