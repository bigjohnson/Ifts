#define LED_start 2
#define LED_end 9

void setup() {

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  for ( unsigned char led = LED_start; led <= LED_end; led++) {
    pinMode(led, OUTPUT);
    //Serial.println(led);
  }
  Serial.println("Accende e spegne i LED da 2 a 9 con la seriale");
  Serial.println("0 spegne il LED");
  Serial.println("1 accende il LED");
  Serial.println("aggiungere il led da 2 a 9");
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean stato;
  boolean errore = false;
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    if ( 'a' == comando ) {
      //digitalWrite(LED, HIGH);
      Serial.println("Quale led accendo?");
      stato = HIGH;
    } else if ( 's' == comando ) {
      //digitalWrite(LED, LOW);
      stato = LOW;
      Serial.println("Quale led spengo?");
    } else {
      Serial.println("Comando non riconosciuto. Inserire a o s!");
      errore = true;
    }

    while (!Serial.available()) {
    };

    unsigned char led = Serial.read() - 48;
    if ( led < 2 || led > 9) {
      errore = true;
      Serial.println("led non riconosciuto. Inserire numeri da 2 a 9");
    }

    if ( !errore ) {
      {
        Serial.print("Led ");
        Serial.print(led);
        digitalWrite(led, stato);
        if (stato) {
          Serial.println(" acceso.");
        } else {
          Serial.println(" spento");
        }
      }
    }
  }
}
