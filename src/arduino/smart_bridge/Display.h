#ifndef __DISPLAY__
#define __DISPLAY__

enum Message {
  MSG_WELCOME,
  MSG_PROCEED,
  MSG_READY,
  MSG_COMPLETE1,
  MSG_COMPLETE2,
  MSG_PROBLEM
};

class Display
{

public:
  void showText(Message message);
  void setup();
};

#endif
