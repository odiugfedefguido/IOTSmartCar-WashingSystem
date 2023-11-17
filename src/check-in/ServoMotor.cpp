#include "ServoMotor.h"
#include "Arduino.h"

ServoMotor::ServoMotor(int pin) : servoPin(pin) {}

void ServoMotor::attach()
{
  servo.attach(GATE_PIN);
}

void ServoMotor::write(int angle)
{
  servo.write(angle);
}

void ServoMotor::detach()
{
  servo.detach();
}
