#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Servo.h>

class ServoMotor
{
public:
  ServoMotor(int pin);
  void setup();
  void write(int angle);
  void detach();
  void openGate();
  void closeGate();

private:
  int GATE_PIN;
  Servo servo;
};

#endif