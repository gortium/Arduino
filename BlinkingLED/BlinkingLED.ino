// TEST PROGRAMME
// BLINKING LED ONBBORAD

int ledPin = 11;
  
void setup()
{
  pinMode(ledPin,OUTPUT);
  analogWrite(ledPin,0);
}

void loop()
{
  int a =0;
  for(a=0;a<=50;a)
  {
    analogWrite(ledPin,a);
    delay(50);
    a+=2;
  }
    for(a=50;a>=0;a)
  {
    analogWrite(ledPin,a);
    delay(50);
    a-=2;
  }
  delay(300);
  
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(300);
}
