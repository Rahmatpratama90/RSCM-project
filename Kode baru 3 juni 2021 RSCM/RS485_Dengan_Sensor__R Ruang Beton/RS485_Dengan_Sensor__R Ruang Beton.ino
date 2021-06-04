
#define SLAVE_EN  3

void setup() {
  pinMode(LED_BUILTIN , OUTPUT);                        // Declare LED pin as output
  pinMode(SLAVE_EN , OUTPUT);                   // Declare Enable pin as output
  Serial.begin(9600);                           // set serial communication baudrate 
  digitalWrite(SLAVE_EN , LOW);                 // Make Enable pin low
                                                // Receiving mode ON 
}

void loop() {
  while(Serial.available())                     // If serial data is available then enter into while loop
  {
    Serial.write(Serial.read());
    
  }
}
