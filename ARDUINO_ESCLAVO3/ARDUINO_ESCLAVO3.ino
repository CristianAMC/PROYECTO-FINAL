#include <Wire.h>
#define address 32
int VALOR;
int LED1,LED2;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  //Wire.onReceive(receiver); 
  Wire.onRequest(sender);
  pinMode(0,INPUT);
  pinMode(1,INPUT); 
}

void loop() {

}

void sender(){
    VALOR= analogRead (A0);
    Wire.write(VALOR);
    LED1 = digitalRead (0);
    Wire.write(LED1);
    LED2 = digitalRead (1);
    Wire.write(LED2);
    
}
