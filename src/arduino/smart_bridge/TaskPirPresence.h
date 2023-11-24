#pragma once

#include "Arduino.h"
#include "Pir.h"

class TaskPirPresence {
public:
  TaskPirPresence();

  void init();
  void update();

private:
  bool isVehiclePresent();
  Pir pirSensor;
};
