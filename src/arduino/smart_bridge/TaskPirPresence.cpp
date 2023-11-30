#include "Arduino.h"
#include "TaskPirPresence.h"
#include "StateMachine.h"
#include "SleepMode.h"
#include "Pir.h"
 
TaskPirPresence::TaskPirPresence(int pirPin, int ledPin) : pir(pirPin), led(ledPin) {}

void TaskPirPresence::init() {
  setupInterrupt();
}

void TaskPirPresence::update() {
  if (isVehiclePresent()) {
    Serial.println("Detected a vehicle. Goes to the next state");
    //exitSleepMode();
    //StateMachine::transitionTo(WELCOME);
    delay(500);
  } else {
    //enterSleepMode();
    Serial.println("!!!!!!NOT DETECTED ");
  }
}

bool TaskPirPresence::isVehiclePresent() {
  return pir.detectMotion();
}
