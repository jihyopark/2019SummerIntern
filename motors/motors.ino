int led1 = 6;
int led2 = 5;
int a = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (a, INPUT);
  Serial.begin (9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead (a) == 1){
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
  }
  else {
    digitalWrite (led1, LOW);  
    digitalWrite (led2, HIGH);
  }
  Serial.println(digitalRead (a));
}
