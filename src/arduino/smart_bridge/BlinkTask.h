// BlinkTask.h
#ifndef __BLINK_TASK__
#define __BLINK_TASK__

#include "Task.h"
#include "Led.h"

class BlinkTask : public Task {
  int pin;
  Led* led;
  enum { ON, OFF } state;

public:
  BlinkTask(Led& led);  // Modificato il costruttore per accettare un riferimento a Led
  void init(int period);
  void tick();
};

#endif
