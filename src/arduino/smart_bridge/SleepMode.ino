#include <avr/sleep.h>
#include "Pir.h"
#include "SleepMode.h"

void setupInterrupt() {
  Serial.println("interrupt settato");
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), pirInterrupt, RISING);
}

void enterSleepMode(){
    Serial.println("sleep");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
}

void exitSleepMode(){
  //sveglia sistema
  sleep_disable(); 
  Serial.println("sleep finished");
}