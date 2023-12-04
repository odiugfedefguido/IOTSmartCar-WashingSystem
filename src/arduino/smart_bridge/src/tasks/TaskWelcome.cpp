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
    gate.openGate();
    Serial.println(ultrasonicSensor.carIn());

    if(ultrasonicSensor.carIn()) { //se la macchina è nella zona due 

        if (!isVehicleInside) { //se il veicolo non era gia dentro
            // record the timestamp when the vehicle arrives for the first time
            lcd.showText(MSG_READY);
            isVehicleInside = true;            
        } 
        secondsInsideZone++; //ad ogni tic entra e aumenta di uno il tempo che la macchina è nella zona 2
        Serial.println(secondsInsideZone);
        if (secondsInsideZone >= N2) {
            StateMachine::transitionTo(READY_TO_WASH);
            return;
        } else {
           ledRed.turnOn(); // Accendi il LED rosso se la macchina non è dentro
        }
    } else {
        // reset variables
        isVehicleInside = false;
        secondsInsideZone = 0;
        

    }

}

