#include "TaskMaintenance.h"
#include "Arduino.h"
#include "../serial/MsgService.h"

int is_first_message = true;

TaskMaintenance::TaskMaintenance(SystemState activeState, Display &lcd) : Task(activeState), lcd(lcd)
{
    // Empty.
}

void TaskMaintenance::init(int period) {
    Task::init(period);
    MsgService.sendMsg("ERROR");
}

void TaskMaintenance::tick() {
    if (is_first_message) {
        lcd.showText(MSG_PROBLEM1);
    } else {
        lcd.showText(MSG_PROBLEM2);
    }

    is_first_message = !is_first_message;

    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "REPAIRED"){
            StateMachine::transitionTo(WASHING);
        }
        delete msg;
    }

    // TODO: Send maintenance message to PC.
    // TODO: Wait for response to continue.
}