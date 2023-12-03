#pragma once

#include "Task.h"

#include "../components/actuators/Led.h"

class TaskProceed : public Task
{
public:
    TaskProceed(SystemState activeState, Led& led);
    void init(int period);
    void tick();

private:
    Led led;
};