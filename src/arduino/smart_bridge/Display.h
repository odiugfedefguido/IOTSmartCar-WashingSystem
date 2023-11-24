#ifndef __DISPLAY__
#define __DISPLAY__

enum Message {
  WELCOME,
  PROCEED,
  READY,
  COMPLETE1,
  COMPLETE2,
  PROBLEM
};

class Display
{

public:
  void showText(Message message);
  void setup();
};

#endif
