#include <IRremote.h>

const byte recv_pin=6;

IRrecv receiver(recv_pin);

void setup() {

  Serial.begin(9600);

  receiver.enableIRIn();

  receiver.blink13(true);

}

void loop() {

  if(receiver.decode()){
    int response=receiver.decodedIRData.command;
    Serial.println(response);
    
    receiver.resume();
  }
  
}