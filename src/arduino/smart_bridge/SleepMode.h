#ifndef SLEEP_MODE_H
#define SLEEP_MODE_H

#include <Arduino.h>

extern bool motionDetected;

void pirInterrupt();
void setupInterrupt();
void enterSleepMode();
void exitSleepMode();

#endif // SLEEP_MODE_H
