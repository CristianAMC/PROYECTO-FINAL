#include <Wire.h>
#define address 32

bool state=false;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver);
  Wire.onRequest(sender);
  pinMode(0,INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  state=digitalRead(0);
  delay(5000);
}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number) {
  while (Wire.available() > 0) {
    char x= Wire.read();
    if (x >= '4' && x <= '9'){
      int velocidad = map(x,'9','4',0,255);
      analogWrite(3,velocidad);
     }
    switch (x) {
      case '1': {
          if (digitalRead(5)) {
            digitalWrite(5, LOW);
          }
          else {
            digitalWrite(5, HIGH);
          }
          break;
        }
      case '2': {
          if (digitalRead(6)) {
            digitalWrite(6, LOW);
          }
          else {
            digitalWrite(6, HIGH);
          }
          break;
        }
      case '3': {
          if (digitalRead(7)) {
            digitalWrite(7, LOW);
          }
          else {
            digitalWrite(7, HIGH);
          }
          break;
        }
      default: {
        setup();
          break;
        }
    }
  }
}
//-------------------------------------------------------------

//ENTRADA DIGITAL----------------------------------------------
void sender() {
  if(state==true){
  Wire.write(0x1);
  }
  else{
    Wire.write(0x2);
   }
}
