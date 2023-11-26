#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
//#include "Scheduler.h"
#include "Timer.h"
#include "StateMachine.h"

#define START_BUTTON_PIN 7
#define LED_GREEN1 12
#define LED_GREEN2 8
#define LED_RED 11
#define PIR_PIN 13
#define GATE_PIN 5
#define SONAR_TRIGPIN 10
#define SONAR_ECHOPIN 9
#define TEMPERATURE_PIN A0

#define N1 5 //tempo n1 per considerare macchina nel checkin
#define N2 10
#define N3 15
#define N4 20
#define MINDIST 5
#define MAXDIST 15
#define MAXTEMP 30

Timer timer;

void debug();

TemperatureSensor temperatureSensor(TEMPERATURE_PIN);
UltrasonicSensor ultrasonicSensor(SONAR_TRIGPIN, SONAR_ECHOPIN);
Display display;
Button startButton(START_BUTTON_PIN);
ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);
Led ledGreen2 (LED_GREEN2);
Led ledRed (LED_RED);

void step(){
  switch (StateMachine::getCurrentState()) {
    case OFF:
      // Logica per lo stato OFF
      break;
    case WELCOME:
      // Logica per lo stato WELCOME
      break;
    case PROCEED_TO_WASHING_AREA:
      // Logica per lo stato PROCEED_TO_WASHING_AREA
      break;
    case READY_TO_WASH:
      // Logica qua
      break;
    case WASHING:
      // Logica
      break;
    case WASHING_COMPLETE:
      // Logica
      break;
    case LEAVE_AREA:
      // Logica
      break;
    case MAINTENANCE_REQUIRED:
      // Logica
      break;
  }
}

void setup()
{
  Serial.begin(9600);

  temperatureSensor.setup();
  ultrasonicSensor.setup();
  gateServo.setup();
  display.setup();

  timer.setupPeriod(50);
}

void loop()
{
  timer.waitForNextTick();
  step();
}
