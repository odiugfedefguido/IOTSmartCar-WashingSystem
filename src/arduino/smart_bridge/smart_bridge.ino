#include "Button.h"
#include "Display.h"
#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"
#include "DistanceSensor.h"

#define START_BUTTON_PIN 7
#define LED_GREEN1 12
#define LED_GREEN2 8
#define LED_RED 11
#define PIR_PIN 13
#define GATE_PIN 5


//pin del sonar
//const int trigPin = ?;
//const int echoPin = ?;

DistanceSensor distanceSensor(trigPin, echoPin);

#define N1 5 //tempo n1 per considerare macchina nel checkin

void debug();

Display* textLCD = new Display();
//Button* startButton = new Button(START_BUTTON_PIN);
//Led* ledGreen1 = new Led(LED_GREEN1);

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
  textLCD->showText("Test");

  gateServo.attach();
  Serial.println("Gate attached!");*/
  gateServo.attach();
  Serial.println("Gate attached!");
  distanceSensor.setup(); //
 
}

void loop()
{
  debug();
  // Button test
}

void debug() {

  gateServo.write(180);
  /*ledGreen1.turnOn();
  ledGreen2.turnOn();
  ledRed.turnOn();

  if (startButton.isPressed()) {
      Serial.println("Button START is pressed.");
  }*/

  /*if (pirSensor.detectMotion())
  {
      ledGreen1.turnOn(); 
      Serial.println("Motion detected!");
  }*/

  float distance = distanceSensor.getDistance();//
}