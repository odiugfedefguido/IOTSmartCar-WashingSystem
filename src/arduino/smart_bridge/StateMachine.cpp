#include "StateMachine.h"
#include "Arduino.h"

static SystemState currentState = OFF;

SystemState StateMachine::getCurrentState() {
  return currentState;
}

void step(){
  switch (currentState) {
    case OFF:
      // Logica per lo stato OFF

      //taskPirPresence
      break;
    case WELCOME:
      // Logica per lo stato WELCOME
      
      //TaskServo
      break;
    case PROCEED_TO_WASHING_AREA:
      // Logica per lo stato PROCEED_TO_WASHING_AREA
      break;
    case READY_TO_WASH:
      // Logica qua
      
      break;
    case WASHING:
      // Logica
      break;
    case WASHING_COMPLETE:
      // Logica
      break;
    case LEAVE_AREA:
      // Logica
      break;
    case MAINTENANCE_REQUIRED:
      // Logica
      break;
  }
}

void StateMachine::transitionTo(SystemState nextState) {
  currentState = nextState;
}
