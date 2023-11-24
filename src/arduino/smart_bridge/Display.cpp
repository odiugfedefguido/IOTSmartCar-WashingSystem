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

  switch (message)
  {
    case WELCOME:
      lcd.setCursor(4, 1);
      lcd.print("Welcome");
      break;
    case PROCEED:
      lcd.setCursor(1, 0);
      lcd.print("Proceed to the");
      lcd.setCursor(2, 1);
      lcd.print("Washing Area");
      break;
    case READY:
      lcd.setCursor(4,1);
      lcd.print("Ready to Wash");
      break;
    case COMPLETE:
      lcd.print("Washing complete, you can leave the area");
      break;
    case PROBLEM:
      lcd.print("Detected a Problem - Please Wait");
      break;
  }
}