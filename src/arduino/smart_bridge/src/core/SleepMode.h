#ifndef SLEEP_MODE_H
#define SLEEP_MODE_H

#include <Arduino.h>

extern bool motionDetected;

void onWakeUp();
void setupInterrupt();
void enterSleepMode();

#endif // SLEEP_MODE_H
