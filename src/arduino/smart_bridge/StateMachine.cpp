#include "StateMachine.h"
#include "Arduino.h"

static SystemState currentState = OFF;

void StateMachine::transitionTo(SystemState nextState) {
  currentState = nextState;
}

SystemState StateMachine::getCurrentState() {
  return currentState;
}
