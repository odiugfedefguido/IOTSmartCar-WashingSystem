#include "Button.h"
#include "Display.h"

#define START_BUTTON_PIN 7

Display lcd;
Button startButton;

void setup()
{
    Serial.begin(9600);

    // LCD test
    lcd = new Display();
    lcd.showText("Test");
    
    // Button start
    startButton = Button(START_BUTTON_PIN);

}

void loop()
{
    if (startButton.isPressed()) {
        Serial.println("Button START is pressed.");
    }
}