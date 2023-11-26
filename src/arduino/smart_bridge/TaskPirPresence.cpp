/**
*-) se non ci sono veicoli nella zona 1 sistema va in sleep -->gestire con scheduler ad ogni tick
*-) quando arriva un veicolo che viene rilevato dal PIR nella zona 1 --> L1 Green si accende + "Welcome" mex nel LCD
*-) dopo N1 secondi che il veicolo è nella zona 1, il gate si apre e il veicolo va alla zona 2 
*-) finito l'autolavaggio il gate si apre
*-) la macchina si considera uscita solo quando il sonar misura una distanza più grande di MAXDIST per un tempo di N4 sec --> gate si chiude + L3 Green si spegne
**/

//il pir rivela una macchina 
#include "Arduino.h"
#include "TaskPirPresence.h"
#include "StateMachine.h"
#include "Pir.h"

TaskPirPresence::TaskPirPresence(int PIR_PIN) : pir(PIR_PIN) {}

void TaskPirPresence::init() {
}

void TaskPirPresence::update() {
  if (isVehiclePresent()) {
    // Logica per la presenza del veicolo--> passa al prossimo stato
    Serial.println("Detected a vehicle. Goes to the next state");
    StateMachine::transitionTo(WELCOME);
  }
}

bool TaskPirPresence::isVehiclePresent() {
  return pir.detectMotion();
}
