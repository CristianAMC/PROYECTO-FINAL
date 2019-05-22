#include <Wire.h>
#define address 30

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver); 
}

void loop() {
}

void receiver(int number){
  while(Wire.available() > 0){
    }
}
