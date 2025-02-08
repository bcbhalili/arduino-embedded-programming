#include <LiquidCrystal.h>

/*
	File Name:			  POTInterfacing.ino
	Date Created:   	February 8, 2025
    Embedded Engineer:  Bien Carlo Halili
    Project Description:
    	This project demonstrates a potentiometer for analog input then an LCD for output.
*/

// LCD Constants
#define RS_PIN 12
#define EN_PIN 11
#define D4_PIN 5
#define D5_PIN 4
#define D6_PIN 3
#define D7_PIN 2
#define CHARACTER_PER_LINE 16
#define MAX_LINES 2
// Potentiometer Constant
#define POT_PIN A0
// Potentiometer Variable
int potValue = 0;
// LCD Object Declaration
LiquidCrystal lcd(RS_PIN,
                  EN_PIN,
                  D4_PIN,
                  D5_PIN,
                  D6_PIN,
                  D7_PIN);

void displayText(int line, char text[])
{
  lcd.setCursor(0, line);
  lcd.print(text);
}
void displayText(int line, int value)
{
  lcd.setCursor(0, line);
  lcd.print(value);
}

void setup()
{
  // Set up the display dimenstions of LCD
  lcd.begin(CHARACTER_PER_LINE,
           MAX_LINES);
  // Set the start display in the LCD
  displayText(0, "Initializing...");
  delay(3000);
}

void loop()
{
  potValue = analogRead(POT_PIN);
  lcd.clear();
  displayText(0, "POT Value:");
  displayText(1, potValue);
  delay(100);
}