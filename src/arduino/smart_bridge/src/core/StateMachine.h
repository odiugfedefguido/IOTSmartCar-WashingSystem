#pragma once

// Variabili di stato
enum SystemState {
  OFF, // system is on sleep mode
  // car presence detector detect car -->taskpirpresence
  WELCOME, // green light is on, ...
  // N1 seconds pass
  PROCEED_TO_WASHING_AREA, // gate opens, ...
  // car distance detector detects car with distance < M1 for N2 seconds
  READY_TO_WASH, // gate closes, ...
  // button start pressed
  WASHING, // light blinks, countdown
  // N3 seconds pass
  WASHING_COMPLETE, // gate opens, ...
  // car distance detector measures car distance > M2 for N4 seconds
  LEAVE_AREA, // gate closes
  // from washing: temperature too high
  MAINTENANCE_REQUIRED
  // button on PC pressed -> WASHING
};

void step();

namespace StateMachine {
  void transitionTo(SystemState nextState);
  SystemState getCurrentState();
};
