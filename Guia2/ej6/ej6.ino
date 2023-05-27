// Utilizando como modelo el ejercicio 4, deberá modificarse para que cada vez que se presione el pulsador (p1)
// la cuenta se incremente de 0 hasta 9 y después de 9 hasta 0. Es decir que cada vez que se presione el pulsador 
// el número debe realizar la secuencia 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0…….
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define p1 9
bool estadoAnterior;
int avance = 1;
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

void setup(){
  pinMode(p1,INPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

int i = 0;

void loop() {
  bool estado = digitalRead(p1);
  if (estado and !estadoAnterior) {
    disp7seg(i);
    i=i+avance;
    if (i=9){
      avance = -1;
    }
    if (i=0){
      avance = 1;
    }
  }
}
