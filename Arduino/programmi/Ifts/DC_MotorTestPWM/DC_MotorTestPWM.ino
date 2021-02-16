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
  digitalWrite(DIRA, HIGH); //one way
  digitalWrite(DIRB, LOW);
  for (unsigned char speed = MIN_SPEED; speed < 255 ; speed++) {
    analogWrite(ENABLE, speed); //enable on
    Serial.println(speed);
    delay(100);
  }
  //Serial.println("Indietro");
  digitalWrite(DIRA, HIGH); //one way
  digitalWrite(DIRB, LOW);
  for (unsigned char speed = 255; speed > MIN_SPEED ; speed--) {
    analogWrite(ENABLE, speed); //enable on
    Serial.println(speed);
    delay(100);
  }
}
