#include "TaskComplete.h"
#include "Arduino.h"

bool isFirstMessage = true;

TaskComplete::TaskComplete(SystemState activeState, Display &lcd) : Task(activeState), lcd(lcd)
{
    // Empty.
}

void TaskComplete::init(int period)
{
    Task::init(period);
}

void TaskComplete::tick()
{
    if (isFirstMessage)
    {
        lcd.showText(MSG_COMPLETE1);
    }
    else
    {
        lcd.showText(MSG_COMPLETE2);
    }

    isFirstMessage = !isFirstMessage;
}
