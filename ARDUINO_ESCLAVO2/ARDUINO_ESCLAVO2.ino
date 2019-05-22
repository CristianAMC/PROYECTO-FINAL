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
}

void loop() {

}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number){
  while(Wire.available() > 0){
    switch(number){
      case 49:{
        if(digitalRead(0)){
          digitalWrite(0,LOW);
          }
        else{
          digitalWrite(0,HIGH);
          }
       break;
      }
      case 50:{
        if(digitalRead(1)){
          digitalWrite(1, LOW);
          }
        else {
          digitalWrite(1,HIGH);
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
