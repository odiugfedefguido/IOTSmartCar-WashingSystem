#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  this->vs = 331.45 + 0.62 * 20;  // Assuming a temperature of 20 °C
}

void UltrasonicSensor::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  float tUS = pulseIn(echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float distance = t * vs;

  return distance;
}
