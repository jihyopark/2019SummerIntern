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
int d = 0;
int n = 0;
int a1 = 0;

void loop() {
  
  if (Serial.available() > 0) {
    a1 = Serial.read() - 48;
    if (a1 == -38) {
      Serial.println(n);
      d = n;
      n = 0;
      a1 = 0;
      a = 0;
    }
    n *= 10;
    n += a1;
  }
  
  int pos = map(d, 0, 360, 0, 3200);
  if (a < pos) {
    digitalWrite(DIR,HIGH);
    digitalWrite(ENA,HIGH);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL,LOW);
    delayMicroseconds(50);
    a++;
  }
}
