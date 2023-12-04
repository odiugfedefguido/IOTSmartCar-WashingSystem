//al click del bottone parte il timere per n3 sec (durante questo tempo c'è il countdown) quando finisce il tempo 
//finisce il lavaggio e si accente l3fissa e messaggio lavaggio puoi lasciare l'area il gate si apre fine task
//quando max dist è piu grande chiudo il gate e l3 si spegne 

#include <Arduino.h>
#include "../components/sensors/Button.h"
#include "../components/actuators/Led.h"
#include "../components/actuators/Display.h"
#include "Task.h"

class TaskWashing:public Task {
    public:
        TaskWashing(SystemState activeState, Button& button, Led& led, Display& lcd);
        void init(int period);
        void tick();

    private:
        SystemState activeState;
        Button& button;
        Led& ledGreen;
        Display& lcd;
        int secondsWashing;
        bool isPressed;
};