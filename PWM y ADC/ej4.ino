// Investigar y conectar un sensor fotosensible tipo LDR. Realizar un
// algoritmo que realice la medición de luz y mostrar el valor del ADC en el
// monitor serie.

void setup() {
    Serial.begin(9600);
}

void loop() {
    int valor = analogRead(A3);
    Serial.println(valor);
    delay(100);
}