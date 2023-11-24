const int trigPin = 8;
const int echoPin = 7;
/* supposing to have a temperature
 of 20 °C */
const float vs = 331.5 + 0.6*20;
void setup()
{
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
float getDistance()
{
 /* sending impulse */
 digitalWrite(trigPin,LOW);
 delayMicroseconds(3);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(5);
 digitalWrite(trigPin,LOW);

 /* receiving the eco */
 float tUS = pulseIn(echoPin, HIGH);
 float t = tUS / 1000.0 / 1000.0 / 2;
 float d = t*vs;
 return d;
}