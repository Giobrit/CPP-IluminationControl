#include "Arduino.h"
#include "PresenceSensor.h"

// Most Arduino boards already have a LED attached to pin 13 on the board itself
//#define LED_PIN 13
int outpoutPresenceSensor = A3;

PresenceSensor PresenceSensor(outpoutPresenceSensor);

void setup() {
  Serial.begin(9600);

  PresenceSensor.registerButton(new Button(A0, automatic));
  PresenceSensor.registerButton(new Button(A1));
  PresenceSensor.registerButton(new Button(A2));
}

void loop() {
  PresenceSensor.run();
  delay(100);
}
