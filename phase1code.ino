#include <Servo.h>
Servo myservo;
const int trig = 9;
const int echo = 10;
const int buzz = 11;
int pos = 0, nextpos;
void setup() {
  Serial.begin(115200);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
  myservo.attach(6);
  // put your setup code here, to run once:

}
float measureDist()
{
  myservo.detach();
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  long time = pulseIn(echo, HIGH);
  myservo.attach(6);
  return (time * 0.0343) / 2;
}

void loop() {

  float distance = measureDist();
  float maxdist = distance;

  if (distance < 70)
  {
    nextpos = 0;
    int intensity = map(distance, 0, 402, 255, 0);
    tone(buzz, intensity);
    delay(500);
    noTone(buzz);
    for (pos = 0; pos <= 180; pos = pos + 45)
    {
      myservo.write(pos);
      delay(500);
      float instantdist = measureDist();
      if (instantdist > maxdist + 3)
      {
        maxdist = instantdist;
        nextpos = pos;
      }
      delay(1000);
    }
    if (nextpos == 0)
    {
      Serial.println("stop");
    }
    else if (nextpos == 45)
    {
      Serial.println("forward right");
    }
    else if (nextpos == 90)
    {
      Serial.println("right");
    }
    else if (nextpos == 135)
    {
      Serial.println("forward left");
    }
    else {
      Serial.println("left");
    }
  }
  else {
    noTone(buzz);
  }

  // put your main code here, to run repeatedly:

}
