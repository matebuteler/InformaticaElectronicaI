/*

*/
int p1 = 2;
int s1 = 9;
boolean pa = 0;
boolean p = 0;
boolean led = 0;
char puls = 0; // pulsaciones

void setup() {
    pinMode(2,INPUT);
    pinMode(9,OUTPUT);
}

void loop() {
  p = digitalRead(p1);
  
  if (pa == 0 && p == 1) {
    puls += 1;
  }
  
  if (puls == 4) {
    led = !led;
  }
  
  if (puls == 5) {
    led = !led;
    puls = 0;
  }
  
  digitalWrite(s1,led); // 
  pa = p;
}