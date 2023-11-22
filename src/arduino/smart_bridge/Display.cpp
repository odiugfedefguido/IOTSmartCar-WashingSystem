#include "Display.h"
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void Display::init() {
  /* Wiring: SDA => A4, SCL => A5 */
  /* I2C address of the LCD: 0x27 */
  /* Number of columns: 20 rows: 4 */
  lcd.init();
  lcd.backlight();
}

void Display::showText(char *text) {
  // Set the cursor on the third column and first row.
  lcd.setCursor(2, 1); 
  lcd.print(text);
}