#include <Arduino.h>
#include "TaskWashing.h"

#include "../core/StateMachine.h"

#define N3 7 // washing time
#define MAX_TEMPERATURE 30 // temperature threshold
#define N5 2 // max time of high temperature

TaskWashing::TaskWashing(SystemState activeState, Led &led, Display &lcd, TemperatureSensor &temperatureSensor)
    : Task(activeState), ledGreen(led), lcd(lcd), temperatureSensor(temperatureSensor)
{
    secondsWashing = 0;
    }

void TaskWashing::init(int period) {
    Task::init(period);
}

void TaskWashing::tick() {
    secondsWashing++;

    // stampo il tempo rimanente
    lcd.showNumber(N3-secondsWashing);
    // TODO: Display output is not yet working.

    Serial.println("Temperature: " + String(temperatureSensor.getTemperature()) + " " + String(temperatureSensor.getTemperature() > MAX_TEMPERATURE));

    if (temperatureSensor.getTemperature() > MAX_TEMPERATURE)
    {
        secondsAtHighTemperature += 1;
        Serial.println(secondsAtHighTemperature);

        if (secondsAtHighTemperature >= N5) {
            StateMachine::transitionTo(MAINTENANCE_REQUIRED);
            return;
        }
    }
    else
    {
        secondsAtHighTemperature = 0;
    }

    if (secondsWashing >= N3) { //macchina lavata
        StateMachine::transitionTo(WASHING_COMPLETE);
    }
}