#include "StateMachine.h"
#include "Arduino.h"

#include "../serial/MsgService.h"

static SystemState currentState = WASHING;

SystemState StateMachine::getCurrentState() {
  return currentState;
}

String getStatusText() {
  switch (currentState) {
    case CHECKIN:
      return "CHECKIN";
      break;
    case WELCOME:
      return "CAR ARRIVED";
      break;
    case READY_TO_WASH:
      return "READY TO WASH";
      break;
    case WASHING:
      return "WASHING";
      break;
    case WASHING_COMPLETE:
      return "WASHING COMPLETE";
      break;
    case MAINTENANCE_REQUIRED:
      return "MAINTENANCE REQUIRED";
      break;
  }
}

void StateMachine::transitionTo(SystemState nextState) {
  currentState = nextState;
  MsgService.sendMsg("STATUS;" + getStatusText());
}
