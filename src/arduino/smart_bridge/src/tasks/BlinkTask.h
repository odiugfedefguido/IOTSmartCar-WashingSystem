#ifndef __BLINK_TASK__
#define __BLINK_TASK__

#include "Task.h"
#include "../components/actuators/Led.h"

class BlinkTask : public Task {
  int pin;
  Led* led;
  enum { ON, OFF } state;

public:
  BlinkTask(SystemState activeState, Led &led);
  void init(int period);
  void tick();
};

#endif
