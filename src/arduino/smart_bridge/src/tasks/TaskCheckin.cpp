#include "Arduino.h"
#include "TaskCheckin.h"

#include "../core/StateMachine.h"
#include "../core/SleepMode.h"

#define N1 10000 // 10 sec

TaskCheckin::TaskCheckin(SystemState activeState, Button &button, Led &led1, Led &led2, ServoMotor &gate, Display &lcd, Pir &pirSensor)
    : button(button), led1(led1), led2(led2), gate(gate), lcd(lcd), Task(activeState), pirSensor(pirSensor)
{
  vehicleDetectedTime = 0;
  vehicleDetected = false;
}

void TaskCheckin::init(int period) {
  Task::init(period);

  gate.closeGate();
  lcd.turnOff();
  
  setupInterrupt();
}

void TaskCheckin::tick() {
  Serial.println("tick");
  if (isVehiclePresent()) {
    if (!vehicleDetected)
    {
      // record the timestamp when the vehicle arrives for the first time
      vehicleDetectedTime = millis();
      vehicleDetected = true;

      led1.turnOn();
      lcd.showText(MSG_WELCOME);
    } else if (vehicleDetectedTime - millis() > N1) {
      StateMachine::transitionTo(PROCEED_TO_WASHING_AREA);
    }
  } else {
    // reset variables
    vehicleDetected = false;
    vehicleDetectedTime = 0;

    led1.turnOff();
    lcd.turnOff();

    enterSleepMode();
  }
}


bool TaskCheckin::isVehiclePresent() {
  return button.isPressed();
  // TODO: return pirSensor.detectMotion();
}

