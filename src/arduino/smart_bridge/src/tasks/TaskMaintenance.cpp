#include "TaskMaintenance.h"
#include "Arduino.h"
#include "../serial/MsgService.h"

TaskMaintenance::TaskMaintenance(SystemState activeState, Display &lcd) : Task(activeState), lcd(lcd)
{
    // Empty.
}

void TaskMaintenance::init(int period) {
    Task::init(period);
}

void TaskMaintenance::tick() {
    if (!hasBeenInitiated) {
        MsgService.sendMsg("ERROR");
        hasBeenInitiated = true;
    }

    if (isFirstMessage) {
        lcd.showText(MSG_PROBLEM1);
    } else {
        lcd.showText(MSG_PROBLEM2);
    }

    isFirstMessage = !isFirstMessage;

    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "REPAIRED"){
            StateMachine::transitionTo(WASHING);
        }
        delete msg;
    }
}