#include "Arduino.h"
#include "TaskWelcome.h"

#include "../core/StateMachine.h"

#define N2 5 // Durata in secondi per cui la distanza deve essere minore di MINDIST

TaskWelcome::TaskWelcome(SystemState activeState, UltrasonicSensor &ultrasonicSensor, Led &ledRed, ServoMotor &gate, Display &lcd)
   : Task(activeState), ultrasonicSensor(ultrasonicSensor), ledRed(ledRed), gate(gate), lcd(lcd)
    {
        isVehicleInside = false;
        secondsInsideZone = 0;
    }

void TaskWelcome::init(int period) {
    Task::init(period);
}

void TaskWelcome::tick() {
    lcd.showText(MSG_PROCEED);
    gate.openGate();

    if(ultrasonicSensor.carIn()) { 
        // the car is in the washing area

        if (!isVehicleInside) { 
            // record the timestamp when the vehicle arrives for the first time
            isVehicleInside = true;            
        } 

        secondsInsideZone++;
        Serial.println(secondsInsideZone);
        
        if (secondsInsideZone >= N2) {
            isVehicleInside = false;
            secondsInsideZone = 0;
            StateMachine::transitionTo(READY_TO_WASH);
            return;
        }
    } else {
        // reset variables
        isVehicleInside = false;
        secondsInsideZone = 0;
    }

}

