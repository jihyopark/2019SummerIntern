int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
int s1 = A0;
int s2 = A1;

int PUL2=10; //define Pulse pin2
int DIR2=9; //define Direction pin2
int ENA2=8; //define Enable Pin2


void setup() {
pinMode (PUL, OUTPUT);
pinMode (DIR, OUTPUT);
pinMode (ENA, OUTPUT);
pinMode (s1, INPUT);

pinMode (PUL2, OUTPUT);
pinMode (DIR2, OUTPUT);
pinMode (ENA2, OUTPUT);
pinMode (s2, INPUT);


Serial.begin(9600);

}

int a = 0;
int b = 0;

void loop() {
int pos = map(analogRead(s1), 0, 1023, 0, 3200);

int pos2 = map(analogRead(s2), 0, 1023, 0, 3200);

if (a < pos - 24) {
digitalWrite(DIR,HIGH);
digitalWrite(ENA,HIGH);
digitalWrite(PUL,HIGH);
delayMicroseconds(30);
digitalWrite(PUL,LOW);
delayMicroseconds(30);
a++;
}
else if (pos + 24 < a) {
digitalWrite(DIR,LOW);
digitalWrite(ENA,HIGH);
digitalWrite(PUL,HIGH);
delayMicroseconds(30);
digitalWrite(PUL,LOW);
delayMicroseconds(30);
  a--;
}
delayMicroseconds(30);

if (b < pos2 - 24) {
digitalWrite(DIR2,LOW);
digitalWrite(ENA2,HIGH);
digitalWrite(PUL2,HIGH);
delayMicroseconds(30);
digitalWrite(PUL2,LOW);
delayMicroseconds(30);
b++;
}
else if (pos2 + 24 < b) {
digitalWrite(DIR2,HIGH);
digitalWrite(ENA2,HIGH);
digitalWrite(PUL2,HIGH);
delayMicroseconds(30);
digitalWrite(PUL2,LOW);
delayMicroseconds(30);
b--;
}
delayMicroseconds(30);

//Serial.println(analogRead(s1));

}
