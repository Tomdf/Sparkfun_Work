// setup software serial on pins 8 (RX) and 4 (tx)
#include <SoftwareSerial.h>
SoftwareSerial Serial7Segment(8, 4); //RX pin, TX pin

#define MODE_CMD 0x82
#define MODE_DATA 0
#define MODE_ANALOG 1
#define MODE_COUNTER 2

int cycles = 0;

// setup pin configuration
const char encoder0PinA = 2;
const char encoder0PinB = 3;
const char plusPin = 5;
const char minusPin = 7;

volatile unsigned int encoder0Pos = 0;

void setup() {
  pinMode(encoder0PinA, INPUT); 
  pinMode(encoder0PinB, INPUT); 
  pinMode(plusPin, OUTPUT);
  pinMode(minusPin, OUTPUT);

  // encoder pin on interrupt 0 (pin 2)
  // interrupt when the first sensor transistions
  // from blocked to slot
  attachInterrupt(0, doEncoderA, FALLING);
  Serial.begin (9600);
  Serial7Segment.begin(9600); //Talk to the Serial7Segment at 9600 bps
  Serial7Segment.write('v'); //Reset the display - this forces the cursor to return to the beginning of the display
  delay(10);
  Serial7Segment.write(MODE_CMD); //Change the mode of the display
  Serial7Segment.write(MODE_COUNTER); //Enter counter mode. Any pulse on SDI will go up. Any pulse on SDO will go down.
}

void loop(){  
  Serial.println(encoder0Pos);
}

void doEncoderA(){
  if (digitalRead(encoder0PinB) == LOW) {
    //digitalWrite(plusPin, HIGH);
    //digitalWrite(plusPin, LOW);
    encoder0Pos -= 1; 
  }
  else if (digitalRead(encoder0PinB) == HIGH) {
    //digitalWrite(minusPin, HIGH);
    //digitalWrite(minusPin, LOW);
    encoder0Pos += 1; 
  }
} 


