#include "Adafruit_VL53L0X.h"
#define MASTER_EN   3   // connected to RS485 Enable pin
#define LOX1_ADDRESS 0x30
#define LOX2_ADDRESS 0x31
//#define LOX3_ADDRESS 0x32
//#define LOX4_ADDRESS 0x33
/*#define LOX5_ADDRESS 0x34
#define LOX6_ADDRESS 0x35
#define LOX7_ADDRESS 0x36
#define LOX8_ADDRESS 0x37
#define LOX9_ADDRESS 0x38*/
/// set the pins to shutdown
#define SHT_LOX1 2
#define SHT_LOX2 4
//#define SHT_LOX3 5
//#define SHT_LOX4 6;
/*#define SHT_LOX5 7
#define SHT_LOX6 8
#define SHT_LOX7 9
#define SHT_LOX8 10
#define SHT_LOX9 11*/
const int pushButton = 12;
const int LED = 13;
int rate = 0;
int pusher = 0;
int state = 0;
#include <Adafruit_VL53L0X.h>
#include <Wire.h>
// objects for the vl53l0x
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
/*Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox4 = Adafruit_VL53L0X();
/*Adafruit_VL53L0X lox5 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox6 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox7 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox8 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox9 = Adafruit_VL53L0X();*/
// this holds the measurement
VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;
/*VL53L0X_RangingMeasurementData_t measure3;
VL53L0X_RangingMeasurementData_t measure4;
/*VL53L0X_RangingMeasurementData_t measure5;
VL53L0X_RangingMeasurementData_t measure6;
VL53L0X_RangingMeasurementData_t measure7;
VL53L0X_RangingMeasurementData_t measure8;
VL53L0X_RangingMeasurementData_t measure9;*/


/*
    Reset all sensors by setting all of their XSHUT pins low for delay(10), then set all XSHUT high to bring out of reset
    Keep sensor #1 awake by keeping XSHUT pin high
    Put all other sensors into shutdown by pulling XSHUT pins low
    Initialize sensor #1 with lox.begin(new_i2c_address) Pick any number but 0x29 and it must be under 0x7F. Going with 0x30 to 0x3F is probably OK.
    Keep sensor #1 awake, and now bring sensor #2 out of reset by setting its XSHUT pin high.
    Initialize sensor #2 with lox.begin(new_i2c_address) Pick any number but 0x29 and whatever you set the first sensor to
 */
char strgabungan[50];


int measure_1= 0;
  int measure_2 = 0;
  int measure_3 = 0;
  int measure_4 = 0;
  int measure_5 = 0;
  int measure_6 = 0;
  int measure_7 = 0;
  int measure_8 = 0;
  int measure_9 = 0;
  
