#include "TemperatureSensor.h"
#include <Arduino.h>

TemperatureSensor::TemperatureSensor(int analogPin) {
    this->analogPin = analogPin;
}

void TemperatureSensor::setup() {
    // add initializations if necessary
}

float TemperatureSensor::getTemperature() {
    // Read the analog value
    int sensorValue = analogRead(analogPin);

    // Convert that reading into voltage
    // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
    float voltage = sensorValue * (5.0 / 1024.0);

    // Convert the voltage into the temperature in Celsius
    float temperature = (voltage - 0.5) * 100;

    return temperature;
}
