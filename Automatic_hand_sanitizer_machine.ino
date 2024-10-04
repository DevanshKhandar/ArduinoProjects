int pirSensor =2;
int pinLed =12;
int pinBuzzer =13;

void setup()
{
  pinMode(pirSensor, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}
void loop()
{
 int irsensor = digitalRead(pirSensor);
  if (irsensor == LOW)
  {
    digitalWrite(pinLed, HIGH);
   digitalWrite (pinBuzzer, HIGH);
  }
    else {
    digitalWrite(pinLed, LOW);
digitalWrite (pinBuzzer, LOW);
  }
  delay(10);
}
