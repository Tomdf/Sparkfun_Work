char QRE1113_Pin = 2; //connected to digital 2
int count;
boolean gapOne = false;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  int QRE_Value = readQD();
  if (QRE_Value >= 2000 && gapOne == false)
  {
    count = count++;
    gapOne = true;
    Serial.println(count);
  }
  if (QRE_Value < 750 && gapOne == true)
  {
    gapOne = false;
  }
  //Serial.println(QRE_Value);
}


int readQD()
{
  //Returns value from the QRE1113 
  //Lower numbers mean more refleacive
  //More than 3000 means nothing was reflected.
  pinMode( QRE1113_Pin, OUTPUT );
  digitalWrite( QRE1113_Pin, HIGH );  
  delayMicroseconds(10);
  pinMode( QRE1113_Pin, INPUT );

  long time = micros();

  //time how long the input is HIGH, but quit after 3ms as nothing happens after that
  while (digitalRead(QRE1113_Pin) == HIGH && micros() - time < 3000); 
  int diff = micros() - time;

  return diff;
}
