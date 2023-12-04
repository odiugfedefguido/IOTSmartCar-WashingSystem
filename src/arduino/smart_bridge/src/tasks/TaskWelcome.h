#include <Arduino.h>
#include "../components/sensors/UltrasonicSensor.h"
#include "../components/actuators/Led.h"
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Display.h"
#include "Task.h"


class TaskWelcome:public Task {
    public:
        TaskWelcome(SystemState activeState, UltrasonicSensor &ultrasonicSensor, Led &led, ServoMotor &gate, Display &lcd);
        void init(int period);
        void tick();

    private:
        SystemState activeState;
        UltrasonicSensor& ultrasonicSensor;
        Led& ledRed;
        ServoMotor& gate;
        Display& lcd;
        bool isVehicleInside;
        int secondsInsideZone;


};