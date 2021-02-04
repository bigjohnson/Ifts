void setup() {
  // put your setup code here, to run once:
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // prints title with ending line break
  Serial.println("Accende e spegne il led con la seriale");
  Serial.println("1 accende il led");
  Serial.println("0 spegne il led");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    if ( '1' == comando ) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("led acceso");
    } else if ( '0' == comando ) {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("led spento");
    } else {
      Serial.println("comando non riconosciuto, inserire 0 o 1");
    }
  }
}
