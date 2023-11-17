#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Servo.h>

class ServoMotor
{
public:
  ServoMotor(int pin);
  void attach();
  void write(int angle);
  void detach();

private:
  int GATE_PIN;
  Servo servo;
};

#endif