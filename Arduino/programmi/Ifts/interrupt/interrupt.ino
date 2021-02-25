const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink1, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
  noInterrupts();
#codice che non deve essere interrotto
  interrupts();
}

void blink1() {
  noInterrupts();
  state = !state;
  interrupts();
}
