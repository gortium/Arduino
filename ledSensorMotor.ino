int pinLed0 = 13;
int pinLed1 = 3;
int pinLed2 = 5;
int pinLed3 = 6;
int pinSensor = A5;
int pinMotor = 11;
int maxSensor = 0;
int minSensor = 1024;
int range = 0;

void setup()
{
 delay(2000);
 Serial.begin(9600);
 
 pinMode(pinSensor, INPUT);
 pinMode(pinLed1, OUTPUT);
 pinMode(pinLed2, OUTPUT);
 pinMode(pinLed3, OUTPUT);
 pinMode(pinMotor, OUTPUT);
 pinMode(pinLed0, OUTPUT);
 
 while(millis() <= 5000)
 {
   delay(100);
   
   digitalWrite(pinLed0, HIGH);
   
   minSensor = min(minSensor,analogRead(pinSensor));
   maxSensor = max(maxSensor,analogRead(pinSensor));
   
   Serial.print("min = ");
   Serial.print(minSensor);
   Serial.print("  max = ");
   Serial.println(maxSensor);
   
   digitalWrite(pinLed0, LOW);
 }
 
 range = ((maxSensor - minSensor)/5);
 
 Serial.print("range = ");
 Serial.println(range);
}

void loop()
{
  int sensor = 0, led1 = 0, led2 = 0, led3 = 0, motor = 0;
  
  sensor = analogRead(pinSensor);
  sensor = constrain(sensor,minSensor,maxSensor);  
  
  if(sensor >= (minSensor + range))
  {
  led1 = sensor;
  led1 = constrain(led1,(minSensor + range),(minSensor + 2*range));
  led1 = map(led1,(minSensor + range),(minSensor + 2*range),0,255);
  led1 = constrain(led1,0,255);
  }
  else
  {
    led1 = 0;
  }
  if(sensor >= (minSensor + (2*range)))
  {
  led2 = sensor;
  led2 = constrain(led2,(minSensor + 2*range),(minSensor + 3*range));
  led2 = map(led2,(minSensor + 2*range),(minSensor + 3*range),0,255);
  led2 = constrain(led2,0,255);
  }
  else
  {
    led2 = 0;
  }
  if(sensor >= (minSensor + (3*range)))
  {
  led3 = sensor;
  led3 = constrain(led3,(minSensor + 3*range),(minSensor + 4*range));
  led3 = map(led3,(minSensor + 3*range),(minSensor + 4*range),0,255);
  led3 = constrain(led3,0,255);
  }
    else
  {
    led3 = 0;
  }
  
  if(sensor >= (minSensor + range - 60))
  {
  motor = sensor;
  motor = constrain(motor,(minSensor + range - 60),maxSensor);
  motor = map(motor,(minSensor + range - 60),maxSensor,0,255);
  }
  else
  {
    motor = 0;
  }

  analogWrite(pinLed1,led1);
  analogWrite(pinLed2,led2);
  analogWrite(pinLed3,led3);
  analogWrite(pinMotor,motor);
  
  Serial.print("sensor = ");
  Serial.print(sensor);
  Serial.print(" motor = ");
  Serial.print(motor);
  Serial.print("  led 1 = ");
  Serial.print(led1);
  Serial.print("  led 2 = ");
  Serial.print(led2);
  Serial.print("  led 3 = ");
  Serial.println(led3);
  
  delay(100);
}

