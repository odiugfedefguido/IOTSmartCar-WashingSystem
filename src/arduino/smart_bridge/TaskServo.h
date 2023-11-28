#ifndef TASK_SERVO_H
#define TASK_SERVO_H

#include "ServoMotor.h"
#include "Led.h"
#include "Display.h"
#include "Timer.h"
#include "StateMachine.h"
#include "BlinkTask.h"

class TaskServo {
public:
  TaskServo(ServoMotor& gate, Led& led, Display& display, Timer& timer);

  void init();
  void update();

private:
  ServoMotor& gate;
  Led& blinkingLed;
  Display& lcdDisplay;
  Timer& timer;
  unsigned long entryTime;
  bool gateOpened;
  BlinkTask blinkTask;
};

#endif
