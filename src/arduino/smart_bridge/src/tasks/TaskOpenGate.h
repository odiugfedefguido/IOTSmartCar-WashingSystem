#pragma once

#include "Task.h"

#include "../components/actuators/ServoMotor.h"

class TaskOpenGate : public Task
{
public:
    TaskOpenGate(SystemState activeState, ServoMotor &gate);
    void init(int period);
    void tick();

private:
    ServoMotor gate;
};
