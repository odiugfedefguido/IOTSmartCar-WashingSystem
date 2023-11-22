#include "Led.h"
#include "Arduino.h"

Led::Led(int pin) : pinLed(pin)
{
  pinMode(pinLed, OUTPUT);
}

void Led::turnOn()
{
  digitalWrite(pinLed, HIGH);
}

void Led::turnOff()
{
  digitalWrite(pinLed, LOW);
}

