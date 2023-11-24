#include "temp.h"
#include <Arduino.h>

TemperatureSensor::TemperatureSensor(int analogPin) {
    this->analogPin = analogPin;
}

void TemperatureSensor::setup() {
    // Aggiungi eventuali inizializzazioni del sensore, se necessario
}

float TemperatureSensor::getTemperature() {
    // Leggi il valore analogico
    int sensorValue = analogRead(analogPin);

    // Converti il valore analogico in temperatura in gradi Celsius
    float temperature = (sensorValue / 1023.0) * 500.0;

    return temperature;
}
