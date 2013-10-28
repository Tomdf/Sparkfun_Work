
byte led = 13;
int gatePin = A1;
int gateState = 0;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  pinMode(gatePin, INPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  gateState = analogRead(gatePin);
  Serial.println(gateState);
  delay(50);
}
