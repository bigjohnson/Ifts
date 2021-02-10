// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
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
    lcd.setCursor(0, 1);
    lcd.print("                ");
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(stringa);
  }

  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}
