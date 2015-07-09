int pinLed1 = 3, pinLed2 = 5, pinLed3 = 6, pinSensor = A5, pinButton = 0; // Pin 2
volatile int choixLed = 1;

void setup()
{
 Serial.begin(9600);
 
 pinMode(A5, INPUT);
 pinMode(2, INPUT);
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 
 attachInterrupt(pinButton, choix, RISING);
}

void choix()
{
  if(choixLed == 1)
  {
    choixLed = 2;
  }
  else if(choixLed == 2)
  {
    choixLed = 3;
  }
  else if(choixLed == 3)
  {
    choixLed = 4;
  }
  else if(choixLed == 4)
  {
    choixLed = 1;
  }
  return;
}
void loop()
{
  int sensor = 0, led = 0;
  
  sensor = analogRead(pinSensor);
  sensor = constrain(sensor,600,900);  
  
  led = map(sensor, 600, 800, 255, 0);
  led = constrain(led, 0, 255);
  
  Serial.print("sensor = ");
  Serial.print(sensor);
  Serial.print("  led = ");
  Serial.println(led);
  
  if(choixLed == 1)
  {
    analogWrite(pinLed1, led);
  }
  else if(choixLed == 2)
  {
    analogWrite(pinLed2, led);
  }
  else if(choixLed == 3)
  {
    analogWrite(pinLed3, led);
  }

  delay(100);
}

