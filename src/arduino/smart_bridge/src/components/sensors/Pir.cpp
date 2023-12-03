#include "Pir.h"
#include "Arduino.h"

#define CALIBRATION_TIME_SEC 10

bool detectedStatus;

Pir::Pir(int pin) : PIR_PIN(pin)
{
  pinMode(PIR_PIN, INPUT);
}

void Pir::setup() 
{
  // give the sensor some time to calibrate
  Serial.print("Calibrating PIR sensor: ");
  for (int i = 0; i < CALIBRATION_TIME_SEC; i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("PIR SENSOR READY.");
  detectedStatus = false;
  delay(50);
}

bool Pir::detectMotion()
{
  int current = digitalRead(PIR_PIN);
  if (current != detectedStatus)
  {
    detectedStatus = current;
    if (current)
    {
      Serial.println("detected!");
      return true;
    }
    else
    {
      Serial.println("no more detected.");
      return false;
    }
  }
}

int Pir::getPin() {
  return PIR_PIN;
}
