
int resval = 0;
int respin = A5;

void setup() {
  Serial.begin(9600);

}

void loop() {
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
