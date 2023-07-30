//#include <LCD.h>
//#include <LiquidCrystal_I2C.h>
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

#define MAX_COUNT  24
#define MIN_COUNT   0

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
//LiquidCrystal_I2C lcd(0x27, 20, 4);

int count = MAX_COUNT;

void setup()
{
  lcd.begin(20, 4);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  delay(5000);

  Serial.begin(9600);
  Serial.println("Setup done.");
}

void loop()
{
  if (count < MIN_COUNT) count = MAX_COUNT;
  lcd.clear();
  lcd.print(count);
  lcd.setCursor(0, 3);
  lcd.print("01234567890123456789");
  delay(1000);
  count--;
}

/* #include <Wire.h> // For communication purposes of I2C
#include <LiquidCrystal_I2C.h> // Main library that does the job

LiquidCrystal_I2C lcd(0x27, 20, 4); // Set the LCD address to 0x27 for a 20 chars and 4 line display

void setup()
{
  
  // Initialize the LCD
  lcd.begin();
  //lcd.noBacklight();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");

  Serial.begin(9600); // Initialize serial and wait for port to open
  delay(1500); // This delay gives the chance to wait for a Serial Monitor without blocking if none is found

  Serial.println("Setting LCD ...");

  lcd.clear();
  lcd.print("AutorTech");
  lcd.setCursor(0,1); // go to start of 2nd line
  lcd.print("Hello World!");
  delay(1000);
 
  Serial.println("Done");

}

void loop() 
{
  //Serial.println("Looping...");

}*/
