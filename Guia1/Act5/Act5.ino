/*

*/
int p1 = 2;
int p2 = 3;
int s1 = 9;
int s2 = 10;
int s3 = 11;
int s4 = 12;

void setup() {
    pinMode(2,INPUT);
    pinMode(3,INPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
}

void loop() {
  delay(150);
  digitalWrite(s1,HIGH);
  delay(150);
  digitalWrite(s1,LOW);
  digitalWrite(s2,HIGH);
  delay(150);
  digitalWrite(s3,HIGH);
  digitalWrite(s2,LOW);
  delay(150);
  digitalWrite(s3,LOW);
  digitalWrite(s4,HIGH);
  delay(150);
}
