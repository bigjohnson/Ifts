//www.elegoo.com
//2016.12.12

/************************
  Exercise the motor using
  the L293D chip
************************/

#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define MIN_SPEED 60

const int X_pin = 0; // analog pin connected to X output

int i;

void setup() {
  //---set pin direction
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
  digitalWrite(DIRA, HIGH); //one way
  digitalWrite(DIRB, LOW);
  analogWrite(ENABLE, 255);
  delay(20);
  Serial.println("speed");
}

void loop() {
  //Serial.println("PWM speed test");
  //Serial.println("Avanti");
  unsigned int joy = analogRead(X_pin);
  if ( joy > 515 ) {
    joy = joy - 514;
    unsigned char speed = map(joy, 0, 514, 0, 255);
    digitalWrite(DIRA, LOW); //one way
    digitalWrite(DIRB, HIGH);
    analogWrite(ENABLE, speed);
    Serial.println(speed);
  } else if ( joy < 509 ) {
    joy = 510 - joy;
    unsigned char speed = map(joy, 0, 514, 0, 255);
    digitalWrite(DIRA, HIGH); //one way
    digitalWrite(DIRB, LOW);
    analogWrite(ENABLE, speed);
    Serial.println(speed);
  } else {
    analogWrite(ENABLE, 0);
  }
  delay(100);
}
