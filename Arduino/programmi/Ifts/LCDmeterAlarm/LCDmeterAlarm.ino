//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

  Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
   LCD RS pin to digital pin 7
   LCD Enable pin to digital pin 8
   LCD D4 pin to digital pin 9
   LCD D5 pin to digital pin 10
   LCD D6 pin to digital pin 11
   LCD D7 pin to digital pin 12
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  Library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  Example added 9 Jul 2009
  by Tom Igoe
  Modified 22 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

#define DISTANZA_MINIMA 50

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

unsigned long tempo;
unsigned char blink;

#include "SR04.h";
#define TRIG_PIN 5
#define ECHO_PIN 6
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);//Initialization of Serial Port
  delay(1000);
}

void loop() {
  if ((millis() - tempo) > 500) {
    tempo = millis();
    lcd.setCursor(15, 0);
    if ( blink ) {
      lcd.print(".");
      blink = false;
    } else {
      lcd.print(" ");
      blink = true;
    }
    float distanza = 0;
    const unsigned char media = 10;
    for (unsigned char i = 0; i < media; i++) {
      distanza += sr04.Distance();
    }
    distanza /= media;
    lcd.setCursor(0, 0);
    lcd.print(distanza, 0);
    lcd.print(" cm  ");
    Serial.println(distanza);
    if ( distanza < DISTANZA_MINIMA ) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // Print a message to the LCD.

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
