#include "BlinkTask.h"

BlinkTask::BlinkTask(SystemState activeState, Led &led): Task(activeState), led(&led)
{
  state = OFF;
}

void BlinkTask::init(int period) {
  Task::init(period);
  // Non è più necessario creare un nuovo oggetto Led, usiamo quello passato nel costruttore
  state = OFF;
}

void BlinkTask::tick() {
  switch (state) {
    case OFF:
      led->turnOn();
      state = ON;
      break;
    case ON:
      led->turnOff();
      state = OFF;
      break;
  }
}
