#pragma once

#include "Button.h"
#include "Led.h"
#include "ServoMotor.h"
#include "Display.h"
#include "BlinkTask.h"

class TaskProva {
public:
  TaskProva(Button &button, Led &led1, Led &led2, ServoMotor &gate, Display &lcd);
  void init();
  void update();

private:
  Button& button;
  Led& led1;
  Led& led2;
  ServoMotor& gate;
  Display& lcd;
  // BlinkTask blinkTask;

  unsigned long vehicleDetectedTime;
  bool isPressed();
};