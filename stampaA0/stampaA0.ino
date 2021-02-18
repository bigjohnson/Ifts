int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  //if (Serial.availableForWrite()) {
    Serial.println(val * (5.0 / 1023.0), 3); // debug value
    //delay(500);
  //}
}
