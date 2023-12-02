#include "TaskMaintenance.h"
#include "Display.h"
#include "Arduino.h"

int is_first_message = true;

TaskMaintenance::TaskMaintenance(SystemState activeState, Display &lcd) : Task(activeState), lcd(lcd)
{
    // TODO:
    Serial.println("create");
}

void TaskMaintenance::init(int period) {
    Task::init(period);
    Serial.println("init");
}

void TaskMaintenance::tick() {
    Serial.println("tick");
    if (is_first_message) {
        lcd.showText(MSG_PROBLEM1);
    } else {
        lcd.showText(MSG_PROBLEM2);
    }

    is_first_message = !is_first_message;

    // TODO: Send maintenance message to PC.
    // TODO: Wait for response to continue.
}