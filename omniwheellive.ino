
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
  
  Serial.begin(9600);
}

int s1 = 100;
int s2 = 100;
int s3 = 100;
int s4 = 100;

void forward() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, s4);
}

void backward() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, s4);
}

void right() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, s4);
}

void left() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, s4);
}

void stop() {
  analogWrite (ENA1,0);
  analogWrite (ENA2,0);
  analogWrite (ENA3,0);
  analogWrite (ENA4,0);
}

void nw() {
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, s4);

  analogWrite (ENA1,0);
  analogWrite (ENA3,0);
}

void sw() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, s3);

  analogWrite (ENA2,0);
  analogWrite (ENA4,0);
}

void ne() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, s3);

  analogWrite (ENA2,0);
  analogWrite (ENA4,0);
}

void se() {
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, s4);

  analogWrite (ENA1,0);
  analogWrite (ENA3,0);
}

void turnRight() {
  digitalWrite (IN11, HIGH);
  digitalWrite (IN21, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN22, HIGH);
  digitalWrite (IN12, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN23, HIGH);
  digitalWrite (IN13, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN14, HIGH);
  digitalWrite (IN24, LOW);
  analogWrite (ENA4, s4);
}

void turnLeft() {
  digitalWrite (IN21, HIGH);
  digitalWrite (IN11, LOW);
  analogWrite (ENA1, s1);
  
  digitalWrite (IN12, HIGH);
  digitalWrite (IN22, LOW);
  analogWrite (ENA2, s2);
  
  digitalWrite (IN13, HIGH);
  digitalWrite (IN23, LOW);
  analogWrite (ENA3, s3);
  
  digitalWrite (IN24, HIGH);
  digitalWrite (IN14, LOW);
  analogWrite (ENA4, s4);
}

int b = 0;

void loop() {
  if (Serial.available() > 0) {
    b = Serial.read();
  }
  if (b == 119) { // w
    forward();
    Serial.println("w");
  }
  if (b == 97) { // a
    left();
    Serial.println("a");
  }
  if (b == 115) { // s
    backward();
    Serial.println("s");
  }
  if (b == 100) { //d
    right();
    Serial.println("d");
  }
  if (b == 32) { // spacebar
    stop();
    Serial.println("spacebar");
  }
  if (b == 93) { // ] speed up
    Serial.println("speed up");
    s1 += 5;
    s2 += 5;
    s3 += 5;
    s4 += 5;
  }
  if (b == 91) { // [ speed down
    Serial.println("speed down");
    s1 -= 5;
    s2 -= 5;
    s3 -= 5;
    s4 -= 5;
  }
  if (b == 113) { //q
    nw();
    Serial.println("q");
  }
  if (b == 101) { //e
    ne();
    Serial.println("e");
  }
  if (b == 122) { //z
    sw();
    Serial.println("z");
  }
  if (b == 120) { //x
    se();
    Serial.println("x");
  }
  if (b == 39) { // ' right turn
    turnRight();
    Serial.println("right turn");
  }
  if (b == 59) { // ; left turn
    turnLeft();
    Serial.println("left turn");
  }
  
}
