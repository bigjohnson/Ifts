#define LED LED_BUILTIN

void setup() {
  pinMode(LED, OUTPUT);
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  Serial.println("Accende e spegne il LED con la seriale");
  Serial.println("0 spegne il LED");
  Serial.println("1 accende il LED");
  Serial.println("2 lampeggia il LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    if ( '1' == comando ) {
      digitalWrite(LED, HIGH);
      Serial.println("Acceso");
    } else if ( '0' == comando ) {
      digitalWrite(LED, LOW);
      Serial.println("Spento");
    } else if ( '2' == comando ) {
      Serial.print("Lampeggia: ");
      digitalWrite(LED, HIGH);
      Serial.print("acceso, ");
      delay(500);
      digitalWrite(LED, LOW);
      Serial.print("spento, ");
      delay(500);
      digitalWrite(LED, HIGH);
      Serial.println("acceso");
      delay(500);
    } else {
      Serial.println("Comando non riconosciuto. Inserire 0 o 1!");
    }
  }
}
