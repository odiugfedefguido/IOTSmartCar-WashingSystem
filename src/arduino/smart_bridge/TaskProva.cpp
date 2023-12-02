//è un taskCheckin che testa senza la modalità sleep!!
//problema: quando schiaccio il bottone entra in ispressed essendo true però non esegue i comandi successivi

#include "Arduino.h"
#include "TaskProva.h"
#include "StateMachine.h"
#include "Led.h"
#include "Display.h"
#include "ServoMotor.h"
#include "Button.h"

#define N1 5000 // 10sec

TaskProva::TaskProva(Button& button, Led& led1, Led& led2, ServoMotor& gate, Display& lcd) : button(button), led1(led1), led2(led2), gate(gate), lcd(lcd) {
  vehicleDetectedTime = 0;
}

void TaskProva::update() {
    Serial.println("entra in update");

  if (isPressed()) {
    //registra il tempo da quando schiaccia il bottone
    vehicleDetectedTime = millis();
    Serial.println("entra in isPressed in update");

    // l1 accesa
    led1.turnOn();
    lcd.showText(MSG_WELCOME);

    // Dopo N1 millisecondi, esegui le operazioni successive
    if (millis() - vehicleDetectedTime >= N1) {
      // Resettiamo le variabili per la prossima rilevazione
      vehicleDetectedTime = 0;
      gate.openGate(); // Apri il cancello
      lcd.showText(MSG_PROCEED);
      // blinking di l2!!!!
      // blinkTask.init(100);  // Imposta il periodo del lampeggio a 0.1 secondi
      // blinkTask.tick();
    }
  }
}

bool TaskProva::isPressed() {
  Serial.println("entra in ispressed");

  // Gestione debounce software
  static unsigned long lastButtonPressTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - lastButtonPressTime > 50) {  // Intervallo di debounce
    delay(100);
    if (button.isPressed()) {
      Serial.println("bottone schiacciato");
      lastButtonPressTime = currentTime;
      return true;
    }
  }
  return false;
}

