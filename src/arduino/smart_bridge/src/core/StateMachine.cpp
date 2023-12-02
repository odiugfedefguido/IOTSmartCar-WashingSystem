#include "StateMachine.h"
#include "Arduino.h"

#include "../serial/MsgService.h"

static SystemState currentState = OFF;

SystemState StateMachine::getCurrentState() {
  return currentState;
}

String getStatusText() {
  switch (currentState) {
    case OFF:
      return "IDLE";
      break;
    case WELCOME:
      return "CAR ARRIVED";
      break;
    case PROCEED_TO_WASHING_AREA:
      return "PROCEED TO WASHING";
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
    case LEAVE_AREA:
      return "LEAVING THE AREA";
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
