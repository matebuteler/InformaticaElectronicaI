
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

void disp7seg(int n) {
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

void setup {
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
}

void loop {
    bool estado1 = digitalRead(2);
    bool estado2 = digitalRead(3);
    if (estado1 == HIGH) {
        for (int i = 0; i < 10; i++) {
            disp7seg(i);
            delay(1000);
        }
    }
    if (estado2 == HIGH) {
        for (int i = 9; i >= 0; i--) {
            disp7seg(i);
            delay(1000);
        }
    }
}