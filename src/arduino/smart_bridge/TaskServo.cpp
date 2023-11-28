#include "TaskServo.h"
#include "StateMachine.h"
#include "Arduino.h"

#define N1 100

TaskServo::TaskServo(ServoMotor& gate, Led& led, Display& display, Timer& timer)
    : gate(gate), blinkingLed(led), lcdDisplay(display), timer(timer), entryTime(0), gateOpened(false), blinkTask(8) {}

void TaskServo::init() {
  // Inizializza il task se necessario
}

void TaskServo::update() {
  switch (StateMachine::getCurrentState()) {
    case PROCEED_TO_WASHING_AREA:
      if (!gateOpened) {
        entryTime = millis();
        gate.openGate(); // Apri il cancello
        //lcdDisplay.showText("Proceed to Washing Area");
        gateOpened = true;
      }

      // BlinkTask
      blinkTask.init(100);  // Imposta il periodo del lampeggio a 0.1 secondi
      blinkTask.tick();

      // Se è trascorso il tempo N1, passa allo stato successivo
      if (timer.elapsedTime(entryTime) > N1 * 1000) {
        StateMachine::transitionTo(WASHING);
      }
      break;

    default:
      // Altri stati o logica qui se necessario
      break;
  }
}
