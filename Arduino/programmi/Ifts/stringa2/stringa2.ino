#define STRINGSIZE 10
String stringa = String();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    char ricevuto = Serial.read();
    if (ricevuto != '\n' && stringa.length() < STRINGSIZE ) {
      stringa += ricevuto;
    } else if ( ricevuto == '\n' && stringa.length() > 0 ) {
      Serial.println(stringa);
      if ( stringa == "on" ) {
        Serial.println("Accendo");
        digitalWrite(LED_BUILTIN, HIGH);
      } else if ( stringa == "off" ) {
        Serial.println("Spengo");
        digitalWrite(LED_BUILTIN, LOW);
      } else {
        Serial.println("Comando non riconosciuto.");
        Serial.println("on accende il led.");
        Serial.println("off spegne il led.");
      }
      stringa = "";
    }

  }
}
