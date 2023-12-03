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
#include "tasks/TaskMaintenance.h"
#include "tasks/TaskProva.h"

#include "serial/MsgService.h"

#define START_BUTTON_PIN 4
#define LED_GREEN1 12
#define LED_GREEN2 8
#define LED_RED 11
#define PIR_PIN 2
#define GATE_PIN 3
#define SONAR_TRIGPIN 10
#define SONAR_ECHOPIN 9
#define TEMPERATURE_PIN A0

#define N2 10
#define N3 15
#define N4 20
#define MINDIST 0.03
#define MAXDIST 15
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
  scheduler.init(50); // base period
  MsgService.init();

  temperatureSensor.setup();
  ultrasonicSensor.setup();
  pirSensor.setup();

  gateServo.setup();
  display.setup();

  Task *taskCheckin = new TaskCheckin(OFF, startButton, ledGreen1, ledGreen2, gateServo, display, pirSensor);
  taskCheckin->init(500);
  scheduler.addTask(taskCheckin);

  Task* taskMaintenance = new TaskMaintenance(MAINTENANCE_REQUIRED, display);
  taskMaintenance->init(100);
  scheduler.addTask(taskMaintenance);
}

int val = 1000;

void loop()
{
  scheduler.schedule();

  //ultrasonicSensor.carOut();
  /*
  bool motionDetected = pirSensor.detectMotion();
   if (motionDetected) {
    Serial.println("Movimento rilevato!");
    digitalWrite(LED_BUILTIN, HIGH);  // Accendi il LED incorporato
  } else {
    Serial.println("Nessun movimento rilevato.");
    digitalWrite(LED_BUILTIN, LOW);  // Spegni il LED incorporato
  }*/
  
  //taskProva.update();
  
}
