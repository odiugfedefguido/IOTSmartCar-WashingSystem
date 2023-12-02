#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
// #include "ServoMotor.h"
#include "UltrasonicSensor.h"
#include "TemperatureSensor.h"
#include "Scheduler.h"
#include "BlinkTask.h"
#include "TaskCheckin.h"
#include "TaskMaintenance.h"
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
// ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);
Led ledGreen2(LED_GREEN2);
Led ledRed(LED_RED);

//TaskCheckin taskCheckin(pirSensor, ledGreen1, ledGreen2, gateServo, display);

void setup()
{
  Serial.begin(9600);
  scheduler.init(50);

  Task* taskMaintenance = new TaskMaintenance(MAINTENANCE_REQUIRED, display);
  taskMaintenance->init(1000);
  scheduler.addTask(taskMaintenance);

  // taskCheckin.init();
  // taskMaintenance.init();

  //temperatureSensor.setup();
  //ultrasonicSensor.setup();
  // gateServo.setup();
  display.setup();
}

void loop()
{

  scheduler.schedule();

  // taskCheckin.update();
  // taskMaintenance.update();


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
}
