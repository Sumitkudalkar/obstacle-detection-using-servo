#include <Servo.h>
const int trig = 9;
const int echo = 10;
const int buzzer = 6;
Servo myservo;
void setup() {
  Serial.begin(115200);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzzer, OUTPUT);

  myservo.attach(11);
  // put your setup code here, to run once:

}
float nextpos;
float fakeDist(int angle)
{
  switch (angle)
  {
    case 0:
      return 38.2;

    case 45:
      return 43.65;

    case 90:
      return 74.84;

    case 135:
      return 22.24;

    case 180:
      return 10.45;
    default:
      {
        return 0;
      }
  }

}
void loop() {
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  long time = pulseIn(echo, HIGH);
  float distance =  (time * 0.0343) / 2;
  float bestDist = 0, bestAngle = 0;
  if (distance < 70)
  {
    tone(buzzer, 200);
    delay(200);
    noTone(buzzer);
    for (int pos = 0; pos <= 180; pos = pos + 45)
    {
      myservo.write(pos);
      delay(500);
      float dist = fakeDist(pos);
      if (dist > bestDist)
      {
        bestDist = dist;
        bestAngle = pos;
      }

    }
    for (int i = 0; i < (bestAngle + 44) / 45; i++)
    {
      tone(buzzer, 255);
      delay(500);
      noTone(buzzer);
      delay(500);
    }
  }
  delay(500);



  // put your main code here, to run repeatedly:

}
