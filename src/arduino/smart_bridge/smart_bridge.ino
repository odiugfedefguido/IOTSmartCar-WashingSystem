#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
// #include "Scheduler.h"

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

void debug();

// Variabili di stato
enum SystemState {
  OFF,
  // car presence detector detect car
  WELCOME, // green light is on, ...
  // N1 seconds pass
  PROCEED_TO_WASHING_AREA, // gate opens, ...
  // car distance detector detects car with distance < M1 for N2 seconds
  READY_TO_WASH, // gate closes, ...
  // button start pressed
  WASHING, // light blinks, countdown
  // N3 seconds pass
  WASHING_COMPLETE, // gate opens, ...
  // car distance detector measures car distance > M2 for N4 seconds
  LEAVE_AREA, // gate closes
  // from washing: temperature too high
  MAINTENANCE_REQUIRED
  // button on PC pressed -> WASHING
};

SystemState currentState = OFF;

TemperatureSensor temperatureSensor(TEMPERATURE_PIN);
UltrasonicSensor ultrasonicSensor(SONAR_TRIGPIN, SONAR_ECHOPIN);
Display display;
Button startButton(START_BUTTON_PIN);
ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);
Led ledGreen2 (LED_GREEN2);
Led ledRed (LED_RED);

void setup()
{
  Serial.begin(9600);

  temperatureSensor.setup();
  ultrasonicSensor.setup();
  gateServo.setup();
  display.setup();
}

void loop()
{
  debug();
}