#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11;
          const int ldrPin = A0;
          const int LED = 9;
      const int FAN = 10;
          // int ledin;
          int ldrStatus;
              const int trigPin = 4;
              const int echoPin = 5;
              const int disco = 6;
              long duration;
              int distance;
              int safetyDistance;


void setup() {
              pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
              pinMode(echoPin, INPUT); // Sets the echoPin as an Input
              pinMode(disco, OUTPUT);
Serial.begin(9600);
          pinMode(ldrPin, INPUT);
          pinMode(LED, OUTPUT);
          pinMode(FAN, OUTPUT);
}

void loop() {


              // Clears the trigPin
              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              
              // Sets the trigPin on HIGH state for 10 micro seconds
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              
              // Reads the echoPin, returns the sound wave travel time in microseconds
              duration = pulseIn(echoPin, HIGH);
              
              // Calculating the distance
              distance= duration*0.034/2;
              safetyDistance = distance;
              if (safetyDistance <= 10){
                digitalWrite(disco, HIGH);
              }
              else{
                digitalWrite(disco, LOW);
              }



byte temperature = 0;
byte humidity = 0;
if (dht11.read(pinDHT11, &temperature, &humidity, NULL))
{
return;
}
      ldrStatus = analogRead(ldrPin);
//      ledin = (1023 - ldrStatus)/4;
//      analogWrite(LED , ledin);
if ( ldrStatus >= 850 ) {
   analogWrite(LED , 255 );
} else if ( ldrStatus >= 650 ) {
   analogWrite(LED , 128 );
} else if ( ldrStatus >= 450 ) {
   analogWrite(LED , 64 );
} else if (  ldrStatus <= 100  ) {
   analogWrite(LED , 0 );
}


    if ( (int)temperature >= 32 ) {
       digitalWrite(FAN, HIGH);
    } else if ( (int)temperature < 32 ) {
       digitalWrite(FAN, LOW);
    } 



// App works on the following data
Serial.print((int)temperature);
Serial.print(" C");
Serial.print("|");
Serial.print((int)humidity);
Serial.print(" %");
Serial.print("|");
      Serial.println(ldrStatus);
delay(2000);

}
