#pragma once

#include "Pir.h"
#include "Led.h"
#include "ServoMotor.h"
#include "Display.h"
#include "BlinkTask.h"

class TaskCheckin {
public:
  TaskCheckin(Pir& pir, Led& led1, Led& led2, ServoMotor& servoGate, Display& display);
  void init();
  void update();

private:
  Pir& pir;
  Led& led1;
  Led& led2;
  ServoMotor& gate;
  Display& lcd;
  // BlinkTask blinkTask;

  bool isVehiclePresent();
  bool vehicleDetected;
  unsigned long vehicleDetectedTime;
};