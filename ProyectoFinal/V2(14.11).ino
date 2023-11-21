// Incluir la biblioteca Keypad
#include <Keypad.h>
//TODO: # y * para armar y desarmar la alarma
 
// Definir constantes para los números de pin
const byte Bocina = 10;
const byte Infrarojo = 12;

// Definir el diseño del teclado
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

// Definir los pines para las filas y columnas del teclado
byte rowPins[4] = {9, 8, 7, 6}; 
byte colPins[3] = {5, 4, 3}; 

// Crear un objeto Keypad
Keypad Teclado = Keypad( makeKeymap(keys), rowPins, colPins, 4, 3 );

// Definir la contraseña y un array para almacenar la contraseña ingresada
char contra[6] = {'1', '2', '3', '4', '5', '6'};
char ingresarContra[6];
byte cifra = 0;

// Definir una variable para el estado de la alarma
bool estadoAlarma = false;

// Definir una variable para el conteo de errores
byte Errores = 0;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);
  
  // Configurar los pines Bocina e Infrarojo como salidas
  pinMode(Bocina, OUTPUT);
  pinMode(Infrarojo, OUTPUT);
  
  // Adjuntar una interrupción al teclado
  attachInterrupt(digitalPinToInterrupt(Teclado.getPin()), handleKeyPress, CHANGE);
}

void handleKeyPress() {
  // Obtener la tecla presionada
  char key = Teclado.getKey();
  
  // Si se presionó una tecla, almacenarla en el array ingresarContra y incrementar el contador cifra
  if (key) {
    ingresarContra[cifra] = key;
    cifra++;
  }
  
  // Si se han ingresado 6 dígitos, verificar la contraseña
  if (cifra == 6) {
    checkPassword();
  }
}

void checkPassword() {
  // Comparar la contraseña ingresada con la contraseña almacenada
  if (strcmp(contra, ingresarContra) == 0) {
    // Si coinciden, apagar la alarma y alternar el estado de la alarma
    digitalWrite(Bocina, LOW);
    estadoAlarma = !estadoAlarma;
    
    // Restablecer el conteo de errores
    Errores = 0;
  } else {
    // Si no coinciden, incrementar el conteo de errores
    Errores++;
    
    // Si ha habido 3 errores, activar la alarma
    if (Errores == 3) {
      triggerAlarm();
    }
  }
  
  // Restablecer el contador cifra y el array ingresarContra
  cifra = 0;
  memset(ingresarContra, 0, sizeof(ingresarContra));
}

void triggerAlarm() {
  // Configurar el pin Bocina en ALTO para activar la alarma
  digitalWrite(Bocina, HIGH);
}

void loop() {
  // Verificar el estado de la alarma
  if (estadoAlarma) {
    // Si la alarma está activada, verificar el pin Infrarojo
    if (digitalRead(Infrarojo) == LOW) {
      // Si el pin Infrarojo está en BAJO, esperar 30 segundos y luego activar la alarma
      delay(30000);
      triggerAlarm();
    }
  }
}