#include "Led.h"
#include "Pir.h"
#include "ServoMotor.h"

#define LED_GREEN1 12
#define PIR_PIN 13
#define GATE_PIN 5

#define N1 5 //tempo n1 per considerare macchina nel checkin

ServoMotor gateServo(GATE_PIN);
PIRSensor pirSensor(PIR_PIN);
LED ledGreen1(LED_GREEN1);

void setup(){
  Serial.begin(9600);

  gateServo.attach();
  Serial.println("Gate attached!");
}

void loop(){
    if (pirSensor.detectMotion())
    {
        ledGreen1.turnOn(); 
        Serial.println("Motion detected!");
    } else {
        ledGreen1.turnOff();
    }

    delay(10);
}