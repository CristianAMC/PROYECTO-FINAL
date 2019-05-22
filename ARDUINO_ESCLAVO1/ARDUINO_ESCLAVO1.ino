#include <Wire.h>
#define address 30
int VALOR;
int LED1,LED2,LED3,LED4,LED5;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver); 
  Wire.onRequest(sender);
  pinMode(0,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
}

void loop() {

}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number){
  while(Wire.available() > 0){
    switch(number){
      case 49:{
        if(digitalRead(5)){
          digitalWrite(5,LOW);
          }
        else{
          digitalWrite(5,HIGH);
          }
       break;
      }
      case 50:{
        if(digitalRead(6)){
          digitalWrite(6, LOW);
          }
        else {
          digitalWrite(6,HIGH);
          }
        break;
          }
      case 51:{
        if(digitalRead(7)){
          digitalWrite(7, LOW);
          }
        else {
          digitalWrite(7,HIGH);
          }
        break;
          }
      default:{
        break;
      }
    }
  }
}
//-------------------------------------------------------------

//ENTRADA DIGITAL----------------------------------------------
void sender(){
    LED1 = digitalRead (0);
    Wire.write(LED1);
    LED2 = digitalRead (1);
    Wire.write(LED2);
    LED3 = digitalRead (2);
    Wire.write(LED3);
    LED4 = digitalRead (3);
    Wire.write(LED4);
    LED5 = digitalRead (4);
    Wire.write(LED5);
//--------------------------------------------------------------     
}
