#define a 7
#define b 6
#define c 8
#define d 9
#define e 10
#define f 11
#define g 12

bool estadoAnteriorp2 = 0;
bool estadoAnteriorp3 = 0;
bool on = true;

void disp7seg(char seg) { //function to turn on a specific segment of the display while turning all of the other segments off
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
    switch (seg) {
        case 'a':
            digitalWrite(a,1);
            break;
        case 'b':
            digitalWrite(b,1);
            break;
        case 'c':
            digitalWrite(c,1);
            break;
        case 'd':
            digitalWrite(d,1);
            break;
        case 'e':
            digitalWrite(e,1);
            break;
        case 'f':
            digitalWrite(f,1);
            break;
        case 'g':
            digitalWrite(g,1);
            break;
    }
}

void setup() {
    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
    pinMode(e,OUTPUT);
    pinMode(f,OUTPUT);
    pinMode(g,OUTPUT);
    pinMode(2,INPUT);
    pinMode(3,INPUT);
}

void loop() {
    // Snake sequence (clockwise): a, f, g, c, d, e, g, b
    // Snake sequence (counterclockwise): a, b, g, e, d, c, g, f
    int viborita [16] = {a, f, g, c, d, e, g, b, a, b, g, e, d, c, g, f}; //del 1-8 = clockwise, del 8-16 = counterclockwise
    bool estado2 = digitalRead(2);
    bool estado3 = digitalRead(3);
    bool sentido = true; //true = clockwise, false = counterclockwise
    if (on) {
        if (sentido) {
            for (int i = 0; i < 8; i++) {
                disp7seg(viborita[i]);
                delay(100);
            }
        } else {
            for (int i = 8; i < 16; i++) {
                disp7seg(viborita[i]);
                delay(100);
            }
        } 
    }

    if (estado2 and !estadoAnteriorp2) { //alt display rotation
        sentido = !sentido;
    }
    if (estado3 and !estadoAnteriorp2) { //switch display on or off
        on = !on;
    }    
    estadoAnteriorp2 = estado2;
    estadoAnteriorp3 = estado3;
}