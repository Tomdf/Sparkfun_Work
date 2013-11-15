// setup software serial on pins 8 (RX) and 4 (tx)
#include <SoftwareSerial.h>
SoftwareSerial Serial7Segment(8, 4); //RX pin, TX pin

// setup pin configuration
const char encoder0PinA = 3;
const char encoder0PinB = 2;
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
  attachInterrupt(0, doEncoderA, FALLING );
  Serial.begin (9600);
}

void loop(){  
  Serial.print(encoder0Pos);
}

void doEncoderA(){
  if (digitalRead(encoder0PinB) == HIGH) {
    digitalWrite(plusPin, HIGH);
    digitalWrite(plusPin, LOW);
    encoder0Pos += 1; 
  }
  else if (digitalRead(encoder0PinB) == LOW) {
    digitalWrite(minusPin, HIGH);
    digitalWrite(minusPin, LOW);
    encoder0Pos -= 1; 
  }
} 


