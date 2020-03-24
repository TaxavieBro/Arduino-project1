#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2);

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  LCD.begin(16,2);
  
 }
 void loop()
 {
  int SensorValue= analogRead(A0);
  Serial.print(SensorValue);
  Serial.print("-");
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
 }
