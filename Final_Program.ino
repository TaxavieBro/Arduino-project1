#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2);
int analogPin = A0;
int moisture;
int percentage;

int map_low = 686;
int map_high = 300;
int sensor = 8;
int val;

int resval = 0;
int respin = A5;

void setup()
{
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  LCD.begin(16,2);
  pinMode (13, OUTPUT);
 pinMode (8, INPUT);
  
 }
 void loop()
 {
   val = digitalRead(8);
  if (val == LOW)
  {
    digitalWrite(13, LOW);
    }
  else
 {
  digitalWrite(13, HIGH);
 }
  int SensorValue= analogRead(A0);
  moisture = analogRead(analogPin);
  Serial.print("RAW:");
  Serial.print(moisture);

  percentage = map(moisture, map_low, map_high, 0, 100);
    Serial.print("| Percentage: ");
    Serial.print(percentage);
  Serial.println("%");
;
  if(SensorValue >= 1000)
  {
    Serial.println("NOT IN SOIL");
    LCD.setCursor(0,0);
    LCD.print("      ");
  }
  if(SensorValue < 1000 && SensorValue >= 600)
  {
    Serial.println("SOIL: DRY");
    LCD.setCursor(0,0);
    LCD.print("SOIL: DRY");
    LCD.print("       "); 
  }
  if(SensorValue < 600 && SensorValue >= 370)
  {
    Serial.println("SOIL: HUMID");
    LCD.setCursor(0,0);
    LCD.print("SOIL: HUMID");
    LCD.print("       "); 
  }
  if(SensorValue < 370)
  {
    Serial.println("SOIL: SOGGY");
    LCD.setCursor(0,0);
    LCD.print("SOIL: SOGGY");
    LCD.print("       ");
  }
    LCD.setCursor(0,1);
    LCD.print("       ");
    LCD.setCursor(0,1);
    LCD.print(SensorValue);
    delay(1000);

    resval = analogRead(respin);

    if (resval <= 100){
      Serial.println("WATER LEVEL : EMPTY");
    }
    else if (resval > 100 && resval <= 300 ){
        Serial.println("WATER LEVEL : LOW");
    }
     else if (resval > 300 && resval <= 330 ){
        Serial.println("WATER LEVEL : MEDIUM");
}
     else if (resval > 330){
        Serial.println("WATER LEVEL : HIGH");
     }
     delay(1000);
}
