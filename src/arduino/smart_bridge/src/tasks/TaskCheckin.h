#pragma once

#include "../components/sensors/Button.h"

#include "../components/actuators/Led.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Display.h"

#include "BlinkTask.h"

class TaskCheckin {
public:
  TaskCheckin(Button& button, Led& led1, Led& led2, ServoMotor& servoGate, Display& display);
  void init();
  void update();

private:
  Button& button;
  Led& led1;
  Led& led2;
  ServoMotor& gate;
  Display& lcd;
  // BlinkTask blinkTask;

  //bool isVehiclePresent();
  bool vehicleDetected;
  unsigned long vehicleDetectedTime;
  bool isPressed();
};