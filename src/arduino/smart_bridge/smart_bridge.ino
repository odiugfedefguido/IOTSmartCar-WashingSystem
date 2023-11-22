#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"

#define START_BUTTON_PIN 7
#define LED_GREEN1 12
#define PIR_PIN 13
#define GATE_PIN 5

#define N1 5 //tempo n1 per considerare macchina nel checkin


Display* textLCD = new Display();
Button* startButton = new Button(START_BUTTON_PIN);

ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);

void setup()
{
  Serial.begin(9600);

  // LCD test
  textLCD->init();
  textLCD->showText("Test");

  gateServo.attach();
  Serial.println("Gate attached!");
}

void loop()
{
  // Button test
  if (startButton->isPressed()) {
      Serial.println("Button START is pressed.");
  }

    if (pirSensor.detectMotion())
  {
      ledGreen1.turnOn(); 
      Serial.println("Motion detected!");
  } else {
      ledGreen1.turnOff();
  }
}