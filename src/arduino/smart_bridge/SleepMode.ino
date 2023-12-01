#include <avr/sleep.h>
#include "Pir.h"
#include "SleepMode.h"
#include "Led.h"

Led ledGreen7(LED_GREEN1);

void setupInterrupt() {
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), pirInterrupt, RISING);
  Serial.println("interrupt settato");
}

void enterSleepMode() {
  delay(50);
  Serial.println("sleep");
  delay(50);
  ledGreen7.turnOff();

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sei(); // Abilita gli interrupt
  sleep_mode();
  exitSleepMode();
}

void exitSleepMode() {
  ledGreen7.turnOn();

  sleep_disable(); // Disabilita la modalità sleep
  cli(); // Disabilita gli interrupt
  Serial.println("sleep finished");
}