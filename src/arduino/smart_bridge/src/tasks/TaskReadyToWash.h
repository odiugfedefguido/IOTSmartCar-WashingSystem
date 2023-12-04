#include <Arduino.h>
#include "../components/actuators/Led.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Display.h"
#include "../components/sensors/Button.h"
#include "Task.h"

class TaskReadyToWash:public Task {
    public:
        TaskReadyToWash(SystemState activeState, Led &ledRed, ServoMotor &gate, Display &lcd, Button &button);
        void init(int period);
        void tick();

    private:
        SystemState activeState;
        Led& ledRed;
        ServoMotor& gate;
        Display& lcd;
        Button& button;
};
