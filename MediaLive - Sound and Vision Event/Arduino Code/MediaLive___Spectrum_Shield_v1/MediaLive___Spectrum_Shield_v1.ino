	
// Example 48.1 - tronixstuff.com/tutorials > chapter 48 - 30 Jan 2013
// MSGEQ7 spectrum analyser shield - basic demonstration
byte strobe = 4; // strobe pins on digital 4
byte res = 5; // reset pins on digital 5
byte pot = A5;
byte leftRED = 11; // the red led for the left channel
byte leftGRN = 10;
byte leftBLUE = 9;
byte leftRedValue;
byte leftBlueValue;
byte leftGrnValue;
int pause;

int left[7]; // store band values in these arrays
int right[7];
int band;
void setup()
{
Serial.begin(115200);
pinMode(pot, INPUT);
pinMode(leftRED, OUTPUT);
pinMode(leftGRN, OUTPUT);
pinMode(leftBLUE, OUTPUT);
pinMode(res, OUTPUT); // reset
pinMode(strobe, OUTPUT); // strobe
digitalWrite(res,LOW); // reset low
digitalWrite(strobe,HIGH); //pin 5 is RESET on the shield
}

void loop()
{
  readMSGEQ7();
  // display values of left channel on serial monitor
  for (band = 0; band < 7; band++)
  {
   // Serial.print(left[band]);
   // Serial.print(" ");
  }
  if (left[3] < 700) {
    leftRedValue = 0;
  }
  else {
  leftRedValue = map(left[3], 700, 1200, 0, 255);
  }
  if (left[4] < 700) {
    leftGrnValue = 0;
  }
  else {
  leftGrnValue = map(left[4], 700, 1200, 0, 255);
  }
  if (left[3] < 700) {
    leftBlueValue = 0;
  }
  else {
  leftBlueValue = map(left[5], 700, 1200, 0, 255);
  }
  Serial.print(leftRedValue);
  Serial.println();
  analogWrite(leftRED, leftRedValue);
  analogWrite(leftGRN, leftGrnValue);
  analogWrite(leftBLUE, leftBlueValue);
  
  pause = analogRead(pot);
  Serial.println(pause);
  delay(pot);
     analogWrite(leftRED, 0);
  analogWrite(leftGRN, 0);
  analogWrite(leftBLUE, 0);

  // display values of right channel on serial monitor
  for (band = 0; band < 7; band++)
  {
   // Serial.print(right[band]);
   // Serial.print(" ");
  }
  //Serial.println();
}

void readMSGEQ7()
// Function to read 7 band equalizers
{
  digitalWrite(res, HIGH);
  digitalWrite(res, LOW);
  for(band=0; band <7; band++)
  {
    digitalWrite(strobe,LOW); // strobe pin on the shield - kicks the IC up to the next band
    delayMicroseconds(30); //
    left[band] = analogRead(0); // store left band reading
    right[band] = analogRead(1); // ... and the right
    digitalWrite(strobe,HIGH);
  }
}

