#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"
#include "UltrasonicSensor.h"
#include "temp.h"

#define START_BUTTON_PIN 7
#define LED_GREEN1 12
#define LED_GREEN2 8
#define LED_RED 11
#define PIR_PIN 13
#define GATE_PIN 5

#define N1 5 //tempo n1 per considerare macchina nel checkin

//pin temperatura
//const int analogPin = A0;

//TemperatureSensor temperatureSensor(analogPin);

//DistanceSensor distanceSensor(trigPin, echoPin);



//sonar
const int SONAR_TRIGPIN = 9;
const int SONAR_ECHOPIN  = 10;

UltrasonicSensor ultrasonicSensor(SONAR_TRIGPIN, SONAR_ECHOPIN);



void debug();

Display* textLCD = new Display();
//variabili per il servo
int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

Button startButton(START_BUTTON_PIN);
ServoMotor gateServo(GATE_PIN);
Pir pirSensor(PIR_PIN);
Led ledGreen1(LED_GREEN1);
Led ledGreen2 (LED_GREEN2);
Led ledRed (LED_RED);

void setup()
{
  Serial.begin(9600);

  // LCD test
  /*
  textLCD->init();
  textLCD->showText("Test");*/

  //gate test
  gateServo.attach();
  Serial.println("Gate attached!");


  //sensor test
  //distanceSensor.setup(); //
 //temperatureSensor.setup(); //

  //sonar
 //pinMode(trigPin, OUTPUT);
 //pinMode(echoPin, INPUT);
}

void loop()
{
  debug();
}

void debug() {
/*
  //parte del servo
*/

  //parte dei led
  /*ledGreen1.turnOn();
  ledGreen2.turnOn();
  ledRed.turnOn();

  //parte dei bottoni
  if (startButton.isPressed()) {
      Serial.println("Button START is pressed.");
  }*/
  
  // Chiamare closeGate() per chiudere il gate
  gateServo.closeGate();
  delay(2000);  // Attendere per 2 secondi

  //parte del servo
  // Chiamare openGate() per aprire il gate
  gateServo.openGate();
  delay(2000);  // Attendere per 2 secondi
/*
  //parte del pir
  if (pirSensor.detectMotion())
  {
      ledGreen1.turnOn(); 
      Serial.println("Motion detected!");
  }

  //sonar
  float distance = ultrasonicSensor.getDistance();
  Serial.println(distance);
  delay(200);  */

  //temp
  /*float temperature = temperatureSensor.getTemperature();
  Serial.println(d);
  delay(200);*/

}