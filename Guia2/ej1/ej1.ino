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

  void cero() {
    digitalWrite(a,1); //a,b,c,d,e,f
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void uno(){
    digitalWrite(a,1); //b,c
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void dos() {
    digitalWrite(a,1); //a,b,g,e,d
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void tres() {
    digitalWrite(a,1); //a,b,g,c,d
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void cuatro() {
    digitalWrite(a,1); //b,g,c,f
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void cinco() {
    digitalWrite(a,1); //a,c,d,g,f
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void seis() {
    digitalWrite(a,1); //c,d,e,f,g
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void siete() {
    digitalWrite(a,1); //a,b,c
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void ocho(){
    digitalWrite(a,1); //a,b,c,d,e,f,g
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  void nueve() {
    digitalWrite(a,1); //a,b,c,f,g
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }

void loop() {
  for(int i = 0;i<=9;i++) {
    switch (i) {
      case 0:
        cero();
      case 1:
        uno();
      case 2:
        dos();
      case 3:
        tres();
      case 4:
        cuatro();
      case 5:
        cinco();
      case 6:
        seis();
      case 7:
        siete();
      case 8:
        ocho();
      case 9:
        nueve();
    }
    delay(1000);
  }
}
