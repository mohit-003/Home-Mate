int distance1 = 0;

int distance2 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  distance1 = 0.01723 * readUltrasonicDistance(9, 10);
  distance2 = 0.01723 * readUltrasonicDistance(11, 12);
  if (distance1 <= 10 || distance2 <= 10) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
