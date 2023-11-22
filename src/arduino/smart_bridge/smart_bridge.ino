#include "Button.h"
#include "Display.h"

#define START_BUTTON_PIN 7

Display* textLCD = new Display();
Button* startButton = new Button(START_BUTTON_PIN);

void setup()
{
  Serial.begin(9600);

  // LCD test
  textLCD->init();
  textLCD->showText("Test");
}

void loop()
{
  // Button test
  if (startButton->isPressed()) {
      Serial.println("Button START is pressed.");
  }
}