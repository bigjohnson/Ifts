// include the library code:
#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  lcd.begin(16, 2);
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("inserisci una stringa di massimo 16 caratteri");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String stringa = Serial.readString();
    Serial.println(stringa);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(stringa);
  }

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
