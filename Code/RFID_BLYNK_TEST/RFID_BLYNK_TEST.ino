#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D4
#define RST_PIN D3

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

char auth[] = "l2AvNgrAAvaqCGDBLgs-EtD7ccxOH1X9";
char ssid[] = "azrihaziq";
char pass[] = "12345678";

BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(D8, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,notify);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void notify()
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
  String content = "";
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
  if (content.substring(1) == "92 6C 8D 47") 
  {
    Serial.println("Authorized access");
    Serial.println();
    Blynk.notify("AZRI HAZIQ (2180176) CHECKED IN");
    digitalWrite(D8, HIGH);
    digitalWrite(D2, HIGH);
    delay(100);
    digitalWrite(D8, LOW);
    digitalWrite(D2, LOW);
    delay(100);
    digitalWrite(D8, HIGH);
    digitalWrite(D2, HIGH);
    delay(100);
    digitalWrite(D8, LOW);
    digitalWrite(D2, LOW);
//    delay(2000);
  }

  else if (content.substring(1) == "52 00 89 47")
  {
    Serial.println("Authorized access");
    Serial.println();
    Blynk.notify("AKMAL HANIF (2180130) CHECKED IN");
    digitalWrite(D8, HIGH);
    digitalWrite(D2, HIGH);
    delay(100);
    digitalWrite(D8, LOW);
    digitalWrite(D2, LOW);
    delay(100);
    digitalWrite(D8, HIGH);
    digitalWrite(D2, HIGH);
    delay(100);
    digitalWrite(D8, LOW);
    digitalWrite(D2, LOW);
//    delay(2000);
  }

  else   {
    Serial.println(" Access denied");
    digitalWrite(D8, HIGH);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(100);
    digitalWrite(D0, HIGH);
    delay(100);
    digitalWrite(D0, LOW);
    delay(1000);
    digitalWrite(D8, LOW);
  }  
}
