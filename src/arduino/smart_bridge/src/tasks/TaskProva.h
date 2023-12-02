#pragma once

#include "../components/sensors/Button.h"

#include "../components/actuators/Led.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Display.h"

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