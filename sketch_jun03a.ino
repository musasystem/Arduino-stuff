#include <AltSoftSerial.h>
String inData;
String light;
String boot;
char incomingByte;
const int LED = 10;
const int SLED = 11;
const int RELAY = 7;
AltSoftSerial GoMySerial;

void setup(){
pinMode(LED,OUTPUT);
pinMode(SLED,OUTPUT);
pinMode(RELAY,OUTPUT);
Serial.begin(115200);
boot="0";
GoMySerial.begin(115200);
// GoMySerial.println("AT+IPR=115200");
GoMySerial.println("AT");
light = "off";
digitalWrite(SLED, HIGH);
digitalWrite(RELAY, HIGH);
}
 
void loop(){
  if (boot=="0") {
GoMySerial.println("AT+CMGF=1");
delay(2000);
GoMySerial.println("AT+CMGF=1");
delay(3000); 
GoMySerial.println("AT+CMGF=1");
delay(2000); 
GoMySerial.println("at+cscs=\"gsm\"");
delay(2000); 
GoMySerial.println("at+cscs=\"gsm\"");
delay(2000); 
GoMySerial.println("at+cscs=\"gsm\"");
delay(2000);
GoMySerial.println("AT+CMGF=1");
delay(2000); 
GoMySerial.println("AT+CNMI=2,2,0,0,0");
delay(2000);
GoMySerial.println("AT+CNMI=2,2,0,0,0");
delay(2000);
GoMySerial.println("AT+CNMI=2,2,0,0,0");
delay(2000);
GoMySerial.println("AT+CNMI=2,2,0,0,0");
digitalWrite(SLED, LOW);
boot="1";
  }
  if (Serial.available()) GoMySerial.write(Serial.read());
    while (GoMySerial.available() > 0)
    {
delay(10);
        incomingByte = GoMySerial.read();
        // if (incomingByte=='\n') incomingByte='v';
        inData += incomingByte; 
    }
      if(inData != "")
   {
     Serial.print("Answer:");
     if (inData.indexOf("open") >= 0) {
      digitalWrite(LED, HIGH);
      digitalWrite(RELAY, LOW);
      GoMySerial.println("atz");
      delay(200);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(11000);
      GoMySerial.println("ath");
       delay(200);
      GoMySerial.println("ath");
       delay(200);
      GoMySerial.println("ath");
     }
     if (inData.indexOf("close") >= 0) {
      digitalWrite(LED, LOW);
      digitalWrite(RELAY, HIGH);
      GoMySerial.println("atz");
      delay(200);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(500);
      GoMySerial.println("atd0664133630;");
      delay(11000);
      GoMySerial.println("ath");
       delay(200);
      GoMySerial.println("ath");
       delay(200);
      GoMySerial.println("ath");
     }
     Serial.print(inData);
     Serial.print("\n");
   }
   inData = "";
}
