#include <Wire.h>
#define address 31
int VALOR;
int LED1,LED2;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver); 
  Wire.onRequest(sender);
  pinMode(0,INPUT);
  pinMode(1,INPUT); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {

}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number){
  while(Wire.available() > 0){
    switch(number){
      case 49:{
        if(digitalRead(2)){
          digitalWrite(2,LOW);
          }
        else{
          digitalWrite(2,HIGH);
          }
       break;
      }
      case 50:{
        if(digitalRead(3)){
          digitalWrite(3, LOW);
          }
        else {
          digitalWrite(3,HIGH);
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

//ENTRADA DIGITAL Y ANALOGA------------------------------------
void sender(){
    VALOR= analogRead (A0);
    Wire.write(VALOR);
    LED1 = digitalRead (0);
    Wire.write(LED1);
    LED2 = digitalRead (1);
    Wire.write(LED2);
//-------------------------------------------------------------     
}
