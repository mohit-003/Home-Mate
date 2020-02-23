int led = 12;
void setup()
{
pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop()

{

unsigned int AnalogValue;

AnalogValue = analogRead(A0);
Serial.println(AnalogValue);
if (AnalogValue > 50){
  digitalWrite(led,HIGH);
  Serial.println("Working");
}
else{
    digitalWrite(led,LOW);
}

delay(1000);
}
