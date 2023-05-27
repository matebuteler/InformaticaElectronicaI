
//Crear un algoritmo para un Arduino conectado a un display 7 segmentos y un parlante el cual mediante dos botones implementados por "click" permita realizar las siguientes tareas:
//1. Botón 1: al presionar debe incrementar la cuenta en 1 que se ve en el display hasta un máximo de 9. Si la cuenta se pasa de tal valor el número debe comenzar nuevamente en 0.
//2. Botón 2: al presionar el display debe automáticamente comenzar a realizar una cuenta regresiva desde el valor que quedó seteado en el display hasta llegar a 0.
//3. al terminar la cuenta regresiva debe sonar la alarma 5 veces para indicar que terminó la cuenta y quedar listo para volver a setear la nueva cuenta del punto 1.
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8 
#define buzzer 9
bool estado1_anterior;
bool estado2_anterior;
void disp7seg(int n){
  // se asegura de que todos los pines estén en 0
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  
  if (n!=1 and n!=6) {
    digitalWrite(a,1);
  }
  if (n!=5 and n!=6) {
    digitalWrite(b,1);
  }
  if (n!=2) {
    digitalWrite(c,1);
  }
  if (n!=1 and n!=4 and n!=7 and n!=9) {
    digitalWrite(d,1);
  }
  if (n!=1 and n!=3 and n!=4 and n!=5 and n!=7 and n!=9) {
    digitalWrite(e,1);
  }
  if (n!=1 and n!=2 and n!=3 and n!=7){
    digitalWrite(f,1);
  }
  if (n!= 0 and n!=1 and n!=7) {
    digitalWrite(g,1);
  }
}

void setup(){
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
}

int n = 0; // n being the value that is added to the int shown on the display. can be either 1 or -1, switches to positive 1 when button 1 is pressed and to negative 1 when button 2 is pressed
int i = 0 ;// i being the value that is shown on the display. can be any number between 0 and 9
void loop(){
    bool estado1 = digitalRead(2);
    bool estado2 = digitalRead(3);
    if (estado1 and !estado1_anterior) {
        n = 1;
    }
    if (estado2 and !estado2_anterior) {
        n = -1;
    }
    if (i + n > 9) {
        i = 0;
    }
    if (i + n < 0) {
      for (int j = 0; j < 5; j++) {
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        delay(200);
      }
      i = 9;
    }
    i = i + n;
    disp7seg(i);
    estado1_anterior = estado1;
    estado2_anterior = estado2;
    delay(1000);
}