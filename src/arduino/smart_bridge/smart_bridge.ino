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
#define SONAR_TRIGPIN 10
#define SONAR_ECHOPIN 9

#define N1 5 //tempo n1 per considerare macchina nel checkin

//pin temperatura
//const int analogPin = A0;

//TemperatureSensor temperatureSensor(analogPin);

//DistanceSensor distanceSensor(trigPin, echoPin);


UltrasonicSensor ultrasonicSensor(SONAR_TRIGPIN, SONAR_ECHOPIN);



void debug();

Display* textLCD = new Display();
//Button* startButton = new Button(START_BUTTON_PIN);
//Led* ledGreen1 = new Led(LED_GREEN1);

//int potpin = A0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin

Button startButton(START_BUTTON_PIN);
//ServoMotor gateServo(GATE_PIN);
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

  //gate test
  gateServo.attach();
  Serial.println("Gate attached!");
  gateServo.attach();
  Serial.println("Gate attached!");*/

  //sensor test
  //distanceSensor.setup(); //
 //temperatureSensor.setup(); //

  //sonar
 //pinMode(trigPin, OUTPUT);
 //pinMode(echoPin, INPUT);

 ultrasonicSensor.setup();
}

void loop()
{
  debug();
  // Button test
}

void debug() {
/*
  //parte del servo
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  gateServo.write(val);// sets the servo position according to the scaled value
  Serial.println(val);
  delay(15);*/

  //parte dei led
  /*ledGreen1.turnOn();
  ledGreen2.turnOn();
  ledRed.turnOn();

  //parte dei bottoni
  if (startButton.isPressed()) {
      Serial.println("Button START is pressed.");
  }*/

  //parte del pir
  if (pirSensor.detectMotion())
  {
      ledGreen1.turnOn(); 
      Serial.println("Motion detected!");
  }

  /*
  //sonar
  float distance = ultrasonicSensor.getDistance();
  Serial.println(distance);
  delay(200);  
  */

  //temp
  /*float temperature = temperatureSensor.getTemperature();
  Serial.println(d);
  delay(200);*/

}