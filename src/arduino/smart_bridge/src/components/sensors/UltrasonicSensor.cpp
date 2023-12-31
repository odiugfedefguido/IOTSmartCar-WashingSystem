#include "UltrasonicSensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin, float mindist, float maxdist) : trigPin(trigPin), echoPin(echoPin), mindist(mindist), maxdist(maxdist) {
  // Assuming a temperature of 20 °C
  this->vs = 331.45 + 0.62 * 20;  
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
  Serial.println("Distance: " + String(distance));
  return distance;
}

//questo metodo controlla se la macchina è entrata controllando la distanza
int UltrasonicSensor::carIn() {
  //se la distanza è minore della distanza minima allora la macchina è dentro
  return getDistance() < mindist;
}

int UltrasonicSensor::carOut() {
  //se la distanza è maggiore della distanza massima allora la macchina è fuori
  return getDistance() > maxdist;
}