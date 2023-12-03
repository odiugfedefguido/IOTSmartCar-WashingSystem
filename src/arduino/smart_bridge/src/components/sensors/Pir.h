#ifndef PIR_H
#define PIR_H

class Pir {
public:
  Pir(int pin);
  bool detectMotion();
  void setup();
  int getPin();

private:
  int PIR_PIN;
};

#endif
