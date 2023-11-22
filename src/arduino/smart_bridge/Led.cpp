#include "Led.h"
#include "Arduino.h"

Led::Led(int pin) : LED_GREEN1(pin)
{
  pinMode(LED_GREEN1, OUTPUT);
}

void Led::turnOn()
{
  digitalWrite(LED_GREEN1, HIGH);
}

void Led::turnOff()
{
  digitalWrite(LED_GREEN1, LOW);
}

