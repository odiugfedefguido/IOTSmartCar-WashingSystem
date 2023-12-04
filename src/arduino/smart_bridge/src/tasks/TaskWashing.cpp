//al click del bottone parte il timere per n3 sec (durante questo tempo c'è il countdown) quando finisce il tempo 
//finisce il lavaggio e si accente l3fissa e messaggio lavaggio puoi lasciare l'area il gate si apre fine task
#include <Arduino.h>
#include "TaskWashing.h"

#include "../core/StateMachine.h"

#define N3 7 // Durata tempo di lavaggio

TaskWashing::TaskWashing(SystemState activeState, Led &led, Display &lcd)
   : Task(activeState), ledGreen(led), lcd(lcd)
    {
        secondsWashing = 0;
    }

void TaskWashing::init(int period) {
    Task::init(period);
}

void TaskWashing::tick() {
    secondsWashing++;
    Serial.println(secondsWashing);
    //stampo il tempo rimanente
    lcd.showNumber(N3-secondsWashing);

    if(secondsWashing >= N3) { //macchina lavata
        StateMachine::transitionTo(WASHING_COMPLETE);
    }
}