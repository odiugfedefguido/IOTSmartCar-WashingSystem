#include <Arduino.h>
#include "../components/sensors/TemperatureSensor.h"
#include "Task.h"

class TaskTemperature : public Task
{
public:
    TaskTemperature(SystemState activeState, TemperatureSensor &temperatureSensor);
    void init(int period);
    void tick();

private:
    SystemState activeState;
    TemperatureSensor &temperatureSensor;
};