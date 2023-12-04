//il gate si apre e il veicolo va alla zona 2 --> L2 Red inizia a lampeggiare ogni 0.1 sec + "Proceed to the Washing Area" mex nel LCD
//-) entrata del veicolo nella zona 2 è rilevata  al SONAR 
//-) se la distanza misurata dal veicolo al sonar è minore di MINDIST per N2 sec il veicolo è considerato dentro la zona 2 --> gate si chiude + L2 Red diventa accesa
//(smette di lampeggiare quindi) + "Ready to Wash" mex nel LCD
#include "Arduino.h"
#include "TaskWelcome.h"

#include "../core/StateMachine.h"

#define N2 5 // Durata in secondi per cui la distanza deve essere minore di MINDIST

TaskWelcome::TaskWelcome(SystemState activeState, UltrasonicSensor &ultrasonicSensor, Led &ledRed, ServoMotor &gate, Display &lcd)
   : Task(activeState), ultrasonicSensor(ultrasonicSensor), ledRed(ledRed), gate(gate), lcd(lcd)
    {
        //vehicleDetectedTime = 0;
        
        isVehicleInside = false;
        secondsInsideZone = 0;
    }

void TaskWelcome::init(int period) {
    Task::init(period);
}

void TaskWelcome::tick() {
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
        isVehicleInside = false;
        secondsInsideZone = 0;
        

    }

}

