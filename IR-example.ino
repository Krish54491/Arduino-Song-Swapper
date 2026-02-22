#include <IRremote.h>

const int IRsensor = 7;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRsensor, ENABLE_LED_FEEDBACK);
  Serial.println("IR ready");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Protocol: ");
    Serial.println(IrReceiver.decodedIRData.protocol);

    Serial.print("Command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    Serial.print("Address: 0x");
    Serial.println(IrReceiver.decodedIRData.address, HEX);

    Serial.println("----");
    IrReceiver.resume();
  }
}