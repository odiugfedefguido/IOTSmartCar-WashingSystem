#include "TaskComplete.h"
#include "Arduino.h"

#define N4 5 // seconds for a car to be absent

TaskComplete::TaskComplete(SystemState activeState, Display &lcd, Led &ledRed, Led &ledGreen, UltrasonicSensor &ultrasonicSensor, ServoMotor& gate) : Task(activeState), lcd(lcd), ledRed(ledRed), ledGreen(ledGreen), ultrasonicSensor(ultrasonicSensor), gate(gate)
{
    // Empty.
}

void TaskComplete::init(int period)
{
    Task::init(period);
}

void TaskComplete::tick()
{
    ledRed.turnOff();
    ledGreen.turnOn();

    if (isFirstMessage)
    {
        lcd.showText(MSG_COMPLETE1);
    }
    else
    {
        lcd.showText(MSG_COMPLETE2);
    }

    isFirstMessage = !isFirstMessage;

    if (ultrasonicSensor.carOut()) {
        carAbsenceDuration += 1;

        if (carAbsenceDuration > N4) 
        {
            ledGreen.turnOff();
            gate.openGate();
            MsgService.sendMsg("COMPLETE");
            StateMachine::transitionTo(CHECKIN);
        }
    } else {
        carAbsenceDuration = 0;
    }
}
