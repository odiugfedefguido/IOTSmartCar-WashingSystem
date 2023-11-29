#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin, int mindist, int maxdist) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  this->vs = 331.45 + 0.62 * 20;  // Assuming a temperature of 20 °C
  this->mindist = mindist;
  this->maxdist = maxdist;
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
  Serial.print(distance);
  return distance;
}

//questo metodo controlla se la macchina è entrata controllando la distanza
void UltrasonicSensor::carIn() {
  //se la distanza è minore della distanza minima allora la macchina è dentro
  if (getDistance() < mindist) {
    Serial.println("Car in");
  }
}

void UltrasonicSensor::carOut() {
  //se la distanza è maggiore della distanza massima allora la macchina è fuori
  if (getDistance() > maxdist) {
    Serial.println("Car out");
  }
}
