/*#include arduino
#include "../components/actuators/ServoMotor.h"
#include "../components/actuators/Led.h"
#include "Task.h"


class TaskReadyToWash {
    public:
        TaskReadyToWash(SystemState activeState, ServoMotor& servoMotor, Led& led);
        void init(int period);
        void tick();

    private:
        ServoMotor& servoMotor;
        Led& led;
        bool isFirstMessage;
        bool hasBeenInitiated;
};*/