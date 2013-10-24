
byte led = 13;
byte gatePin = 2;
boolean gateState = LOW;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  pinMode(gatePin, INPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  gateState = digitalRead(gatePin);
  digitalWrite(led, gateState);
  Serial.println(gateState);
  delay(50);
}
