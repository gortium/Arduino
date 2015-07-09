#include <Servo.h>

Servo S1;
Servo S2;
Servo S3;

int pinS1 = 9;
int pinS2 = 10;
int pinS3 = 11;
int angleS1 = 90;
int angleS2 = 90;
int angleS3 = 90;

char choixServo;
int vitesse = 10;
unsigned char lAngle;
unsigned char mAngle;
unsigned char hAngle;
unsigned int choixAngle1 = 90;
unsigned int lastAngle1 = 90;
unsigned int choixAngle2 = 90;
unsigned int lastAngle2 = 90;
unsigned int choixAngle3 = 90;
unsigned int lastAngle3 = 90;

void setup()
{
  Serial.begin(9600);
  
  S1.attach(pinS1);
  S2.attach(pinS2);
  S3.attach(pinS3);
  
 pinMode(pinS3,11);
 pinMode(pinS2,10);
 pinMode(pinS1,9);
}

void loop()
{
  Serial.println("[# du servo][space][angle]");
  
  while(true)
  {
    if (Serial.available() >= 2)
    {
      choixServo = Serial.read();
      delay(250);
      if(choixServo == '1')
      {
        Serial.read();
        hAngle = ((Serial.read() - 48)*100);
        mAngle = ((Serial.read() - 48)*10);
        lAngle = (Serial.read() - 48);
        choixAngle1 = hAngle + mAngle + lAngle;
        break;
      }
      else if(choixServo == '2')
      {
        Serial.read();
        hAngle = ((Serial.read() - 48)*100);
        mAngle = ((Serial.read() - 48)*10);
        lAngle = (Serial.read() - 48);
        //        if(lAngle == (32-48))
//        {
//          lAngle = mAngle/10;
//          mAngle = hAngle/10;
//          hAngle = 0;
//        }
        choixAngle2 = hAngle + mAngle + lAngle;
        Serial.println("Angle:");
        Serial.println(choixAngle2);
        break;
      }
      else if(choixServo == '3')
      {
        Serial.read();
        hAngle = ((Serial.read() - 48)*100);
        mAngle = ((Serial.read() - 48)*10);
        lAngle = (Serial.read() - 48);
        choixAngle3 = hAngle + mAngle + lAngle;
        Serial.println("Angle:");
        Serial.println(choixAngle3);
        break;
      }
      else
      {
        Serial.println("non valide !");
      }
    }
  }
    if(choixServo == '1')
    {
      Serial.print("Servo 1 ");
      choixAngle1 = constrain(choixAngle1,0,180);
      Serial.println("Angle:");
      Serial.println(choixAngle1);
      if(choixAngle1 < lastAngle1)
      {
        for(int a=lastAngle1; a >= choixAngle1; a--)
        {
          S1.write(a);
          delay(vitesse);
        }
      }
      if(choixAngle1 > lastAngle1)
      {
        for(int a=lastAngle1; a <= choixAngle1; a++)
        {
          S1.write(a);
          delay(vitesse);
        }
      }
      lastAngle1 = choixAngle1;
    }
  
    else if(choixServo == '2')
    {
      Serial.print("Servo 2 ");
      choixAngle2 = constrain(choixAngle2,0,180);
      Serial.println("Angle:");
      Serial.println(choixAngle2);
      if(choixAngle2 < lastAngle2)
      {
        for(int a=lastAngle2; a >= choixAngle2; a--)
        {
          S2.write(a);
          delay(vitesse);
        }
      }
      if(choixAngle2 > lastAngle2)
      {
        for(int a=lastAngle2; a <= choixAngle2; a++)
        {
          S2.write(a);
          delay(vitesse);
        }
      }
      lastAngle2 = choixAngle2;
    }
    else if(choixServo == '3')
    {
      Serial.print("Servo 3 ");
      choixAngle3 = constrain(choixAngle3,0,180);
      Serial.println("Angle:");
      Serial.println(choixAngle3);
      if(choixAngle3 < lastAngle3)
      {
        for(int a=lastAngle3; a >= choixAngle3; a--)
        {
          S3.write(a);
          delay(vitesse);
        }
      }
      if(choixAngle3 > lastAngle3)
      {
        for(int a=lastAngle3; a <= choixAngle3; a++)
        {
          S3.write(a);
          delay(vitesse);
        }
      }
      lastAngle3 = choixAngle3;
      }
//  Serial.println("Servo 1:");
//  while(Serial.available() == 1);
//  angleS1 = Serial.read()  - '0';
//  S1.write(angleS1);
//  Serial.flush();
//  delay(1000);
//  
// Serial.println("Servo 2:");
//  while(Serial.available() == 1);
//  angleS2 = Serial.read() - '0';
//  S2.write(angleS2);
//  Serial.flush();
//  delay(1000);
//  
// Serial.println("Servo 3:");
//  while(Serial.available() == 1);
//  angleS3 = Serial.read()  - '0';
//  S3.write(angleS3);
//  Serial.flush();
//  delay(1000);

}
