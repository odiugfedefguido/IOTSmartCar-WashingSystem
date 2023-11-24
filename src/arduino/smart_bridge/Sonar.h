#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

class DistanceSensor {
public:
    DistanceSensor(int trigPin, int echoPin);
    void setup();
    float getDistance();

private:
    int trigPin;
    int echoPin;
    const float vs = 331.5 + 0.6 * 20; // Assuming a temperature of 20 °C
};

#endif
