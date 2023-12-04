#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigPin, int echoPin, int mindist, int maxdist);
  void setup();
  float getDistance();
  int carIn();
  int carOut();

private:
  int trigPin;
  int echoPin;
  int mindist;
  int maxdist;
  float vs;
};

#endif
