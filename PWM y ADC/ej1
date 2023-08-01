// Conectar un potenciómetro al puerto A3 y realizar un algoritmo que lea y
// muestre el valor de dicho puerto por el puerto Serie. Variar el
// potenciómetro para tal fin.

void setup() {
    Serial.begin(9600);
}
int valor;
int valor_anterior;
void loop() {
    valor = analogRead(A3);
    if (valor != valor_anterior) {
        Serial.print("Valor: ");
        Serial.println((valor * 5) / 1023) + "V";
    }
    delay(100);
    valor_anterior = valor;
}
