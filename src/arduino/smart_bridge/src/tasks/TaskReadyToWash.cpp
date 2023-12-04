//il gate si apre e il veicolo va alla zona 2 --> L2 Red inizia a lampeggiare ogni 0.1 sec + "Proceed to the Washing Area" mex nel LCD
//-) entrata del veicolo nella zona 2 è rilevata  al SONAR 
//-) se la distanza misurata dal veicolo al sonar è minore di MINDIST per N2 sec il veicolo è considerato dentro la zona 2 --> gate si chiude + L2 Red diventa accesa
//(smette di lampeggiare quindi) + "Ready to Wash" mex nel LCD
#include "Arduino.h"
#include "TaskReadyToWash.h"

#include "../core/StateMachine.h"

#define N2 5 // Durata in secondi per cui la distanza deve essere minore di MINDIST

TaskReadyToWash::TaskReadyToWash(SystemState activeState, UltrasonicSensor &ultrasonicSensor, Led &ledRed, ServoMotor &gate, Display &lcd)
   : Task(activeState), ultrasonicSensor(ultrasonicSensor), ledRed(ledRed), gate(gate), lcd(lcd)
    {
        //vehicleDetectedTime = 0;
        vehicleDetected = false;
        isVehicleInside = false;
        secondsInsideZone = 0;
    }

void TaskReadyToWash::init(int period) {
    Task::init(period);
}

void TaskReadyToWash::tick() {

    if(ultrasonicSensor.carIn()) { //se la macchina è nella zona due 
        if (!isVehicleInside) {
            // record the timestamp when the vehicle arrives for the first time
            lcd.showText(MSG_READY);
            isVehicleInside = true;

            ledRed.turnOn();
            
        } 
        secondsInsideZone++; //ad ogni tic entra e aumenta di uno il tempo che la macchina è nella zona 2
        if (secondsInsideZone >= N2) {
            StateMachine::transitionTo(WASHING);
           /* lcd.showText();
            closeGate(); // Chiude il gate quando la macchina è dentro per N2 secondi
            ledRed.turnOff(); // Spegni il LED rosso
            break; // Esce dal loop di controllo della distanza*/
            return;
        } else {
           ledRed.turnOn(); // Accendi il LED rosso se la macchina non è dentro
        }
    } else {
        // reset variables
        vehicleDetected = false;

        isVehicleInside = false;
        secondsInsideZone = 0;
        

    }

}

