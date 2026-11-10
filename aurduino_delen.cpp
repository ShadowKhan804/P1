// C++ code
//
int sensorValue = 0;
int t = 0;
int green = 2;
int yellow = 4;
int red = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{ 
  sensorValue = analogRead(A0);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  // max water sensor value is 876 for some reason
  if(sensorValue > 438){
    if(t < 10){
      digitalWrite(green, HIGH);
    }else if (t < 20){
      digitalWrite(yellow, HIGH);
    }else{
      digitalWrite(red, HIGH);
    }
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay(500);

    Serial.print("Time: ");
      Serial.println(t);
      t++;
  }else{
      delay(1000); // Wait for 1000 millisecond(s)*/
    t = 0;
  }
}
