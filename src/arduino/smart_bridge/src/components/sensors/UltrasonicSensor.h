#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigPin, int echoPin, float mindist, float maxdist);
  void setup();
  float getDistance();
  int carIn();
  int carOut();

private:
  int trigPin;
  int echoPin;
  float mindist;
  float maxdist;
  float vs;
};

#endif