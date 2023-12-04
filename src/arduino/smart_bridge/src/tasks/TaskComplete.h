#pragma once

#include "../components/sensors/UltrasonicSensor.h"
#include "../components/actuators/Display.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Led.h"
#include "Task.h"

class TaskComplete : public Task 
{
    public:
        TaskComplete(SystemState activeState, Display &lcd, Led &ledRed, Led &ledGreen, UltrasonicSensor &ultrasonicSensor);
        void init(int period);
        void tick();

    private:
        Display &lcd;
        Led &ledRed;
        Led &ledGreen;
        UltrasonicSensor &ultrasonicSensor;
        int carAbsenceDuration = 0;
        bool isFirstMessage = true;
};
