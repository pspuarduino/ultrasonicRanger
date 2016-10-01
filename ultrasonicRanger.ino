#include "Ultrasonic.h" // подключаем дополнительную библиотеку для работы с датчиком расстояния

int pins[3] = {5,6,7}; // ножки светодиодов

Ultrasonic ultrasonic(12, 13); 
// 12 - Trig 
// 13 - Echo

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 3; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM);
  Serial.println(dist_cm);
  
  if(dist_cm > 200){
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], LOW);
    digitalWrite(pins[2], LOW);
  }else if (dist_cm > 100){
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[2], LOW);
  }else{
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], LOW);
    digitalWrite(pins[2], HIGH);
  }
  
  delay(100);
}
