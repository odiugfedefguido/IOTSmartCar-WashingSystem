#include "Arduino.h"
#include "TaskProceed.h"

bool isLedOn = false;

TaskProceed::TaskProceed(SystemState activeState, Led& led)
    : Task(activeState), led(led)
{
    // Empty.
}

void TaskProceed::init(int period)
{
    Task::init(period);
}

void TaskProceed::tick()
{
    if (isLedOn) {
        led.turnOff();
    } else {
        led.turnOn();
    }

    isLedOn = !isLedOn;

    // TODO: Add distance measurement part to transition to the next state.
}