
int LED1 = 12;
int LED2 = 11;
int buzzer = 10;
int smoke = A5;
int bulb = 2;
int fan = 3;
int smokeThreshold = 500;
int inputPir = 9;
int baselineTemp = 0;
int celsius = 0;
int val = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
  pinMode(inputPir, INPUT);
  pinMode(bulb, OUTPUT);
  pinMode(fan, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smoke);
  
  val = digitalRead(inputPir);
  
  baselineTemp = 40;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print(" TEMP: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  
  if (celsius < 25) {
    digitalWrite(fan, LOW);
  }
  if (celsius > 25) {
    digitalWrite(fan, HIGH);
  }
  Serial.print("Co2: ");
  Serial.print(analogSensor);
 
  if (analogSensor > smokeThreshold)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    tone(buzzer, 1000, 350);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    noTone(buzzer);
  }
  delay(100);
  Serial.print(", PIR: ");
  Serial.println(val);
  if(val == HIGH)
    {
      digitalWrite(bulb, HIGH);
      delay(2000);
  	}
  else
  	{
      digitalWrite(bulb, LOW);
      delay(300);
  	}
}