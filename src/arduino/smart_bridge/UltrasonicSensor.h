#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigPin, int echoPin);
  void setup();
  float getDistance();

private:
  int trigPin;
  int echoPin;
  float vs;
};

#endif
