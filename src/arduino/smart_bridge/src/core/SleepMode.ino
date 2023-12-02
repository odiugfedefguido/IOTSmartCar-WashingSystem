#include <avr/sleep.h>
#include "Pir.h"
#include "SleepMode.h"
#include "Led.h"
#include "Button.h"
//#include <EnableInterrupt.h>

Led ledGreen7(LED_GREEN1);

// Variabile di stato per indicare se il sistema deve svegliarsi
volatile bool wakeUpRequested = false;

void setupInterrupt() {
  attachInterrupt(digitalPinToInterrupt(START_BUTTON_PIN), buttonInterrupt, RISING);
  Serial.println("interrupt settato");
}

void enterSleepMode() {
  delay(50);
  Serial.println("sleep");
  delay(50);
  ledGreen7.turnOff();
  sei(); // Abilita gli interrupt
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  delay(500);

  // Se la variabile di stato indica che il sistema deve svegliarsi, esegui l'uscita dallo sleep
  if (wakeUpRequested) {
    Serial.println("wakeuprequested->exitsleep");
    wakeUpRequested = false;
    exitSleepMode();
  }
}

void exitSleepMode() {
    cli(); // Disabilita gli interrupt
    Serial.println("exit sleep mode");
  sleep_disable(); // Disabilita la modalità sleep
  ledGreen7.turnOn();
  Serial.println("wake up");
}

void buttonInterrupt() {
  // Imposta la variabile di stato per indicare che il sistema deve svegliarsi
  wakeUpRequested = true;
}
