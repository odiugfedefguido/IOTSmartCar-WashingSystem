#include "Arduino.h"
#include "TaskPirPresence.h"
#include "StateMachine.h"
#include "SleepMode.h"
#include "Pir.h"
 
TaskPirPresence::TaskPirPresence(int PIR_PIN, int L1_PIN) : pir(PIR_PIN), L1_PIN(L1_PIN) {}

void TaskPirPresence::init() {
  pinMode(L1_PIN, OUTPUT);
  setupInterrupt();
}

void TaskPirPresence::update() {
  if (isVehiclePresent()) {
    // Logica per la presenza del veicolo--> passa al prossimo stato
    Serial.println("Detected a vehicle. Goes to the next state");
    exitSleepMode();
    StateMachine::transitionTo(WELCOME);
    // Accendi la luce L1
    digitalWrite(L1_PIN, HIGH);
    Serial.println("nuovo stato: WELCOME");
  } else {
    enterSleepMode();
  }
}

bool TaskPirPresence::isVehiclePresent() {
  return pir.detectMotion();
}
