#define TRIG 9 
#define ECHO 8 

void setup() {

  Serial.begin(9600); //PC모니터로 센서값을 확인하기위해서 시리얼 통신을 정의해줍니다. 

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{

  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn (ECHO, HIGH); 

  distance = duration * 17 / 1000; 

  Serial.println(duration );
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  delay(1000);
}