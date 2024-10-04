int buzzer = 13;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 800;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}
void loop() {
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);// high
  }
  else
  {
    noTone(buzzer); //low
  }
  delay(100);
}
