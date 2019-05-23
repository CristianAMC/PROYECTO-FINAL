#include <Wire.h>
#define address 31
int pot;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver);
  Wire.onRequest(sender);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {

}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number) {
  char c=Wire.read();
}
//-------------------------------------------------------------

//ENTRADA DIGITAL----------------------------------------------
void sender() {
  pot=analogRead(0);
  Wire.write(pot);
  //--------------------------------------------------------------
}
