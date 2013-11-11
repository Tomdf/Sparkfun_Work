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
  attachInterrupt(0, doEncoderA, CHANGE);
  // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(1, doEncoderB, CHANGE); 
  
  Serial.begin (9600);
}

void loop(){  
  // trying to get this to send a pulse out to the seven segment board
  // but I don't think this will work. Maybe I can modify the interrupts?
  if (encoder0Pos == 4){
    digitalWrite(plusPin, HIGH);
    digitalWrite(plusPin, LOW);
}

void doEncoderA(){
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {  
      encoder0Pos = encoder0Pos + 1;         // CW
      Serial.println(encoder0Pos);
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else {  // must be a high-to-low edge on channel A
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder0PinB) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }

  // use for debugging - remember to comment out
  // Serial.println (encoder0Pos, DEC);          
}

void doEncoderB(){
  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {   
    // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder0PinA) == LOW) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
} 

