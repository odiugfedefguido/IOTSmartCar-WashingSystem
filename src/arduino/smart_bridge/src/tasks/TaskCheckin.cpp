#include "Arduino.h"
#include "TaskCheckin.h"

#include "../core/StateMachine.h"
#include "../core/SleepMode.h"

//#include <EnableInterrupt.h>

#define N1 10000 // 10sec

TaskCheckin::TaskCheckin(Button& button, Led& led1, Led& led2, ServoMotor& gate, Display& lcd)
    : button(button), led1(led1), led2(led2), gate(gate), lcd(lcd) {
  vehicleDetectedTime = 0;
  vehicleDetected = false;
  // TODO: blink task
}


void TaskCheckin::init() {
  Serial.println("entra in init");
  setupInterrupt();
}

void TaskCheckin::update() {
    Serial.println("entra in update");

  if (isPressed()) {
    Serial.println("entra in isPressed in update");
    exitSleepMode();
    Serial.println("UNSLEEP");
    delay(500);

    // l1 accesa
    led1.turnOn();
    lcd.showText(MSG_WELCOME);

    if (!vehicleDetected) {
      // Se è la prima volta che viene rilevato il veicolo, registra il tempo
      vehicleDetectedTime = millis();
      vehicleDetected = true;
    }

    // Dopo N1 millisecondi, esegui le operazioni successive
    if (millis() - vehicleDetectedTime >= N1) {
      // Resettiamo le variabili per la prossima rilevazione
      vehicleDetected = false;
      vehicleDetectedTime = 0;
      gate.openGate(); // Apri il cancello
      lcd.showText(MSG_PROCEED);
      // blinking di l2!!!!
      // TODO: blinkTask.init(100);  // Imposta il periodo del lampeggio a 0.1 secondi
      // TODO: blinkTask.tick();
    }
  } else {
    // Se il veicolo non è più rilevato, resetta le variabili
    vehicleDetected = false;
    vehicleDetectedTime = 0;

    Serial.println("entra nell'else di update");

    // entra in sleep se non rivela niente
    enterSleepMode();
  }
}

/*
bool TaskCheckin::isVehiclePresent() {
  Serial.println("entra il veicolo");
  delay(50);
  return pir.detectMotion();
}*/

bool TaskCheckin::isPressed() {
  Serial.println("entra in ispressed");

  // Gestione debounce software
  static unsigned long lastButtonPressTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - lastButtonPressTime > 50) {  // Intervallo di debounce
    if (button.isPressed()) {
      Serial.println("bottone schiacciato");
      lastButtonPressTime = currentTime;
      return true;
    }
  }
  return false;
}

