#ifndef __DISPLAY__
#define __DISPLAY__

enum Message {
  WELCOME,
  PROCEED,
  READY,
  COMPLETE,
  PROBLEM
};

class Display
{

public:
  void showText(Message message);
  void setup();
};

#endif
