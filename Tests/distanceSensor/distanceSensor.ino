int pinEcho = 4, pinTrig = 2;

void setup()
{
 Serial.begin(9600);
 
 pinMode(pinEcho, INPUT);
 pinMode(pinTrig, OUTPUT);
}

void loop()
{
  long microseconds = 0, cm =0;
  
  digitalWrite(pinTrig, LOW);
  delay(2);
  digitalWrite(pinTrig, HIGH);
  delay(10);
  digitalWrite(pinTrig, LOW);
  
  microseconds = pulseIn(pinEcho, HIGH);

  cm = microSecToCm(microseconds);
  
  Serial.print(cm);
  Serial.println(" cm");
  
  delay(50);
}

long microSecToCm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

