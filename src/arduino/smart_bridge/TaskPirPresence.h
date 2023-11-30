#pragma once

#include "Arduino.h"
#include "Task.h"
#include "Led.h"
#include "Pir.h"

class TaskPirPresence {
public:
  TaskPirPresence(int pirPin, int ledPin);

  void init();
  void update();

private:
  bool isVehiclePresent();
  Pir pir;
  Led led;
};
