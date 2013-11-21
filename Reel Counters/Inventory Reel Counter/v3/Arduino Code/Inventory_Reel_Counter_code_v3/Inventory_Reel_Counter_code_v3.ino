// setup software serial on pins 8 (RX) and 4 (tx)
#include <SoftwareSerial.h>
SoftwareSerial Serial7Segment(8, 4); //RX pin, TX pin

// setup pin configuration
const char detectorPIN = 2;

volatile unsigned int count = 0;

void setup() {
  pinMode(detectorPIN, INPUT); 
  // detector pin on interrupt 0 (pin 2)
  // interrupt when the sensor transistions from 
  // high to low
  attachInterrupt(0, doCount, FALLING);
  Serial.begin (9600);
  Serial7Segment.begin(9600); //Talk to the Serial7Segment at 9600 bps
  Serial7Segment.write('v'); //Reset the display - this forces the cursor to return to the beginning of the display
  Serial7Segment.write(count);
  delay(10);
}

void loop(){  
  /* Bunny Rabbit  
   ()()
   =(-,-)=
   (")_(") 
   */
}

void doCount(){
  count += 1;
  Serial.println(count);
  Serial7Segment.write('v'); //Reset the display - this forces the cursor to return to the beginning of the display
  Serial7Segment.print(count);
} 





