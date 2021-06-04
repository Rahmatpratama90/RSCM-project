#include "Adafruit_VL53L0X.h"
  #include <SoftwareSerial.h>
 // #define setPin 6
  SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox4 = Adafruit_VL53L0X();
//Adafruit_VL53L0X lox5 = Adafruit_VL53L0X();
int measure1= 0;
int rate=0;
int state =0;
  int measure2 = 0;
  int measure3 = 0;
  int measure4 = 0;
  int measure5 = 0;
  int measure6 = 0;
  int measure7 = 0;
  int measure8 = 0;
  int measure9 = 0;

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox1.begin()) {
    Serial.println(F("Failed to boot VL53L0X "));
    while(1);
  }

else if  (!lox2.begin()) {
    Serial.println(F("Failed to boot VL53L0X "));
    while(1);
  }

 /* else if  (!lox3.begin()) {
    Serial.println(F("Failed to boot VL53L0X "));
    while(1);
  }

  
 else if  (!lox4.begin()) {
    Serial.println(F("Failed to boot VL53L0X "));
    while(1);
  }

 /*   else if  (!lox5.begin()) {
    Serial.println(F("Failed to boot VL53L0X 5"));
    while(1);
  }*/
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure_1;
 VL53L0X_RangingMeasurementData_t measure_2;
      //VL53L0X_RangingMeasurementData_t measure_3;
         // VL53L0X_RangingMeasurementData_t measure_4;
           //  VL53L0X_RangingMeasurementData_t measure_5;
  Serial.println("Reading a measurement... ");
  lox1.rangingTest(&measure_1, false); // pass in 'true' to get debug data printout!
 lox2.rangingTest(&measure_2, false);
 //lox3.rangingTest(&measure_3, false);
  //lox4.rangingTest(&measure_4, false);
     // lox5.rangingTest(&measure_5, false);
  if (measure_1.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance 1 (mm): "); Serial.println(measure_1.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }

 if (measure_2.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance 2 (mm): "); Serial.println(measure_2.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }

 /*if (measure_3.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance 3 (mm): "); Serial.println(measure_3.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }

     if (measure_4.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance 4 (mm): "); Serial.println(measure_4.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }

  /*   if (measure_5.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance 5 (mm): "); Serial.println(measure_5.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }*/
        char strgabungan[50];
        measure1= measure_1.RangeMilliMeter;
        rate = rate + measure1;
        measure2= measure_2.RangeMilliMeter;
        rate = rate + measure2;
        measure3= measure2;
        rate = rate + measure3;
        measure4=measure3;
        rate = rate + measure4;
        measure5=    measure4;
        rate = rate + measure5;
        measure6= measure5;
            rate = rate + measure6;
        measure7= measure6;
            rate = rate + measure7;
        measure8= measure7;
            rate = rate + measure8;
        measure9= measure8;
            rate = rate + measure9;
        rate = rate / 9;
        
      sprintf(strgabungan, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;", measure1,measure2,measure3,measure4,measure5,measure6,measure7,measure8,measure9,rate,state);
     //  sprintf(strgabungan, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d", measure1,measure2,measure3,measure4,measure5,measure6,measure7,measure8,measure9,rate,state);
    //serial.println(" String gabungan :");
    HC12.println(strgabungan);
  delay(100);
}
