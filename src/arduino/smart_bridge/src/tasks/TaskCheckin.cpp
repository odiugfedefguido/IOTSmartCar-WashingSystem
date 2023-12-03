#include "Arduino.h"
#include "TaskCheckin.h"

#include "../core/StateMachine.h"
#include "../core/SleepMode.h"

#define N1 10000 // 10 sec

TaskCheckin::TaskCheckin(SystemState activeState, Button &button, Led &led1, Led &led2, Led &ledRed, ServoMotor &gate, Display &lcd, Pir &pirSensor)
    : Task(activeState), button(button), led1(led1), led2(led2), ledRed(ledRed), gate(gate), lcd(lcd), pirSensor(pirSensor)
{
  vehicleDetectedTime = 0;
  vehicleDetected = false;
}

void TaskCheckin::init(int period) {
  Task::init(period);  
  setupInterrupt(pirSensor.getPin());
}

void TaskCheckin::tick() {
  gate.closeGate();
  led1.turnOff();
  ledRed.turnOff();
  led2.turnOff();

  if (isVehiclePresent()) {
    if (!vehicleDetected)
    {
      // record the timestamp when the vehicle arrives for the first time
      vehicleDetectedTime = millis();
      vehicleDetected = true;

      led1.turnOn();
      lcd.showText(MSG_WELCOME);
    }
    else if (millis() - vehicleDetectedTime > N1)
    {
      StateMachine::transitionTo(WELCOME);
    }
  } else {
    // reset variables
    vehicleDetected = false;
    vehicleDetectedTime = 0;

    lcd.turnOff();

    Serial.println("Sleep");
    enterSleepMode();
  }
}


bool TaskCheckin::isVehiclePresent() {
  if (pirSensor.detectMotion()) {
    Serial.println("Motion detected.");
  }
  return pirSensor.detectMotion();
}

