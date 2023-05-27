#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
void setup(){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

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
void loop() {
  for(int i = 0;i<=9;i++) {
    disp7seg(i);
    delay(1000);
  }
}