#include "components/sensors/Button.h"
#include "components/sensors/Pir.h"
#include "components/sensors/UltrasonicSensor.h"
#include "components/sensors/TemperatureSensor.h"

#include "components/actuators/Display.h"
#include "components/actuators/ServoMotor.h"

#include "core/Scheduler.h"
#include "core/StateMachine.h"

#include "tasks/BlinkTask.h"
#include "tasks/TaskOpenGate.h"
#include "tasks/TaskCheckin.h"
#include "tasks/TaskMaintenance.h"
#include "tasks/TaskWelcome.h"

#include "serial/MsgService.h"

#define START_BUTTON_PIN 4
#define LED_GREEN1 12
#define LED_GREEN2 8
#define LED_RED 7
#define PIR_PIN 2
#define GATE_PIN 3
#define SONAR_TRIGPIN 10
#define SONAR_ECHOPIN 9
#define TEMPERATURE_PIN A0

#define N2 10
#define N3 15
#define N4 20
#define MINDIST 0.05
#define MAXDIST 0.05
#define MAXTEMP 30

Scheduler scheduler;

void debug();

TemperatureSensor temperatureSensor(TEMPERATURE_PIN);
UltrasonicSensor ultrasonicSensor(SONAR_TRIGPIN, SONAR_ECHOPIN, MINDIST, MAXDIST);
Display display;
Button startButton(START_BUTTON_PIN);
ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);
Led ledGreen2(LED_GREEN2);
Led ledRed(LED_RED);

void setup()
{
  Serial.begin(9600);
  scheduler.init(10); // base period
  MsgService.init();

  ledGreen1.setup();
  ledGreen2.setup();
  ledRed.setup();

  temperatureSensor.setup();
  ultrasonicSensor.setup();
  pirSensor.setup();

  gateServo.setup();
  display.setup();

  Task *taskCheckin = new TaskCheckin(CHECKIN, startButton, ledGreen1, ledGreen2, ledRed, gateServo, display, pirSensor);
  taskCheckin->init(500);
  scheduler.addTask(taskCheckin);

  Task *blinkTaskReadyToWash = new BlinkTask(WELCOME, ledGreen2);
  blinkTaskReadyToWash->init(100);
  scheduler.addTask(blinkTaskReadyToWash);

  Task *taskOpenGate = new TaskOpenGate(WELCOME, gateServo);
  taskOpenGate->init(10);
  scheduler.addTask(taskOpenGate);

  Task *taskWelcome = new TaskWelcome(WELCOME, ultrasonicSensor, ledRed, gateServo, display);
  taskWelcome->init(1000);
  scheduler.addTask(taskWelcome);

  Task *taskMaintenance = new TaskMaintenance(MAINTENANCE_REQUIRED, display);
  taskMaintenance->init(100);
  scheduler.addTask(taskMaintenance);
}

void loop()
{
  scheduler.schedule();
}
