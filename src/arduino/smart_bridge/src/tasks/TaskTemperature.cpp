#include <Arduino.h>
#include "TaskTemperature.h"

TaskTemperature::TaskTemperature(SystemState activeState, TemperatureSensor &temperatureSensor)
    : Task(activeState), temperatureSensor(temperatureSensor)
{
    // Empty.
}

void TaskTemperature::init(int period)
{
    Task::init(period);
}

void TaskTemperature::tick()
{
    float temperature = temperatureSensor.getTemperature();
    MsgService.sendMsg("TEMP;" + String(temperature));
}