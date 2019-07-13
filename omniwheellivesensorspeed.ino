int ENA1 = 3;
int IN11 = 4;
int IN21 = 2;

int ENA2 = 5;
int IN12 = 7;
int IN22 = 6;

int ENA3 = 11;
int IN13 = 12;
int IN23 = 13;

int ENA4 = 10;
int IN14 = 9;
int IN24 = 8;

int echo1 = A0;
int trig1 = A1;
int echo2 = A5;
int trig2 = A4;

void setup() {
  pinMode (ENA1, OUTPUT);
  pinMode (IN11, OUTPUT);
  pinMode (IN21, OUTPUT);
  
  pinMode (ENA2, OUTPUT);
  pinMode (IN12, OUTPUT);
  pinMode (IN22, OUTPUT);
  
  pinMode (ENA3, OUTPUT);
  pinMode (IN13, OUTPUT);
  pinMode (IN23, OUTPUT);
  
  pinMode (ENA4, OUTPUT);
  pinMode (IN14, OUTPUT);
  pinMode (IN24, OUTPUT);

  pinMode (echo1, INPUT);
  pinMode (trig1, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trig2, OUTPUT);
  
  Serial.begin(9600);
}

double s = 70;
double st1 = 50;
double st2 = 50;

void forward() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, s);
  
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, s * (17.0/14));
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, s);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, s * (17.0/14));
}

void backward() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, s);
  
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, s * (17.0/14));
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, s);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, s * (17.0/14));
}

void stop() {
  analogWrite (ENA1,0);
  analogWrite (ENA2,0);
  analogWrite (ENA3,0);
  analogWrite (ENA4,0);
}

void turnRight() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, st2);
  
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, st2 * (17.0/14));
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, st2);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, st2 * (17.0/14));
}

void turnLeft() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, st1);
  
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, st1 * (17.0/14));
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, st1);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, st1 * (17.0/14));
}

void move() {
  
}

unsigned int duration1;
double cm1;
double cmf1;

unsigned int duration2;
double cm2;
double cmf2;

double cm1t;
double cm2t;

int a = 0;
int b = 0;

double avg1[20];
double avg2[20];

double P;
double I;
double I1;
double I2;

void loop() {
  digitalWrite(trig1, LOW);
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  cmf1 = (duration1/2) / 29.1;

  delay(4);

  if (cm1 > 400) {
    cm1 = cm1t;
  }

  if (a < 20) {
    avg1[a] = cmf1;
    cm1 = cmf1;
  }
  else {
    for (int i = 0; i < 19; i++) {
      avg1[i] = avg1[i + 1];
    }
    avg1[19] = cmf1;
  
    cm1 = (avg1[0] + avg1[1] + avg1[2] + avg1[3] + avg1[4] + avg1[5] + avg1[6] + avg1[7] + avg1[8] + avg1[9] + 
    avg1[10] + avg1[11] + avg1[12] + avg1[13] + avg1[14] + avg1[15] + avg1[16] + avg1[17] + avg1[18] + avg1[19]) / 20;
  }
  
  digitalWrite(trig2, LOW);
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  cmf2 = (duration2/2) / 29.1;
  
  delay(4);

  if (cm2 > 400) {
    cm2 = cm2t;
  }
  
  if (a < 20) {
    avg2[a] = cmf2;
    cm2 = cmf2;
  }
  else {
    for (int i = 0; i < 19; i++) {
      avg2[i] = avg2[i + 1];
    }
    avg2[19] = cmf2;
  
    cm2 = (avg2[0] + avg2[1] + avg2[2] + avg2[3] + avg2[4] + avg2[5] + avg2[6] + avg2[7] + avg2[8] + avg2[9] + 
    avg2[10] + avg2[11] + avg2[12] + avg2[13] + avg2[14] + avg2[15] + avg2[16] + avg2[17] + avg2[18] + avg2[19]) / 20;
  }
  
//  Serial.println(cm1); // right
//  Serial.println(cm2);

  P = (cm1 + cm2) / 2.0 - 10 + 50;
  
  if (I < 50 && cm1 < 70 && cm2 < 70) {
      I += (((cm1 + cm2) / 2.0) - 10) / 20;
      I1 += (cm1 - cm2) / 60;
      I2 += (cm2 - cm1) / 60;
  }

  if (P < 50 && P > -50) {
    P = 50;
  }
  
  if (!(cm1 > 70 && cm2 > 70)) {
    s = P + I;
    st1 = (P / 10) + (I1 * 0.8);
    st2 = (P / 10) + (I2 * 0.8);
  }

  if (cm1 > 9 && cm1 < 11 && cm2 > 9 && cm2 < 11) {
    stop();
    I = 0;

  }
  else if (cm1 > 70 && cm2 > 70) {
    forward();
  }
  else {
    if (cm1 < 7 || cm2 < 7) {
      backward();
    }
    else if (cm1 - cm2 > 1) {
      turnLeft();
    }
    else if (cm2 - cm1 > 1) {
      turnRight();
    }
    else {
      forward();
    }
  }
  cm1t = cm1;
  cm2t = cm2;

//  Serial.println(s);
  Serial.println(I);

  a++;
}
