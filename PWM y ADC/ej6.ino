// Investigar el sensor LM35, conectar y programar una función que lea la
// entrada del sensor y muestre en grados centígrados por medio del
// puerto serie el valor de la temperatura.
#define lm35 A1 //define solo toma valores numericos
int temp_adc;
float temp;

void setup() {
    Serial.begin(9600);
}

void loop() {
    temp_adc = analogRead(lm35);
    temp = ((temp_adc * 4.88 )/ 10);
    Serial.println("Temperatura = ");
    Serial.print(temp);   
    Serial.print(" Grados Celsius");
    delay(1000);
}