#pragma once

#include "Arduino.h"
#include "Pir.h"

class TaskPirPresence {
public:
  TaskPirPresence(int PIR_PIN);

  void init();
  void update();

private:
  bool isVehiclePresent();
  Pir pir;
};
