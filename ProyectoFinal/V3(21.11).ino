// Una alarma con Arduino.
// Componentes: ESP8266, Sensor de movimiento PIR, Bocina, Keypad
// Estadios: 1. Desarmado 2. Armado
// Armado: 
// El sistema activará la bocina 15s después de que se detecte movimiento.
// Desarmado:
// Una vez que se ingresa la contraseña en el keypad, el sistema se desactiva.
// Para armar nuevamente, se presiona el botón # del keypad.
#include <Keypad.h>
const byte Bocina = 10;
const byte PIR = 2;
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {5, 4, 3, 2};
int password[4] = {5,5,5,5};
int ingresado[4] = {0,0,0,0};
bool sonando = false;
int Errores = 0;
bool armado = false;
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
        if (key == '#') {
            armado = true;
            Serial.println("Armado");
        } else {
            if (armado) {
                               
        }
}