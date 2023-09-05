// En base al circuito anterior hacer un programa que mediante un pulsador
// por flanco cambie paso a paso en un sentido entre los colores Rojo,
// Verde, Azul, Amarillo, Celeste, Violeta, Blanco y Apagado. Con un
// segundo pulsador realizar el paso a paso en sentido contrario.
//Rojo = 100
//Verde = 010
//Azul= 001
//Amarillo = 110
//Celeste = 011
//Violeta = 101
//Blanco = 111
// 100, 010, 001, 110, 011, 101, 111
//R = 1,4,6,7
//G = 2,4,5,7
//B= 3,5,6,7

#define RED 1
#define GREEN 2
#define BLUE 3
#define p1 4

bool p1_ant = 0
int n = 0
void setup() {
    pinMode(RED) ...
}

void loop() {
    if (p1 and !p1_ant)  {
        digitalWrite(RED, (n = 1 || n = 4 || n = 6 || n = 7));
        digitalWrite(GREEN, (n = 2 || n = 4 || n = 5 || n = 7));
        digitalWrite(BLUE, (n = 3 || n = 5 || n = 6 || n = 7));
        n++;
    }
}