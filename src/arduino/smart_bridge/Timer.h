#ifndef __TIMER__
#define __TIMER__

class Timer {
    
public:  
  Timer();
  void setupFreq(int freq);  
  /* period in ms */
  void setupPeriod(int period);  
  void waitForNextTick();
  unsigned long elapsedTime(long unsigned int startTime);
};


#endif