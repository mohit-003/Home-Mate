#include <SPI.h>
#include <MFRC522.h>
               #include <Servo.h>
                Servo name_servo;
#define SS_PIN 10
#define RST_PIN 9

                int Red_LED = 2;
                int Green_LED = 4;
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
                int servo_position = 0; // Servo motor position
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
                  pinMode(Green_LED , OUTPUT);
                  pinMode(Red_LED , OUTPUT);
  Serial.println("Put your card to the reader...");
  Serial.println();
                name_servo.attach (6); // Pin of servo motor
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX); 
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "14 36 EA 2B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
              delay(1);
              digitalWrite(Green_LED , HIGH);
              
                        
    delay(ACCESS_DELAY);
    
                    for (servo_position = 0; servo_position <= 180; servo_position++)
                    {
                      name_servo.write(servo_position);
                      delay(1);
                    }
                    delay(1000);
                    for (servo_position = 180; servo_position >= 0; servo_position--)
                    {
                      name_servo.write(servo_position);
                      delay(1); 
                    }   
                    digitalWrite(Green_LED , LOW);  
  }
 
 else   {
    Serial.println(" Access denied");
               digitalWrite(Red_LED , HIGH);
               delay(1000);
    delay(DENIED_DELAY);
               digitalWrite(Red_LED , LOW);
   
  }
}
