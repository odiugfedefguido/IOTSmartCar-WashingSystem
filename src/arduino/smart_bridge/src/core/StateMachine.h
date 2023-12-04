#pragma once

// Variabili di stato
enum SystemState
{
  OFF, // first state
  ALWAYS, // for temperature measurements
  CHECKIN,
  /*
    • When no one is around, the system is off, sleeping.
    • When a vehicle is detected by the CAR PRESENCE DETECTOR in the Check In/Out Area, the light L1 is turned on and on the USER LCD the message: Welcome is displayed.
    • After N1 seconds that a vehicle is in the Check In/Out Area, …
    At that point, the gate GATE is closed, L3 is turned off
  */

  WELCOME,
  /*
    • the gate GATE is opened to allow the vehicle to proceed to the Washing Area and the light L2 starts blinking with a period equals to 0.1 secs.  On the USER LCD the message Proceed to the Washing Area is displayed.
    • The entrance of a vehicle in the Washing Area is tracked by the CAR DISTANCE DETECTOR: when the measured distance is less than MINDIST for N2 secs, …
  */

  READY_TO_WASH,
  /*
    • the vehicle is considered fully entered. The gate GATE is then closed and the light L2 stops blinking and is turned on.  On the USER LCD the message: Ready to Wash is displayed.
    • When the user presses the button START, …
  */

  WASHING,
  /*
    •  the simulated washing process begins and lasts for N3 secs. During this time, the light L2 blinks with a period equal to 0.5 secs. On the USER LCD a countdown is displayed–either using numbers or a bar changing dimensions.
    • After N3 secs, …
  */

  WASHING_COMPLETE,
  /*
    the washing process ends: L2 is turned off, L3 is turned on, the message Washing complete, you can leave the area  is displayed on the USER LCD and the gate GATE is opened to allow the vehicle to move away from the Washing Area.  In this stage, the leaving process can be considered completed when the CAR DISTANCE DETECTOR measures a distance greater than MAXDIST for N4 secs.
  */

  MAINTENANCE_REQUIRED
  /*
    ◦  If the temperature becomes greater than MAXTEMP for N4 seconds, then the washing process  is suspended and a message Maintenance required is displayed on the PC Console Dashboard, along with the message  Detected a Problem - Please Wait on the USER LCD.
    ◦ Then, the PC Console Dashboard must provide a button Maintenance done to notify that the problem has been verified (and solved)  and the washing process can go on.
  */
};

namespace StateMachine {
  void transitionTo(SystemState nextState);
  SystemState getCurrentState();
};
