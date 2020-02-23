#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11;
#define light (A1)
int lvl;
void setup() {
Serial.begin(9600);
}

void loop() {

byte temperature = 0;
byte humidity = 0;
if (dht11.read(pinDHT11, &temperature, &humidity, NULL))
{
return;
}
lvl = analogRead(light);
Serial.print((int)temperature);
Serial.print(" C");
Serial.print("|");
Serial.print((int)humidity);
Serial.print(" %");
Serial.print("|");
Serial.println(lvl);
delay(5000);
}
