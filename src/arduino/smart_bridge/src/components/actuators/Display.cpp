#include "Display.h"
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);


void Display::setup() 
{
  /* Wiring: SDA => A4, SCL => A5 */
  /* I2C address of the LCD: 0x27 */
  /* Number of columns: 20 rows: 4 */
  lcd.init();
  lcd.backlight();
}

void Display::showText(Message message) 
{
  // Set the cursor on the third column and first row.
  lcd.clear();
  lcd.backlight();

  switch (message)
  {
    case MSG_WELCOME:
      lcd.setCursor(4, 0);
      lcd.print("Welcome");
      break;
    case MSG_PROCEED:
      lcd.setCursor(1, 0);
      lcd.print("Proceed to the");
      lcd.setCursor(2, 1);
      lcd.print("Washing Area");
      break;
    case MSG_READY:
      lcd.setCursor(1, 0);
      lcd.print("Ready to Wash");
      break;
    case MSG_COMPLETE1:
      lcd.setCursor(0, 0);
      lcd.print("Washing complete.");
      break;
    case MSG_COMPLETE2:
      lcd.setCursor(1, 0);
      lcd.print("You can leave");
      lcd.setCursor(3, 1);
      lcd.print("the area.");
      break;
    case MSG_PROBLEM1:
      lcd.setCursor(2, 0);
      lcd.print("Detected a");
      lcd.setCursor(4, 1);
      lcd.print("Problem");
      break;
    case MSG_PROBLEM2:
      lcd.setCursor(2, 0);
      lcd.print("Please Wait");
      break;
  }
}

void Display::turnOff() {
  lcd.noBacklight();
  lcd.clear();
}