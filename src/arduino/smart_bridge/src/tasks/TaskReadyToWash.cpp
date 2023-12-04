/* lcd.showText();
            closeGate(); // Chiude il gate quando la macchina è dentro per N2 secondi
            ledRed.turnOff(); // accendo il LED rosso se la macchina è dentro
            //messaggio ready to wash
            al clic del bottone parte il task dopo
            break; // Esce dal loop di controllo della distanza*/

#include <Arduino.h>
#include "TaskReadyToWash.h"

#include "../core/StateMachine.h"

TaskReadyToWash::TaskReadyToWash(SystemState activeState, Led &ledRed, ServoMotor &gate, Display &lcd, Button &button)
   : Task(activeState), ledRed(ledRed), gate(gate), lcd(lcd), button(button)
    {

    }
void TaskReadyToWash::init(int period) {
    Task::init(period);
}

void TaskReadyToWash::tick() {
    gate.closeGate();
    ledRed.turnOn();
    lcd.showText(MSG_READY);
    if(button.isPressed()) {
        StateMachine::transitionTo(WASHING);
        return;
    }

}