void setID() {
  // all reset
  digitalWrite(SHT_LOX1, LOW);    
 digitalWrite(SHT_LOX2, LOW);
  /*digitalWrite(SHT_LOX3, LOW);
  digitalWrite(SHT_LOX4, LOW);    
 /* digitalWrite(SHT_LOX5, LOW);
  digitalWrite(SHT_LOX6, LOW);
  digitalWrite(SHT_LOX7, LOW);    
  digitalWrite(SHT_LOX8, LOW);
  digitalWrite(SHT_LOX9, LOW);*/
  delay(10);
  // all unreset
digitalWrite(SHT_LOX1, HIGH);
  digitalWrite(SHT_LOX2, HIGH);
  /*digitalWrite(SHT_LOX3, HIGH);
  digitalWrite(SHT_LOX4, HIGH);
  /*digitalWrite(SHT_LOX5, HIGH);
  digitalWrite(SHT_LOX6, HIGH);
  digitalWrite(SHT_LOX7, HIGH);
  digitalWrite(SHT_LOX8, HIGH);
  digitalWrite(SHT_LOX9, HIGH);*/
  delay(10);

  // activating LOX1 and reseting LOX2
  digitalWrite(SHT_LOX1, HIGH);
digitalWrite(SHT_LOX2, LOW);
  /*digitalWrite(SHT_LOX3, LOW);
  digitalWrite(SHT_LOX4, LOW);
 /* digitalWrite(SHT_LOX5, LOW);
  digitalWrite(SHT_LOX6, LOW);
  digitalWrite(SHT_LOX7, LOW);
  digitalWrite(SHT_LOX8, LOW);
  digitalWrite(SHT_LOX9, LOW);*/
  
//digitalWrite(SHT_LOX1, HIGH);
  delay(10);
  // initing LOX1
  if(!lox1.begin(LOX1_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  // activating LOX2
  digitalWrite(SHT_LOX2, HIGH);
  delay(10);

  //initing LOX2
  if(!lox2.begin(LOX2_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  /*digitalWrite(SHT_LOX3, HIGH);
  delay(10);
  
 //initing LOX3
  if(!lox3.begin(LOX3_ADDRESS)) {
    while(1);

      delay(10);
  digitalWrite(SHT_LOX4, HIGH);
  delay(10);


     //initing LOX4
  if(!lox4.begin(LOX4_ADDRESS)) {
    while(1);
  }
  
  delay(10);
 /*8 digitalWrite(SHT_LOX5, HIGH);
  delay(10);

   //initing LOX5
  if(!lox5.begin(LOX5_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  digitalWrite(SHT_LOX6, HIGH);
  delay(10);

   //initing LOX6
  if(!lox6.begin(LOX6_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  digitalWrite(SHT_LOX7, HIGH);
  delay(10);

  if(!lox7.begin(LOX7_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  digitalWrite(SHT_LOX8, HIGH);
  delay(10);
   if(!lox8.begin(LOX8_ADDRESS)) {
    while(1);
  }
  
  delay(10);
  digitalWrite(SHT_LOX9, HIGH);
  delay(10);

   if(!lox9.begin(LOX9_ADDRESS)) {
    while(1);
  }
  
  delay(10);
*/
  }
void read_dual_sensors() {
 
 
 lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
 lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
 /* lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  lox4.rangingTest(&measure4, false); // pass in 'true' to get debug data printout!
/*  lox5.rangingTest(&measure5, false); // pass in 'true' to get debug data printout!
  lox6.rangingTest(&measure6, false); // pass in 'true' to get debug data printout!
  lox7.rangingTest(&measure7, false); // pass in 'true' to get debug data printout!
  lox8.rangingTest(&measure8, false); // pass in 'true' to get debug data printout!
  lox9.rangingTest(&measure9, false); // pass in 'true' to get debug data printout!*/
 state = digitalRead(pushButton);
  
   //Serial.print(F("1: "));
  if(measure1.RangeStatus != 4) {     // if not out of range
  //  Serial.println(measure1.RangeMilliMeter);
  } else {
   // Serial.print(F("Out of range"));
  }
  
 // Serial.print(F(" "));

  // print sensor two reading
  //Serial.print(F("2: "));
 if(measure2.RangeStatus != 4) {
  //  Serial.println(measure2.RangeMilliMeter);
  } else {
   // Serial.print(F("Out of range"));
  }

    // print sensor three reading
 /* Serial.print(F("3: "));
  if(measure3.RangeStatus != 4) {
    Serial.print(measure3.RangeMilliMeter);
  } else {
    Serial.print(F("Out of range"));
  }

    // print sensor four reading
  Serial.print(F("4: "));
  if(measure4.RangeStatus != 4) {
    Serial.print(measure4.RangeMilliMeter);
  } else {
    Serial.print(F("Out of range"));
  }

  /*  // print sensor five reading
  //8Serial.print(F("5: "));
  if(measure5.RangeStatus != 4) {
    Serial.print(measure5.RangeMilliMeter);
  } else {
    Serial.print(F("Out of range"));
  }
  Serial.println();*/

  


if(state == LOW){
    delay(10);
    pusher = 1;
    digitalWrite(LED, HIGH);
    if(state == LOW ){
      pusher = 1;
    }
  } 
  else {
    digitalWrite(LED, LOW);
    pusher = 0;
  }
}
void setup() {
  pinMode(LED_BUILTIN , OUTPUT);            // Declare LED pin as output
  pinMode(MASTER_EN , OUTPUT);      // Declare Enable pin as output
  Serial.begin(9600);               // set serial communication baudrate 
  digitalWrite(MASTER_EN , LOW);    // Make Enable pin low                                   // Receiving mode ON 

 

  while (! Serial) {
    delay(10);
  }

  
  pinMode(SHT_LOX1, OUTPUT);
  pinMode(SHT_LOX2, OUTPUT);

    digitalWrite(SHT_LOX1, LOW);
  digitalWrite(SHT_LOX2, LOW);

  
 /*Serial.println("Adafruit VL53L0X test");
  if (!lox1.begin()) {
    Serial.println(F("Failed to boot VL53L0X1"));
    while(1);
  } 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
    Serial.println("Adafruit VL53L0X test");

if (!lox2.begin()) {
    Serial.println(F("Failed to boot VL53L0X 2"));
    while(1);
  } 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
    Serial.println("Adafruit VL53L0X test");
    //3
    /*if (!lox3.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  } 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
    Serial.println("Adafruit VL53L0X test");
}
//4
if (!lox4.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  } 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
    Serial.println("Adafruit VL53L0X test");


/*5
if (!lox5.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  } 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
    Serial.println("Adafruit VL53L0X test");

Serial.println(F("Shutdown pins inited..."));


  digitalWrite(SHT_LOX1, LOW);
  digitalWrite(SHT_LOX2, LOW);
 /* digitalWrite(SHT_LOX3, LOW);
  digitalWrite(SHT_LOX4, LOW);
 /* digitalWrite(SHT_LOX5, LOW);
  digitalWrite(SHT_LOX6, LOW);
  digitalWrite(SHT_LOX7, LOW);
  digitalWrite(SHT_LOX8, LOW);
  digitalWrite(SHT_LOX9, LOW);*/

 pinMode(LED, OUTPUT);
 pinMode(pushButton, INPUT_PULLUP);
  setID();
}

void loop() {
    digitalWrite(MASTER_EN , HIGH); 
  read_dual_sensors();
 // measure_1 = 10;
measure_1 = measure1.RangeMilliMeter;

    rate = rate + measure_1;

  

 measure_2 = measure2.RangeMilliMeter;
// measure_2 = measure_1;
    rate = rate + measure_2;

   measure_3 = measure_2;
    rate = rate + measure_3;


    measure_4 = measure_3;
    rate = rate + measure_4;

  
  measure_5 = measure_4;
    rate = rate + measure_5;
   
    measure_6 = measure_5;
    rate = rate + measure_6;
    
    measure_7 = measure_6;

    measure_8 = measure_7;
    rate = rate + measure_8;

    measure_9 = measure_8;
    rate = rate + measure_9;
     sprintf(strgabungan, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;", measure_1,measure_2,measure_3,measure_4,measure_5,measure_6,measure_7,measure_8,measure_9,rate,pusher);
      Serial.println(strgabungan);
  
     Serial.flush();                     // wait for transmission of data
  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
  delay(100);
 
}
