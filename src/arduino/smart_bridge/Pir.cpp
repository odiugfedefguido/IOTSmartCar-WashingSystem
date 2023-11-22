#include "Pir.h"
#include "Arduino.h"

Pir::Pir(int pin) : PIR_PIN(pin)
{
  pinMode(PIR_PIN, INPUT);
}

bool Pir::detectMotion()
{
  return digitalRead(PIR_PIN) == HIGH;
}
