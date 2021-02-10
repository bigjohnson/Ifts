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

// include the library code:
#include <LiquidCrystal.h>

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

unsigned long tempo;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //Serial.println(F("DHTxx test!"));
  lcd.setCursor(0, 0);
  lcd.print("DHT11 and LCD");
  dht.begin();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // Print a message to the LCD.

  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);

  if ((millis() - tempo) > 500) {
    tempo = millis();
    lcd.setCursor(0, 1);
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    lcd.print("H:");
    lcd.print(h);
    lcd.setCursor(8, 1);
    lcd.print("T:");
    lcd.print(t);
  }
}
