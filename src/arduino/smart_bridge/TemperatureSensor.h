#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

class TemperatureSensor {
public:
    TemperatureSensor(int analogPin);
    void setup();
    float getTemperature();

private:
    int analogPin;
};

#endif
