#pragma once

#include "Display.h"
#include "Task.h"

class TaskMaintenance : public Task
{
public:
    TaskMaintenance(SystemState activeState, Display &lcd);
    void init(int period);
    void tick();

private:
    Display &lcd;
    int is_first_message;
};