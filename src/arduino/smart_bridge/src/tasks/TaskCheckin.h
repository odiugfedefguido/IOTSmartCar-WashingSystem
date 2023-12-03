#pragma once

#include "../components/sensors/Button.h"
#include "../components/sensors/Pir.h"

#include "../components/actuators/Led.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Display.h"

#include "Task.h"

class TaskCheckin : public Task {
public:
  TaskCheckin(SystemState activeState, Button& button, Led& led1, Led& led2, Led& ledRed, ServoMotor& servoGate, Display& lcd, Pir& pirSensor);
  void init(int period);
  void tick();

private:
  Button& button;
  Led& led1;
  Led& led2;
  Led& ledRed;
  ServoMotor &gate;
  Display& lcd;
  Pir& pirSensor;

  bool vehicleDetected;
  unsigned long vehicleDetectedTime;
  bool isVehiclePresent();
};