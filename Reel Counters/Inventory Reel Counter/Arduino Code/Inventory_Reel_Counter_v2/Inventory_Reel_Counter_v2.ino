
byte led = 13;
int gatePin = A5;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  pinMode(gatePin, INPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int gateState = digitalRead(gatePin);
  Serial.println(gateState);
  delay(50);
}

