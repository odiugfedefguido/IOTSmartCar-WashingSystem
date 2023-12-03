#include <avr/sleep.h>
#include "SleepMode.h"

#include "../components/sensors/Pir.h"
#include "../components/actuators/Led.h"
#include "../components/sensors/Button.h"

#define LED_GREEN1 12
#define START_BUTTON_PIN 2

void setupInterrupt() {
  // TODO: Make dependent on PIR.
  attachInterrupt(digitalPinToInterrupt(START_BUTTON_PIN), onWakeUp, FALLING);
}

void enterSleepMode() {
  Serial.println("sleep");
  sei(); // set interrupts enabled
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

void onWakeUp() {
  // disable sleep
  sleep_disable();
}
