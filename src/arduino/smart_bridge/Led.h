#ifndef LED_H
#define LED_H

class Led
{
public:
  Led(int pin);
  void turnOn();
  void turnOff();

private:
  int LED_GREEN1;
};

#endif
