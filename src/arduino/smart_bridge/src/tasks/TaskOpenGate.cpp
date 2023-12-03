#include "Arduino.h"
#include "TaskOpenGate.h"

TaskOpenGate::TaskOpenGate(SystemState activeState, ServoMotor& gate)
    : Task(activeState), gate(gate)
{
    // Empty.
}

void TaskOpenGate::init(int period)
{
    Task::init(period);
}

void TaskOpenGate::tick()
{
    gate.openGate();
}