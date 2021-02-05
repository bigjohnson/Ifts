void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( unsigned char carattere = 48; carattere <= 57; carattere ++) {
    Serial.print(carattere);
    Serial.print("\t");
    Serial.write(carattere);
    Serial.println();
  }
  while(true) {};
}
