#include "ServoMotor.h"
#include "Arduino.h"

ServoMotor::ServoMotor(int pin) : GATE_PIN(pin) {
  pinMode(GATE_PIN, INPUT);
}

void ServoMotor::attach()
{
  servo.attach(GATE_PIN);
}

void ServoMotor::write(int angle)
{//SISTEMARE ANGOLO
  servo.write(angle);
}

void ServoMotor::detach()
{
  servo.detach();
}
