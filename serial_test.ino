void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("gugudan");
  for(int i=1; i<=9; i++)
   
  {
    for (int j = 1 ; j<= 9 ; j++)
    {
      Serial.print(i);
    Serial.print(" X ");
    Serial.print(j);
    Serial.print(" = ");
    Serial.println(i*j);
    }
  }
}

