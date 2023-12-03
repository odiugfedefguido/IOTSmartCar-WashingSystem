#pragma once

#include "../components/actuators/Display.h"
#include "Task.h"

class TaskMaintenance : public Task
{
public:
    TaskMaintenance(SystemState activeState, Display &lcd);
    void init(int period);
    void tick();

private:
    Display &lcd;
    bool isFirstMessage;
    bool hasBeenInitiated;
};