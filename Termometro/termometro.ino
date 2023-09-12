// 1. Por medio del conversor ADC del Arduino, medir la temperatura a través de un sensor LM35. 
// 2. Mostrar por el puerto serie la medición en °C 
// 3. Mostrar la medición en un par de displays 7 segmentos. 
// 4. Con un pulsador se debe poder cambiar el valor mostrado entre °C y °F, tal valor se debe reflejar tanto
// en los display 7 segmentos como en la información arrojada por el puerto serie. 

// Nota: en caso de superar el valor de 100 grados, tanto °C como °F, debe encenderse un led para indicar tal situación
// y en los display seguir mostrando la unidad y decena del valor. Para testeo hacer que esa temperatura maxima sea medible para probar la función

// Modificar el programa anterior agregando una función para que muestre
// la temperatura por medio de los display 7 segmentos. Realizar otra
// función que encienda un led cuando la temperatura supere los 28C.

#define LED_a 6
#define LED_b 7
#define LED_c 8
#define LED_d 2 //9 no anda
#define LED_e 10
#define LED_f 11
#define LED_g 12
#define com1 4
#define com2 5
#define p1 13
#define LED_100 3
// lm35 está en A3
#include <Arduino.h>
float temp;
bool p1_ant;
bool celsius = 1;

void setup() {
    pinMode(LED_a,OUTPUT);
    pinMode(LED_b,OUTPUT);
    pinMode(LED_c,OUTPUT);
    pinMode(LED_d,OUTPUT);
    pinMode(LED_e,OUTPUT);
    pinMode(LED_f,OUTPUT);
    pinMode(LED_g,OUTPUT);
    pinMode(com1,OUTPUT);
    pinMode(com2,OUTPUT);
    pinMode(LED_100, OUTPUT);
    Serial.begin(9600);
}

void disp7seg(int n){
  digitalWrite(LED_a, (n != 1 && n != 6 && n != 4));
  digitalWrite(LED_b, (n != 5 && n != 6));
  digitalWrite(LED_c, (n != 2));
  digitalWrite(LED_d, (n != 1 && n != 4 && n != 7 && n != 9));
  digitalWrite(LED_e, (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9));
  digitalWrite(LED_f, (n != 1 && n != 2 && n != 3 && n != 7));
  digitalWrite(LED_g, (n != 0 && n != 1 && n != 7));
}

void multiplex(int n) { //com1 = decena, com2 = unidad
    int decena = n/10;
    int unidad = n%10;
    digitalWrite(com2, HIGH); // apaga display de la unidad
    disp7seg(decena);	   // muestra decena
    digitalWrite(com1, LOW); // enciende display decena
    delay(4);  
    digitalWrite(com1, HIGH); // apaga display decena
    disp7seg(unidad);	    // muestra unidad
    digitalWrite(com2, LOW); // enciende display unidad
    delay(4);
}


void loop() {
    
    temp = ((analogRead(A3) * 4.9 )/ 10); //4.9mv es la resolucion del arduino (5v / 1024)

    if (celsius) {
        multiplex(temp);
        Serial.println(temp);
    } else {
        multiplex(temp*1.8 + 32);
        Serial.println(temp*1.8 + 32);
    }

    if (p1 and !p1_ant) celsius = !celsius;
    if (temp > 100) digitalWrite(LED_100, 1);
    delay(100);
    p1_ant = p1;
}