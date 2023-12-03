#include <Key.h>
#include <Keypad.h>

// Una alarma con Arduino.
// Componentes: ESP8266, Sensor de movimiento PIR, Bocina, Keypad
// Estadios: 1. Desarmado 2. Armado
// Armado: 
// El sistema activará la bocina 15s después de que se detecte movimiento.
// Desarmado:
// Una vez que se ingresa la contraseña en el keypad, el sistema se desactiva.
// Para armar nuevamente, se presiona el botón # del keypad.
const byte Bocina = 10;
const byte PIR = 2;
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[4] = {0, 1, 2, 3};
byte colPins[4] = {4, 5, 6, 7};
int password[4] = {5,5,5,5};
int ingresado[4] = {0,0,0,0};
int tiempo = 30; // Segundos que tarda en activarse la bocina tras detectar movimiento.
bool sonando = false;
bool armado = false;
char key;
bool movimiento = false;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4, 4 );
void esperarKey() { 
    key = keypad.getKey();
    if key = NO_KEY {
        return;
    } else {
        if (key == '#') {
            armado = true;
            Serial.println("Armado");
        } else { //se está intentando ingresar una contraseña
            
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(Bocina, OUTPUT);
    pinMode(PIR, INPUT);
    digitalWrite(Bocina, sonando);
    // attachInterrupt para que cuando se detecte una pulsación en el teclado, se interrumpa el delay()
    // y se pueda ingresar la contraseña.
    attachInterrupt(digitalPinToInterrupt(xd), esperarKey, CHANGE);
}

void loop() {
    if (armado) {
        if (movimiento) {
            Serial.println("Movimiento detectado");
            delay(tiempo*1000); // Este delay será interrumpido si se detecta una pulsación en el teclado
            sonando = true;
            digitalWrite(Bocina, sonando);
        } else {}
}
}