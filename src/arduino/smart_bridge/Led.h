#ifndef LED_H
#define LED_H

class Led
{
public:
  Led(int pin);
  void turnOn();
  void turnOff();

private:
  int pinLed;
};

#endif
