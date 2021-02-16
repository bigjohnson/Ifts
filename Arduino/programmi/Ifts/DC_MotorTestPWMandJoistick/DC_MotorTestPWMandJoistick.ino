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
#define TOLLERANZA 2

const int X_pin = 0; // analog pin connected to X output

int i;

void setup() {
  //---set pin direction
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  //Serial.begin(9600);
  digitalWrite(DIRA, HIGH); //one way
  digitalWrite(DIRB, LOW);
  //Serial.println("joya\tjoyb\tspeed");
}

void loop() {
  //Serial.println("PWM speed test");
  //Serial.println("Avanti");
  unsigned int joy = analogRead(X_pin);
  if ( joy > ( 513 + TOLLERANZA ) ) {
    //Serial.print(joy);
    //Serial.print("\t");
    joy = joy - 512;
    //Serial.print(joy);
    //Serial.print("\t");
    unsigned char speed = map(joy, 0, 511, 0, 255);
    digitalWrite(DIRA, LOW); //one way
    digitalWrite(DIRB, HIGH);
    analogWrite(ENABLE, speed);
    //Serial.println(speed);
  } else if ( joy < (513 - TOLLERANZA) ) {
    //Serial.print(joy);
    //Serial.print("\t");
    joy = 511 - joy;
    //Serial.print(joy);
    //Serial.print("\t");
    unsigned char speed = map(joy, 0, 511, 0, 255);
    digitalWrite(DIRA, HIGH); //one way
    digitalWrite(DIRB, LOW);
    analogWrite(ENABLE, speed);
    //Serial.println(speed);
  } else {
    analogWrite(ENABLE, 0);
  }
  //delay(100);
}
