#define DEBUG true
#define SILENT true

bool hasGateBeenOpened = 0;

void debug() {
  if (DEBUG)
  {
    if (!hasGateBeenOpened && !SILENT) 
    {
      // gate
      gateServo.openGate();
      delay(2000);
      gateServo.closeGate();
      hasGateBeenOpened = 1;
    }

    // LEDs
    ledGreen1.turnOn();
    ledGreen2.turnOn();
    ledRed.turnOn();

    // button
    if (startButton.isPressed()) {
        Serial.println("Button START is pressed.");
    }

    // PIR
    if (pirSensor.detectMotion())
    {
        Serial.println("Motion detected!");
    }
 
    // sonar sensor
    float distance = ultrasonicSensor.getDistance();
    Serial.println("Sonar distance measurement: " + String(distance));

    // temperature sensor
    float temperature = temperatureSensor.getTemperature();
    Serial.println("Temperature measurement: " + String(temperature));  

    // display
    display.showText(MSG_WELCOME);

    delay(1000);
  }
}