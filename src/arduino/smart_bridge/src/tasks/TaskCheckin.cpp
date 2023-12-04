#include "Arduino.h"
#include "TaskCheckin.h"

#include "../core/StateMachine.h"
#include "../core/SleepMode.h"

#define N1 5000 // 10 sec

TaskCheckin::TaskCheckin(SystemState activeState, Button &button, Led &ledGreen1, Led &ledGreen2, Led &ledRed, ServoMotor &gate, Display &lcd, Pir &pirSensor)
    : Task(activeState), button(button), ledGreen1(ledGreen1), ledGreen2(ledGreen2), ledRed(ledRed), gate(gate), lcd(lcd), pirSensor(pirSensor)
{
  vehicleDetectedTime = 0;
  vehicleDetected = false;
}

void TaskCheckin::init(int period) {
  Task::init(period);  
  setupInterrupt(pirSensor.getPin());
}

void TaskCheckin::tick() {
  gate.closeGate();

 /* ledGreen1.turnOn();
  ledRed.turnOn();
  ledGreen2.turnOn();

  Serial.println("led accesi");
  delay(1000);

  ledGreen1.turnOff();
  ledRed.turnOff();
  ledGreen2.turnOff();

  Serial.println("led spenti");
  delay(1000);*/


  if (isVehiclePresent()) {
    // Movimento rilevato
    if (!vehicleDetected)
    {
      // record the timestamp when the vehicle arrives for the first time
      vehicleDetectedTime = millis();
      vehicleDetected = true;

      ledGreen1.turnOn();
      lcd.showText(MSG_WELCOME);
      delay(1000);
    }
    else if (millis() - vehicleDetectedTime > N1)
    {
      ledGreen1.turnOff();
      StateMachine::transitionTo(WELCOME);
    }
  } else {
    // Movimento NON rilevato-->va in sleep e tutto spento
    // reset variables
    vehicleDetected = false;
    vehicleDetectedTime = 0;

    lcd.turnOff();
    delay(50);
    ledGreen1.turnOff();
    Serial.println("Sleep");
    delay(1000);
    enterSleepMode();
  }
}


bool TaskCheckin::isVehiclePresent() {
  if (pirSensor.detectMotion()) {
    Serial.println("Motion detected.");
  }
  return pirSensor.detectMotion();
}

