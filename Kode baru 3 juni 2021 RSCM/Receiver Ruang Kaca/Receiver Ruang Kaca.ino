
// See SoftwareSerial example 
// https://www.arduino.cc/en/tutorial/SoftwareSerialExample
//#define setPin 6
#include <SoftwareSerial.h>;
#define RX 11 //Connect to the TX pin of the HC-12
#define TX 10 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(TX,RX);
byte readState = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() { // run over and over
  if (mySerial.available()) {
      
    Serial.write(mySerial.read());
    
  }
  if (Serial.available()) {
    
    mySerial.write(Serial.read());
    
  }}
 
