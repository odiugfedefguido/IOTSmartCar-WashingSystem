#include <Arduino.h>
#include "TaskReadyToWash.h"

#include "../core/StateMachine.h"

TaskReadyToWash::TaskReadyToWash(SystemState activeState, Led &ledRed, ServoMotor &gate, Display &lcd, Button &button)
   : Task(activeState), ledRed(ledRed), gate(gate), lcd(lcd), button(button)
{
    // Empty.
}

void TaskReadyToWash::init(int period) {
    Task::init(period);
}

void TaskReadyToWash::tick() {
    gate.closeGate();
    ledRed.turnOn();
    lcd.showText(MSG_READY);
    if(button.isPressed()) {
        StateMachine::transitionTo(WASHING);
        return;
    }

}

