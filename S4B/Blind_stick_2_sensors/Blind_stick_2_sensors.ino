// defines pins numbers
const int buzzer = 8;
const int trigPin = 9;
const int echoPin = 10;
const int trigPin1 = 11;
const int echoPin1 = 12;

// defines variables
long duration;
long duration1;
int distance;
int distance1;
int safetyDistance;
int safetyDistance1;


void setup() {
  Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
 // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
duration1 = pulseIn(echoPin1, HIGH);

// Calculating the distance
distance= duration*0.034/2;
distance1= duration1*0.034/2;

safetyDistance = distance;
safetyDistance1 = distance1;

if (safetyDistance <= 5 || safetyDistance1 <= 5){
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Distance1: ");
Serial.println(distance1);
}
