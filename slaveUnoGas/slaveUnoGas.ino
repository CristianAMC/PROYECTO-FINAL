#include <Wire.h>
#define address 30
int gas;

void setup() {
  Wire.setClock(400000);
  Wire.begin(address);
  Wire.onReceive(receiver);
  Wire.onRequest(sender);
  pinMode(5, OUTPUT);
}

void loop() {

}

//SALIDA DIGITAL---------------------------------------------
void receiver(int number) {
  while (Wire.available() > 0) {
    char x= Wire.read();
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
  gas=analogRead(0);
  Wire.write(gas);
  //--------------------------------------------------------------
}
