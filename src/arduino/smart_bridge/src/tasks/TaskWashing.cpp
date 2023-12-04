#include <Arduino.h>
#include "TaskWashing.h"

#include "../core/StateMachine.h"

#define N3 7 // Durata tempo di lavaggio

TaskWashing::TaskWashing(SystemState activeState, Led &led, Display &lcd)
   : Task(activeState), ledGreen(led), lcd(lcd)
    {
        secondsWashing = 0;
    }

void TaskWashing::init(int period) {
    Task::init(period);
}

void TaskWashing::tick() {
    secondsWashing++;

    // stampo il tempo rimanente
    lcd.showNumber(N3-secondsWashing);
    // TODO: Display output is not yet working.

    if (secondsWashing >= N3) { //macchina lavata
        StateMachine::transitionTo(WASHING_COMPLETE);
    }
}