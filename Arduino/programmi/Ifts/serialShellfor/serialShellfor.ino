#define LED LED_BUILTIN

void setup() {
  pinMode(LED, OUTPUT);
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  Serial.println("Accende e spegne il LED con la seriale.");
  Serial.println("s spegne il LED");
  Serial.println("a accende il LED");
  Serial.println("l lampeggia il LED per il numero di volte inserito.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    if ( 'a' == comando ) {
      digitalWrite(LED, HIGH);
      Serial.println("acceso");
    } else if ( 's' == comando ) {
      digitalWrite(LED, LOW);
      Serial.println("spento");
    } else if ( 'l' == comando ) {
      Serial.print("Lampeggia ");
      while (!Serial.available()) {
      };
      comando = Serial.read();
      if ( comando >= 49 && comando <= 57 ) {
        unsigned char volte = comando - 48;
        Serial.print(volte);
        Serial.println(" volte.");
        
          for ( unsigned char lampeggi = 0; lampeggi < volte; lampeggi++) {
            digitalWrite(LED, HIGH);
            Serial.println("acceso");
            delay(500);
            digitalWrite(LED, LOW);
            Serial.println("spento");
            delay(500);
          }
        } else {
          Serial.println("Parametro sbagliato, inserire numeri da 1 a 9");
        }
      } else {
        Serial.println("Parametro sbagliato, inserire numeri da 1 a 9");
      }
  }
}
