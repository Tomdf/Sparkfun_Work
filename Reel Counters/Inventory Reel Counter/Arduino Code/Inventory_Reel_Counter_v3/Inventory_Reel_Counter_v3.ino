char gatePin = 2; //connected to digital 2
int count;
boolean gateOne = false;

void setup()
{
  pinMode(gatePin, INPUT);
  Serial.begin(9600);
}


void loop()
{
  int gateState = digitalRead(gatePin);
  if (gateState == true && gateOne == false)
  {
    count = count++;
    gateOne = true;
    Serial.println(count);
  }
  if (gateState == false && gateOne == true)
  {
    gateOne = false;
  }
}



