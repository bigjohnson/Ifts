#define STRINGSIZE 10
char stringa[STRINGSIZE];
unsigned char posizione = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    char ricevuto = Serial.read();
    if (ricevuto != '\n' && posizione < ( STRINGSIZE - 1 ) ) {
      stringa[posizione] = ricevuto;
      stringa[posizione + 1] = '\0';
      posizione++;
    } else {
      Serial.println(stringa);
      if ( strcmp(stringa, "on") == 0 ) {
        Serial.println("Accendo");
        digitalWrite(LED_BUILTIN, HIGH);
      } else if ( strcmp(stringa, "off") == 0 ) {
        Serial.println("Spengo");
        digitalWrite(LED_BUILTIN, LOW);
      } else {
        Serial.println("Comando non riconosciuto.");
        Serial.println("on accende il led.");
        Serial.println("off spegne il led.");
      }
      posizione = 0;
      stringa[posizione] = '\0';
    }

  }
}
