int trigPin = 12;
int echoPin = 11;
int led = 10;

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 400 || distance <= 2)
  {
    Serial.println("Out of range");
    digitalWrite(led,LOW);
  }
  else if(distance <= 20)
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(led,HIGH);
    
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(led, LOW);
  }
  delay(500);
}
