// Initialize the pins
const int trigPin = 11;
const int echoPin = 10;
const int in1 = 9;
const int in2 = 8;
const int in3 = 7;
const int in4 = 6;
long duration, distance; 

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // distance = time*velocity
  // Velocity of sound = 343meter/sec. 
  // time = duration / 2 (microsecond) bcz sound wave first go from trigpin and then come out in echo pin.
  // distance = duration/2 (ms) * velocity (343 m/s)
  // distance = duration/2 (ms) * (343 * 100cm/10^6 ms)
  // distance = duration/2 (ms) * (343 cm/ 10^4 ms)
  // distance = duration/58.3090379 cm
  
  distance = duration/58.31;

  if(distance<30)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(0);  
  }
  
}
