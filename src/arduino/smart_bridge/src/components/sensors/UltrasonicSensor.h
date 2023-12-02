#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigPin, int echoPin, int mindist, int maxdist);
  void setup();
  float getDistance();
  void carIn();
  void carOut();

private:
  int trigPin;
  int echoPin;
  int mindist;
  int maxdist;
  float vs;
};

#endif
