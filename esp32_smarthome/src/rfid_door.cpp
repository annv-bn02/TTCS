#include "rfid_door.h"
#include <ESP32Servo.h> 
#include <MFRC522.h>
#include <SPI.h>
#include "header.h"


Servo servo_door;
byte nuidPICC[4] = {0, 0, 0, 0};
MFRC522::MIFARE_Key key;
MFRC522 rfid = MFRC522(SS_PIN, RST_PIN);

const int ip[4] = { 212, 94, 20, 184}; //mã
uint8_t flag_checkRFID = 1;
int count_wrong = 0;
int count_buzzer = 0;
int count_light = 0;
uint8_t flag_open_door = 0;
uint8_t door = 0;
int pos = 0;
int i = 0;

void Setup_Door()
{
    pinMode( DOOR_LIGHT_PIN, OUTPUT);
    pinMode( DOOR_BUZZER_PIN, OUTPUT);
    servo_door.attach(DOOR_SERVO_PIN);
    servo_door.write(108);
}

void Start_RFID ()
{
    SPI.begin();
    rfid.PCD_Init();
    for (byte i = 0; i < 6; i++)
    {
        key.keyByte[i] = 0xFF;
    }
}

void Check_RFID() 
{
  for (byte i = 0; i < 6; i++) 
  {
    key.keyByte[i] = 0xFF;
  }
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (  !rfid.PICC_ReadCardSerial())
    return;
  for (byte i = 0; i < 4; i++) 
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }
  if ( nuidPICC[0] == ip[0] && nuidPICC[1] == ip[1] && nuidPICC[2] == ip[2] && nuidPICC[3] == ip[3] )
  {
    flag_open_door = 1;
  }
  else 
  {
    count_wrong++;
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void Open_Door()
{
  pos -= 4;
  if ( pos > -108 )
  {
    i = 108 - abs(pos);
  }
  else if ( pos <= -108 && pos > -308 )
  {
    i = 0;
  }
  else if ( pos <= -308 && pos > -416)
  {
    i = abs(pos) - 308;
  }
  else if ( pos == -416 )
  {
    i = 108;
    pos = 0;
    flag_open_door = 0;
  }
  servo_door.write(i);
}

void Wrong_RFID()
{
  if ( count_wrong >= 3)
  {
    digitalWrite(DOOR_BUZZER_PIN, HIGH);
    count_buzzer++;
    if ( count_buzzer >= 40 )
    {
      count_buzzer = 0;
      count_wrong = 0;
      digitalWrite(DOOR_BUZZER_PIN, LOW);
    }
  }
}

void Door_Light_Control()
{
  prox = digitalRead( PIN_PROX );
  if ( Night() == 1 && prox == 0)
  {
    digitalWrite( DOOR_LIGHT_PIN, HIGH);
  }
  else 
  {
    count_light++;
    if ( count_light >= 50)
    {
      count_light = 0;
      digitalWrite( DOOR_LIGHT_PIN, LOW);
    }  
  }
}