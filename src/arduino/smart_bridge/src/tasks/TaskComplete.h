#pragma once

#include "../components/actuators/Display.h"
#include "../components/actuators/ServoMotor.h"
#include "Task.h"

class TaskComplete : public Task 
{
    public:
        TaskComplete(SystemState activeState, Display &lcd);
        void init(int period);
        void tick();

    private:
        Display &lcd;
};
