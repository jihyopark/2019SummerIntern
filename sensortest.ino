int echo1 = A0;
int trig1 = A1;
int echo2 = A5;
int trig2 = A4;

void setup() {
  // put your setup code here, to run once:
  pinMode (echo1, INPUT);
  pinMode (trig1, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trig2, OUTPUT);

  Serial.begin(9600);
}

unsigned int duration1;
double cm1;

unsigned int duration2;
double cm2;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig1, LOW);
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  cm1 = (duration1/2) / 29.1;
  
  digitalWrite(trig2, LOW);
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  
  duration2 = pulseIn(echo2, HIGH);

  cm2 = (duration2/2) / 29.1;
  
  Serial.println(cm1);
  Serial.println(cm2);
  delay(500);

}
