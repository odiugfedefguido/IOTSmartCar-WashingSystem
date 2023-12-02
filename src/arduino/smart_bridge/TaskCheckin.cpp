#include "Arduino.h"
#include "TaskCheckin.h"
#include "StateMachine.h"
#include "Led.h"
#include "Display.h"
#include "ServoMotor.h"
#include "SleepMode.h"
#include "Pir.h"

#define N1 15000 // 15sec

TaskCheckin::TaskCheckin(Pir& pir, Led& led1, Led& led2, ServoMotor& gate, Display& lcd)
    : pir(pir), led1(led1), led2(led2), gate(gate), lcd(lcd) {
  vehicleDetectedTime = 0;
  vehicleDetected = false;
  // TODO: blink task
}

void TaskCheckin::init() {
  setupInterrupt();
}

void TaskCheckin::update() {
  if (isVehiclePresent()) {
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

    // entra in sleep se non rivela niente
    enterSleepMode();
    Serial.println("SLEEP");
    delay(1000); // Attendiamo un secondo per consentire la stampa su seriale
  }
}

bool TaskCheckin::isVehiclePresent() {
  Serial.println("entra il veicolo");
  delay(50);
  return pir.detectMotion();
}
