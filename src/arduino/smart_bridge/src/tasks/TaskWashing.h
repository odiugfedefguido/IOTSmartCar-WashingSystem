#include <Arduino.h>
#include "../components/actuators/Led.h"
#include "../components/actuators/Display.h"
#include "../components/sensors/TemperatureSensor.h"
#include "Task.h"

class TaskWashing:public Task {
    public:
        TaskWashing(SystemState activeState, Led &led, Display &lcd, TemperatureSensor &temperatureSensor);
        void init(int period);
        void tick();

    private:
        SystemState activeState;
        Led& ledGreen;
        Display& lcd;
        TemperatureSensor &temperatureSensor;
        int secondsWashing = 0;
        int secondsAtHighTemperature = 0;
};