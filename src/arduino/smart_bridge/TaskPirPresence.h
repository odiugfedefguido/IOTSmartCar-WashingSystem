#pragma once

#include "Arduino.h"
#include "Task.h"
#include "Pir.h"

class TaskPirPresence {
public:
  TaskPirPresence(int PIR_PIN, int L1_PIN);

  void init();
  void update();

private:
  bool isVehiclePresent();
  Pir pir;
  int L1_PIN;
};
