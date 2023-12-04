#include "components/sensors/Button.h"
#include "components/sensors/Pir.h"
#include "components/sensors/UltrasonicSensor.h"
#include "components/sensors/TemperatureSensor.h"

#include "components/actuators/Display.h"
#include "components/actuators/ServoMotor.h"

#include "core/Scheduler.h"
#include "core/StateMachine.h"

#include "tasks/BlinkTask.h"

#include "tasks/TaskCheckin.h"
#include "tasks/TaskWelcome.h"
#include "tasks/TaskReadyToWash.h"
#include "tasks/TaskWashing.h"
#include "tasks/TaskComplete.h"
#include "tasks/TaskMaintenance.h"

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

#define N4 20
#define MINDIST 0.10
#define MAXDIST 0.10
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

  gateServo.setup();
  display.setup();
  display.showText(MSG_INIT);

  temperatureSensor.setup();
  ultrasonicSensor.setup();
  pirSensor.setup();

  Task *taskCheckin = new TaskCheckin(CHECKIN, startButton, ledGreen1, ledGreen2, ledRed, gateServo, display, pirSensor);
  taskCheckin->init(500);
  scheduler.addTask(taskCheckin);

  Task *blinkTaskReadyToWash = new BlinkTask(WELCOME, ledRed);
  blinkTaskReadyToWash->init(100);
  scheduler.addTask(blinkTaskReadyToWash);

  Task *taskWelcome = new TaskWelcome(WELCOME, ultrasonicSensor, ledRed, gateServo, display);
  taskWelcome->init(1000);
  scheduler.addTask(taskWelcome);

  Task *taskReadyToWash = new TaskReadyToWash(READY_TO_WASH, ledRed, gateServo, display, startButton);
  taskReadyToWash->init(1000);
  scheduler.addTask(taskReadyToWash);

  Task *taskWashing = new TaskWashing(WASHING, ledRed, display, temperatureSensor);
  taskWashing->init(1000);
  scheduler.addTask(taskWashing);

  Task *blinkTaskWashing = new BlinkTask(WASHING, ledRed);
  blinkTaskWashing->init(500);
  scheduler.addTask(blinkTaskWashing);

  Task *taskComplete = new TaskComplete(WASHING_COMPLETE, display, ledRed, ledGreen2, ultrasonicSensor, gateServo);
  taskComplete->init(1000);
  scheduler.addTask(taskComplete);

  Task *taskMaintenance = new TaskMaintenance(MAINTENANCE_REQUIRED, display);
  taskMaintenance->init(1000);
  scheduler.addTask(taskMaintenance);
}

void loop()
{
  scheduler.schedule();
}
